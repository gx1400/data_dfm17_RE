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
#include "led.h"
#include "radio.h"
#include "time.h"
#include "GNSS.h"
#include "spi.h"

// Select Radio Mode with the following define
// 0 = use radio_config.h in Src folder
// 1 = use config packets from Graw Firmware
// 2 = use PN9 mode
// 3 = use Carrier Tx
#define RADIO_MODE_SELECT 	2

#if (RADIO_MODE_SELECT == 0)
#include "radio_config.h"
#elif (RADIO_MODE_SELECT ==1)
#include "../Src/radioconfigs/radio_config_Si4063_GRAW.h"
#elif (RADIO_MODE_SELECT ==2)
#include "../Src/radioconfigs/radio_config_Si4063_PN9.h"
#elif (RADIO_MODE_SELECT ==3)
#include "../Src/radioconfigs/radio_config_Si4063_CW.h"
#endif


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


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define iSpiGPIO2_Pin GPIO_PIN_0
#define iSpiGPIO2_GPIO_Port GPIOD
#define oBattPOn_Pin GPIO_PIN_0
#define oBattPOn_GPIO_Port GPIOC
#define oSiSDN_Pin GPIO_PIN_3
#define oSiSDN_GPIO_Port GPIOC
#define oMuxMainSwitch_Pin GPIO_PIN_1
#define oMuxMainSwitch_GPIO_Port GPIOA
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
#define oMuxMultiSwitch_Pin GPIO_PIN_13
#define oMuxMultiSwitch_GPIO_Port GPIOB
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
#define oMuxMultiSwitchC10_Pin GPIO_PIN_10
#define oMuxMultiSwitchC10_GPIO_Port GPIOC
#define oTemp1Disc_Pin GPIO_PIN_11
#define oTemp1Disc_GPIO_Port GPIOC
#define oMux20kDisc_Pin GPIO_PIN_2
#define oMux20kDisc_GPIO_Port GPIOD
#define oMux332kDisc_Pin GPIO_PIN_4
#define oMux332kDisc_GPIO_Port GPIOB
#define oTemp2Disc_Pin GPIO_PIN_5
#define oTemp2Disc_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

int __io_putchar(int ch);
int _write(int file, char *ptr, int len);
void gpsUpdate(void);

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
