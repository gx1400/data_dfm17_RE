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

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ERR_CTSFAIL 8000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint32_t greenLastms 		= 0;
uint32_t redLastms 			= 0;
uint32_t yellowLastms 		= 0;
uint32_t usbLastms			= 0;

uint16_t greenIntervalMs	= 500;
uint16_t redIntervalMs		= 1000;
uint16_t yellowIntervalMs	= 2000;
uint16_t usbIntervalMs		= 2000;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM1_Init(void);
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
  HAL_TIM_Base_Start(&htim1); //start timer 1
  assertBattPOn();

  //radio boot
  int resultSetup = 0;
  resultSetup = bootRadio();

  if (!resultSetup) {
	  HAL_GPIO_WritePin(oLED_G_GPIO_Port, oLED_G_Pin, GPIO_PIN_SET);
  } else {
	  HAL_GPIO_WritePin(oLED_R_GPIO_Port, oLED_R_Pin, GPIO_PIN_SET);
  }



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  //ledInterval();
	  //usbInterval();
	  //testToggleLED();

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

void testToggleLED(void) {
	HAL_GPIO_WritePin(oLED_G_GPIO_Port, oLED_G_Pin, GPIO_PIN_SET);
	delay_us(100);
	HAL_GPIO_WritePin(oLED_G_GPIO_Port, oLED_G_Pin, GPIO_PIN_RESET);
	delay_us(200);

}

int radioWaitForCTS(void) {
	HAL_StatusTypeDef hal_status;
	uint8_t tx_data[2];
	uint8_t rx_data[2];


	tx_data[0] = 0x44;
	tx_data[1] = 0xFF;

	for(int x = 0; x <= 100; x++ ) {
		uint8_t resp;
		resp = 0xF0;
		assertRadioCS();
		hal_status = HAL_SPI_TransmitReceive(&hspi1, tx_data, rx_data, 2, HAL_MAX_DELAY);
		deassertRadioCS();

		if(hal_status == HAL_OK) {
			resp = rx_data[1];

			if (resp == 0xFF) {
				return 0;
			}
		}
		delay_us(25);
	}

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
	return 0;
}

int ErrSetupCTS(void) {

	return ERR_CTSFAIL;
}

int sendPatchCmds(void) {
	uint8_t Si446xPatchCommands[][8] = { SI446X_PATCH_CMDS };
	uint8_t SingleCmd[16];

	volatile uint16_t line = 0;
	volatile uint8_t row = 0;
	for (line = 0; line < (sizeof(Si446xPatchCommands) / 8u); line++) {
		for (row=0; row<8; row++) {
			SingleCmd[row] = Si446xPatchCommands[line][row];
		}
		xmitCmdRadio(SingleCmd);
		return 0; // TEMP send only one command
	}
	return 0;
}

int xmitCmdRadio(uint8_t cmd[]){

	return 0;
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

void ledInterval(void) {
	uint32_t currentms = HAL_GetTick();


	if( (currentms - greenLastms) >= greenIntervalMs) {
			greenLastms = currentms;
			HAL_GPIO_TogglePin(oLED_G_GPIO_Port, oLED_G_Pin);
	}

	if( (currentms - redLastms) >= redIntervalMs) {
			redLastms = currentms;
			HAL_GPIO_TogglePin(oLED_R_GPIO_Port, oLED_R_Pin);
	}
	/*
	if( (currentms - yellowLastms) >= yellowIntervalMs) {
			yellowLastms = currentms;
			HAL_GPIO_TogglePin(oLED_Y_GPIO_Port, oLED_Y_Pin);
	}
	*/
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
