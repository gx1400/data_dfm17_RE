/*
 * radio.h
 *
 *  Created on: Feb 12, 2023
 *      Author: derek
 */

#ifndef INC_RADIO_H_
#define INC_RADIO_H_

// Mode switching with config file
#define USE_CW    0
#define USE_GRAW  1
#define USE_PN9   2

#define CONFIG_TO_USE USE_PN9

#ifndef CONFIG_TO_USE
#define CONFIG_TO_USE USE_GRAW
#endif

// Patch file
#include "..\drivers\radio\Si446x\si446x_patch.h"
#include "stm32f1xx_hal.h"



void assertRadioShutdown(void);
void deassertRadioShutdown(void);
void assertRadioCS(void);
void deassertRadioCS(void);

#endif /* INC_RADIO_H_ */
