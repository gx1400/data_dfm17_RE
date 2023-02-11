/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void assertBattPOn(void);
void usbInterval(void);
void usbPrintln(char _out[]);
void usbPrint(char _out[]);
void delay_us(uint16_t us);

int radioWaitForCTS(void);
int bootRadio(void);
void resetRadio(void);
int sendPatchCmds(void);
void assertRadioShutdown(void);
void deassertRadioShutdown(void);
void assertRadioCS(void);
void deassertRadioCS(void);
//uint8_t radio_comm_SendCmdGetResp(uint8_t cmdByteCount, uint8_t* pCmdData, uint8_t respByteCount, uint8_t* pRespData);
void radio_comm_SendCmd(uint8_t byteCount, uint8_t* pData);
void radio_comm_SendCmdNoCTS(uint8_t byteCount, uint8_t* pData);
int radio_comm_GetResp(uint8_t respByteCount, uint8_t* pRespData);
void radioToggleToneGPIO(uint16_t delay);

void debug_msg(const char *fmt, ...);


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define iSpiGPIO2_Pin GPIO_PIN_0
#define iSpiGPIO2_GPIO_Port GPIOD
#define oBattPOn_Pin GPIO_PIN_0
#define oBattPOn_GPIO_Port GPIOC
#define oSiSDN_Pin GPIO_PIN_3
#define oSiSDN_GPIO_Port GPIOC
#define oSpiGPIO3_Pin GPIO_PIN_4
#define oSpiGPIO3_GPIO_Port GPIOA
#define oSpiSCLK_Pin GPIO_PIN_5
#define oSpiSCLK_GPIO_Port GPIOA
#define oSpiMISO_Pin GPIO_PIN_6
#define oSpiMISO_GPIO_Port GPIOA
#define oSpiMOSI_Pin GPIO_PIN_7
#define oSpiMOSI_GPIO_Port GPIOA
#define oSpiCS_Pin GPIO_PIN_2
#define oSpiCS_GPIO_Port GPIOB
#define oLED_R_Pin GPIO_PIN_12
#define oLED_R_GPIO_Port GPIOB
#define oLED_G_Pin GPIO_PIN_6
#define oLED_G_GPIO_Port GPIOC
#define oLED_Y_Pin GPIO_PIN_7
#define oLED_Y_GPIO_Port GPIOC
#define intButton_Pin GPIO_PIN_8
#define intButton_GPIO_Port GPIOC
#define intButton_EXTI_IRQn EXTI9_5_IRQn
#define usbTX_Pin GPIO_PIN_9
#define usbTX_GPIO_Port GPIOA
#define usbRX_Pin GPIO_PIN_10
#define usbRX_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
