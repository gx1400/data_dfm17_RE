/*
 * spi.h
 *
 *  Created on: Feb 12, 2023
 *      Author: gx1400
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

void SpiEnable(void);
void SpiDisable(void);
void SpiWriteData(int size, U8* data);
void SpiReadData (int size, U8 *data);
U8 SpiReadWrite(U8 byte);


#endif /* INC_SPI_H_ */
