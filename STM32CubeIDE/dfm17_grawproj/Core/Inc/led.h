/*
 * led.h
 *
 *  Created on: Feb 11, 2023
 *      Author: derek
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"



void testToggleLED(GPIO_TypeDef* Port, uint16_t Pin);

void ledInterval(GPIO_TypeDef* Port1, uint16_t Pin1, GPIO_TypeDef* Port2, uint16_t Pin2);

#endif /* SRC_LED_H_ */
