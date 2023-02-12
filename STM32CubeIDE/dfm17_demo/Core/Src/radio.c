/*
 * radio.c
 *
 *  Created on: Feb 12, 2023
 *      Author: derek
 */


#include "radio.h"


void radioToggleToneGPIO(uint16_t delay) {
	//GPIO3 is PA4
	GPIOA->BSRR = (1U << 4);
	delay_us(delay);
	GPIOA->BSRR = (1U << (16+4));
	delay_us(delay);
}


void assertRadioShutdown(void) {
	// SDN is PC3
	GPIOC->BSRR = (1U << 3);
}

void deassertRadioShutdown(void) {
	// SDN is PC3
	GPIOC->BSRR = (1U << (16+3));
}

void assertRadioCS(void) {
	// nSEL/CS is PB2
	GPIOB-> BSRR = (1U << (16+2));
}

void deassertRadioCS(void) {
	// nSEL/CS is PB2
	GPIOB-> BSRR = (1U << 2);
}
