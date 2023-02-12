/*
 * led.c
 *
 *  Created on: Feb 11, 2023
 *      Author: derek
 */

#include "led.h"

uint32_t Pin1Lastms 		= 0;
uint32_t Pin2Lastms 		= 0;
uint16_t Pin1IntervalMs		= 500;
uint16_t Pin2IntervalMs		= 1000;


void testToggleLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_WritePin(Port, Pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(Port, Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
}

void ledInterval(GPIO_TypeDef* Port1, uint16_t Pin1, GPIO_TypeDef* Port2, uint16_t Pin2) {
	uint32_t currentms = HAL_GetTick();


	if( (currentms - Pin1Lastms) >= Pin1IntervalMs) {
			Pin1Lastms = currentms;
			HAL_GPIO_TogglePin(Port1, Pin1);
	}

	if( (currentms - Pin2Lastms) >= Pin2IntervalMs) {
			Pin2Lastms = currentms;
			HAL_GPIO_TogglePin(Port2, Pin2);
	}
}
