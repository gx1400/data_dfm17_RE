/*
 * time.c
 *
 *  Created on: Feb 16, 2023
 *      Author: derek
 */

#ifndef INC_TIME_H_
#define INC_TIME_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

typedef struct {
	TIM_HandleTypeDef *htim;
} timerRef;

timerRef timRef;

void delayTimerInit(TIM_HandleTypeDef *htim);
void delay_us(uint8_t us);

#endif /* INC_TIME_H_ */
