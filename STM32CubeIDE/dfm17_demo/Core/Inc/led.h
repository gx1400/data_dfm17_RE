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
#include "main.h"



void testToggleLED(GPIO_TypeDef* Port, uint16_t Pin);


#endif /* SRC_LED_H_ */
