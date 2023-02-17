/*!
 * File:
 *  radio_hal.h
 *
 * Description:
 *  This file contains RADIO HAL.
 *
 * Silicon Laboratories Confidential
 * Copyright 2011 Silicon Laboratories, Inc.
 */

#ifndef _RADIO_HAL_H_
#define _RADIO_HAL_H_

                /* ======================================= *
                 *              I N C L U D E              *
                 * ======================================= */

                /* ======================================= *
                 *          D E F I N I T I O N S          *
                 * ======================================= */

                /* ======================================= *
                 *     G L O B A L   V A R I A B L E S     *
                 * ======================================= */

                /* ======================================= *
                 *  F U N C T I O N   P R O T O T Y P E S  *
                 * ======================================= */

void radio_hal_AssertShutdown(void);
void radio_hal_DeassertShutdown(void);
void radio_hal_ClearNsel(void);
void radio_hal_SetNsel(void);
unsigned char radio_hal_NirqLevel(void);

void radio_hal_SpiWriteByte(uint8_t byteToWrite);
uint8_t radio_hal_SpiReadByte(void);

void radio_hal_SpiWriteData(uint8_t byteCount, uint8_t* pData);
void radio_hal_SpiReadData(uint8_t byteCount, uint8_t* pData);


void SPI_Transmit(uint8_t* data, int size);
void SPI_Receive (uint8_t* data, int size);
void SpiWriteData(int size, uint8_t* data);
void SpiReadData(int size, uint8_t* data);
uint8_t SpiReadWrite(uint8_t data);


#ifdef DRIVERS_EXTENDED_SUPPORT
unsigned char radio_hal_Gpio0Level(void);
unsigned char radio_hal_Gpio1Level(void);
unsigned char radio_hal_Gpio2Level(void);
unsigned char radio_hal_Gpio3Level(void);
#endif

#endif //_RADIO_HAL_H_
