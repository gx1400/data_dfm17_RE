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

void ledOnGreen(void);
void ledOffGreen(void);
void ledOnRed(void);
void ledOffRed(void);
void ledOnYellow(void);
void ledOffYellow(void);

#endif /* SRC_LED_H_ */
