/*
 * led.c
 *
 *  Created on: Feb 11, 2023
 *      Author: derek
 */

#include "led.h"


void testToggleLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_WritePin(Port, Pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(Port, Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
}
