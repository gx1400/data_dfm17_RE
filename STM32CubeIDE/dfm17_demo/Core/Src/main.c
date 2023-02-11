/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "radioPatch.h"
#include "led.h"
#include "stdio.h"
#include "stdarg.h"
#include "radio_config_Si4063.h"

#define PATCHLEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ERR_CTSFAIL 		8000
#define ERR_SPIRECEIVE		8100

#define radioCmd_REQUEST_DEVICE_STATE 	0x33
#define radioCmd_READ_CMD_BUFF			0x44
#define radioCmd_FILLER					0xFF
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

uint32_t usbLastms			= 0;


uint16_t usbIntervalMs		= 2000;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM1_Init(void);

int _write(int file, char *ptr, int len) {
	int i=0;
	for(i=0; i<len; i++){
		ITM_SendChar((*ptr++));
	}
	return len;
}
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  debug_msg("Starting stm...\r\n");

  /* USER CODE BEGIN Init */


  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  debug_msg("Starting timer.\r\n");
  HAL_TIM_Base_Start(&htim1); //start timer 1

  debug_msg("Setting BattPON.\r\n");
  assertBattPOn();

  //radio boot
  int resultSetup = 0;
  debug_msg("Start booting radio...\r\n");
  resultSetup = bootRadio();

  if (!resultSetup) {
	  HAL_GPIO_WritePin(oLED_G_GPIO_Port, oLED_G_Pin, GPIO_PIN_SET);
  } else {
	  HAL_GPIO_WritePin(oLED_R_GPIO_Port, oLED_R_Pin, GPIO_PIN_SET);
  }



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  debug_msg("Starting main loop...");
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  ledInterval(oLED_R_GPIO_Port, oLED_R_Pin, oLED_Y_GPIO_Port, oLED_Y_Pin);
	  //usbInterval();
	  //testToggleLED(oLED_Y_GPIO_Port, oLED_Y_Pin);



  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 16-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0xffff-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, oBattPOn_Pin|oLED_G_Pin|oLED_Y_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(oSiSDN_GPIO_Port, oSiSDN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(oSpiCS_GPIO_Port, oSpiCS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(oLED_R_GPIO_Port, oLED_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : oBattPOn_Pin oLED_G_Pin oLED_Y_Pin */
  GPIO_InitStruct.Pin = oBattPOn_Pin|oLED_G_Pin|oLED_Y_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : oSiSDN_Pin */
  GPIO_InitStruct.Pin = oSiSDN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(oSiSDN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : oSpiCS_Pin */
  GPIO_InitStruct.Pin = oSpiCS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(oSpiCS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : oLED_R_Pin */
  GPIO_InitStruct.Pin = oLED_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(oLED_R_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : intButton_Pin */
  GPIO_InitStruct.Pin = intButton_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(intButton_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == intButton_Pin) // INT Source is pin A9
    {
    	GPIO_PinState sButton = HAL_GPIO_ReadPin(intButton_GPIO_Port, intButton_Pin);
    	HAL_GPIO_WritePin(oLED_Y_GPIO_Port, oLED_Y_Pin, sButton); // Toggle LED
    }
}

void delay_us(uint16_t us) {
	__HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // wait for the counter to reach the us input in the parameter
}

void debug_msg(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
}

int radioWaitForCTS(void) {
	HAL_StatusTypeDef hal_status;
	uint8_t tx_data[2];
	uint8_t rx_data[2];


	tx_data[0] = radioCmd_READ_CMD_BUFF;
	tx_data[1] = radioCmd_FILLER;

	debug_msg("      ...Wait for CTS:\r\n");
	for(int x = 0; x <= 100; x++ ) {
		uint8_t resp;
		resp = 0xF0;
		assertRadioCS();
		hal_status = HAL_SPI_TransmitReceive(&hspi1, tx_data, rx_data, 2, HAL_MAX_DELAY);
		deassertRadioCS();

		if(hal_status == HAL_OK) {
			resp = rx_data[1];

			if (resp == 0xFF) {
				debug_msg("      ...Found CTS at msg#%d\r\n", x);

				return 0;
			}
		}
		delay_us(25);
	}

	debug_msg("     ...ERROR: CTS not found\r\n");
	return ERR_CTSFAIL;
}

int bootRadio(void) {
	resetRadio();
	delay_us(50);

	int result = 0;

	// wait for CTS to allow to boot
	result = radioWaitForCTS();
	if (result) {return result;}


	sendPatchCmds();

	uint8_t cmdRF_POWER_UP[] = {RF_POWER_UP};
	uint8_t cmdRF_GPIO_PIN_CFG[] = {RF_GPIO_PIN_CFG};
	uint8_t cmdRF_GLOBAL_XO_TUNE_2[] = {RF_GLOBAL_XO_TUNE_2};
	uint8_t cmdRF_GLOBAL_CONFIG_1[] = {RF_GLOBAL_CONFIG_1};
	uint8_t cmdRF_INT_CTL_ENABLE_1[] = {RF_INT_CTL_ENABLE_1};
	uint8_t cmdRF_FRR_CTL_A_MODE_4[] = {RF_FRR_CTL_A_MODE_4};
	uint8_t cmdRF_PREAMBLE_CONFIG_1[] = {RF_PREAMBLE_CONFIG_1};
	uint8_t cmdRF_MODEM_MOD_TYPE_12[] = {RF_MODEM_MOD_TYPE_12};
	uint8_t cmdRF_MODEM_FREQ_DEV_0_1[] = {RF_MODEM_FREQ_DEV_0_1};
	uint8_t cmdRF_MODEM_TX_RAMP_DELAY_12[] = {RF_MODEM_TX_RAMP_DELAY_12};
	uint8_t cmdRF_MODEM_BCR_NCO_OFFSET_2_12[] = {RF_MODEM_BCR_NCO_OFFSET_2_12};
	uint8_t cmdRF_MODEM_AFC_LIMITER_1_3[] = {RF_MODEM_AFC_LIMITER_1_3};
	uint8_t cmdRF_MODEM_AGC_CONTROL_1[] = {RF_MODEM_AGC_CONTROL_1};
	uint8_t cmdRF_MODEM_AGC_WINDOW_SIZE_12[] = {RF_MODEM_AGC_WINDOW_SIZE_12};
	uint8_t cmdRF_MODEM_RAW_CONTROL_3[] = {RF_MODEM_RAW_CONTROL_3};
	uint8_t cmdRF_MODEM_RAW_SEARCH2_2[] = {RF_MODEM_RAW_SEARCH2_2};
	uint8_t cmdRF_MODEM_SPIKE_DET_1[] = {RF_MODEM_SPIKE_DET_1};
	uint8_t cmdRF_PA_MODE_4[] = {RF_PA_MODE_4};
	uint8_t cmdRF_SYNTH_PFDCP_CPFF_7[] = {RF_SYNTH_PFDCP_CPFF_7};
	uint8_t cmdRF_FREQ_CONTROL_INTE_7[] = {RF_FREQ_CONTROL_INTE_7};



	debug_msg("Send cmdRF_POWER_UP...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_POWER_UP), cmdRF_POWER_UP);

	debug_msg("Send cmdRF_GPIO_PIN_CFG...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_GPIO_PIN_CFG), cmdRF_GPIO_PIN_CFG);

	debug_msg("Send cmdRF_GLOBAL_XO_TUNE_2...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_GLOBAL_XO_TUNE_2), cmdRF_GLOBAL_XO_TUNE_2);

	debug_msg("Send cmdRF_GLOBAL_CONFIG_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_GLOBAL_CONFIG_1), cmdRF_GLOBAL_CONFIG_1);

	debug_msg("Send cmdRF_GLOBAL_CONFIG_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_GLOBAL_CONFIG_1), cmdRF_GLOBAL_CONFIG_1);

	debug_msg("Send cmdRF_INT_CTL_ENABLE_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_INT_CTL_ENABLE_1), cmdRF_INT_CTL_ENABLE_1);

	debug_msg("Send cmdRF_FRR_CTL_A_MODE_4...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_FRR_CTL_A_MODE_4), cmdRF_FRR_CTL_A_MODE_4);

	debug_msg("Send cmdRF_PREAMBLE_CONFIG_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_PREAMBLE_CONFIG_1), cmdRF_PREAMBLE_CONFIG_1);

	debug_msg("Send cmdRF_MODEM_MOD_TYPE_12...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_MOD_TYPE_12), cmdRF_MODEM_MOD_TYPE_12);

	debug_msg("Send cmdRF_MODEM_FREQ_DEV_0_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_FREQ_DEV_0_1), cmdRF_MODEM_FREQ_DEV_0_1);

	debug_msg("Send cmdRF_MODEM_TX_RAMP_DELAY_12...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_TX_RAMP_DELAY_12), cmdRF_MODEM_TX_RAMP_DELAY_12);

	debug_msg("Send cmdRF_MODEM_BCR_NCO_OFFSET_2_12...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_BCR_NCO_OFFSET_2_12), cmdRF_MODEM_BCR_NCO_OFFSET_2_12);

	debug_msg("Send cmdRF_MODEM_AFC_LIMITER_1_3...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_AFC_LIMITER_1_3), cmdRF_MODEM_AFC_LIMITER_1_3);

	debug_msg("Send cmdRF_MODEM_AGC_CONTROL_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_AGC_CONTROL_1), cmdRF_MODEM_AGC_CONTROL_1);

	debug_msg("Send cmdRF_MODEM_AGC_WINDOW_SIZE_12...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_AGC_WINDOW_SIZE_12), cmdRF_MODEM_AGC_WINDOW_SIZE_12);

	debug_msg("Send cmdRF_MODEM_RAW_CONTROL_3...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_RAW_CONTROL_3), cmdRF_MODEM_RAW_CONTROL_3);

	debug_msg("Send cmdRF_MODEM_RAW_SEARCH2_2...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_RAW_SEARCH2_2), cmdRF_MODEM_RAW_SEARCH2_2);

	debug_msg("Send cmdRF_MODEM_SPIKE_DET_1...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_MODEM_SPIKE_DET_1), cmdRF_MODEM_SPIKE_DET_1);

	debug_msg("Send cmdRF_PA_MODE_4...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_PA_MODE_4), cmdRF_PA_MODE_4);

	debug_msg("Send cmdRF_SYNTH_PFDCP_CPFF_7...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_SYNTH_PFDCP_CPFF_7), cmdRF_SYNTH_PFDCP_CPFF_7);

	debug_msg("Send cmdRF_FREQ_CONTROL_INTE_7...\r\n");
	radio_comm_SendCmd(sizeof(cmdRF_FREQ_CONTROL_INTE_7), cmdRF_FREQ_CONTROL_INTE_7);



	return 0;
}

int sendPatchCmds(void) {
	debug_msg("   ...Starting patch decode\r\n");
	uint8_t Si446xPatchCommands[][9] = { SI446X_PATCH_CMDS };
	uint8_t SingleCmd[8] = {0};

	uint8_t cmdCount = 0;
	cmdCount = PATCHLEN(Si446xPatchCommands);
	debug_msg("      ...Found %d patch commands\r\n", cmdCount);

	volatile uint16_t line = 0;
	volatile uint8_t row = 0;

	for (line = 0; line < cmdCount; line++) {
		memset(SingleCmd, 0, sizeof(SingleCmd));
		for (row=1; row<9; row++) {
			SingleCmd[row-1] = Si446xPatchCommands[line][row];
		}
		debug_msg("      ...Sending patch command %d\r\n", line);
		radio_comm_SendCmd(sizeof(SingleCmd), SingleCmd);
	}


	debug_msg("      ...Done Sending Patch Commands\r\n");
	return 0;
}

//uint8_t radio_comm_SendCmd(uint8_t cmdByteCount, uint8_t* pCmdData, uint8_t respByteCount, uint8_t* pRespData)
//{
//    radio_comm_SendCmd(cmdByteCount, pCmdData);
//    return 0;
//    //return radio_comm_GetResp(respByteCount, pRespData);
//}

void radio_comm_SendCmd(uint8_t byteCount, uint8_t* pData) {
	debug_msg("   ...Start Command\r\n");
	radioWaitForCTS();

	debug_msg("      ...Start Command Send\r\n");
	assertRadioCS();
	HAL_SPI_Transmit(&hspi1, pData, byteCount, HAL_MAX_DELAY);
	deassertRadioCS();
	debug_msg("      ...Command Send Done\r\n");


}

void radio_comm_SendCmdNoCTS(uint8_t byteCount, uint8_t* pData) {
	debug_msg("   ...Start Command w/o CTS\r\n");

	debug_msg("      ...Start Command Send\r\n");
	assertRadioCS();
	HAL_SPI_Transmit(&hspi1, pData, byteCount, HAL_MAX_DELAY);
	deassertRadioCS();
	debug_msg("      ...Command Send Done\r\n");


}

int radio_comm_GetResp(uint8_t respByteCount, uint8_t* pRespData) {
	HAL_StatusTypeDef hal_status;

	assertRadioCS();
	hal_status = HAL_SPI_Receive(&hspi1, pRespData, respByteCount, HAL_MAX_DELAY);
	deassertRadioCS();

	if (hal_status == HAL_OK) {
		return 0;
	} else {
		return ERR_SPIRECEIVE;
	}

}



void resetRadio(void) {
	assertRadioShutdown();
	delay_us(30);
	deassertRadioShutdown();
}

void assertRadioShutdown(void) {
	HAL_GPIO_WritePin(oSiSDN_GPIO_Port, oSiSDN_Pin, GPIO_PIN_SET);
}

void deassertRadioShutdown(void) {
	HAL_GPIO_WritePin(oSiSDN_GPIO_Port, oSiSDN_Pin, GPIO_PIN_RESET);
}

void assertRadioCS(void) {
	HAL_GPIO_WritePin(oSpiCS_GPIO_Port, oSpiCS_Pin, GPIO_PIN_RESET);
}

void deassertRadioCS(void) {
	HAL_GPIO_WritePin(oSpiCS_GPIO_Port, oSpiCS_Pin, GPIO_PIN_SET);
}

void assertBattPOn(void) {
	HAL_GPIO_WritePin(oBattPOn_GPIO_Port, oBattPOn_Pin, GPIO_PIN_SET);
}



void usbInterval(void) {
	uint32_t currentms = HAL_GetTick();

	if ((currentms - usbLastms) >= usbIntervalMs) {
		usbLastms = currentms;

		usbPrintln("hello world");
	}
}

void usbPrintln(char _out[]){
	HAL_UART_Transmit(&huart1, (uint8_t *) _out, strlen(_out), 10);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(&huart1, (uint8_t *) newline, 2, 10);
}

void usbPrint(char _out[]){
	HAL_UART_Transmit(&huart1, (uint8_t *) _out, strlen(_out), 10);
}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
