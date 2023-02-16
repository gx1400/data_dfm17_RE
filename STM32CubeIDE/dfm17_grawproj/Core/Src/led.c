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




void ledOnGreen(void) {
	// Green LED is PC6
	GPIOC->BSRR = (1 << 6);
}

void ledOffGreen(void) {
	// Green LED is PC6
	GPIOC->BSRR = (1 << (16+6));
}

void ledOnRed(void) {
	// Red LED is PB12
	GPIOB->BSRR = (1 << 12);
}

void ledOffRed(void) {
	// Red LED is PB12
	GPIOB->BSRR = (1 << (16+12));
}

void ledOnYellow(void) {
	// Yellow LED is PC7
	GPIOC->BSRR = (1 << 7);
}

void ledOffYellow(void) {
	// Yellow LED is PC7
	GPIOC->BSRR = (1 << (16+7));

}



