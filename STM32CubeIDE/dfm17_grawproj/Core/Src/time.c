/*
 * time.c
 *
 *  Created on: Feb 16, 2023
 *      Author: derek
 */

#include "time.h"


timerRef timRef;

void delayTimerInit(TIM_HandleTypeDef *htim) {
	timRef.htim = htim;
	HAL_TIM_Base_Start(timRef.htim); //start timer
}

void delay_us(uint8_t us) {
	__HAL_TIM_SET_COUNTER(timRef.htim,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(timRef.htim) < us);  // wait for the counter to reach the us input in the parameter
}

