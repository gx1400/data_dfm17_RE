/*
 * spi.h
 *
 *  Created on: Feb 12, 2023
 *      Author: gx1400
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f1xx_hal.h"

void SpiEnable(void);
void SpiDisable(void);
void SpiWriteData(int size, uint8_t* data);
void SpiReadData (int size, uint8_t *data);
uint8_t SpiReadWrite(uint8_t byte);


#endif /* INC_SPI_H_ */
