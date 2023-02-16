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



// Green LED is PC6
void ledOnGreen(void) {
	GPIOC->BSRR = (1 << 6);
}

void ledOffGreen(void) {
	GPIOC->BSRR = (1 << (16+6));
}

void ledToggleGreen(void) {
	GPIOC->ODR ^= (1 << 6);
}

// Red LED is PB12
void ledOnRed(void) {
	GPIOB->BSRR = (1 << 12);
}

void ledOffRed(void) {
	GPIOB->BSRR = (1 << (16+12));
}

void ledToggleRed(void) {
	GPIOB->ODR ^= (1 << 12);
}

// Yellow LED is PC7
void ledOnYellow(void) {
	GPIOC->BSRR = (1 << 7);
}

void ledOffYellow(void) {
	GPIOC->BSRR = (1 << (16+7));
}

void ledToggleYellow(void) {
	GPIOC->ODR ^= (1 << 7);
}

