/*!
 * File:
 *  radio_hal.c
 *
 * Description:
 *  This file contains RADIO HAL.
 *
 * Silicon Laboratories Confidential
 * Copyright 2011 Silicon Laboratories, Inc.
 */

                /* ======================================= *
                 *              I N C L U D E              *
                 * ======================================= */

#include "radio.h"


                /* ======================================= *
                 *          D E F I N I T I O N S          *
                 * ======================================= */

                /* ======================================= *
                 *     G L O B A L   V A R I A B L E S     *
                 * ======================================= */

                /* ======================================= *
                 *      L O C A L   F U N C T I O N S      *
                 * ======================================= */

                /* ======================================= *
                 *     P U B L I C   F U N C T I O N S     *
                 * ======================================= */

void radio_hal_AssertShutdown(void)
{
  // SDN is PC3
  GPIOC->BSRR = (1U << 3);
}

void radio_hal_DeassertShutdown(void)
{
  // SDN is PC3
  GPIOC->BSRR = (1U << (16+3));
}

void radio_hal_ClearNsel(void)
{
	// nSEL/CS is PB2
	GPIOB-> BSRR = (1U << (16+2));
}

void radio_hal_SetNsel(void)
{
	// nSEL/CS is PB2
	GPIOB-> BSRR = (1U << 2);
}

unsigned char radio_hal_NirqLevel(void)
{
    return 1;
}

void radio_hal_SpiWriteByte(uint8_t byteToWrite)
{
  SpiReadWrite(byteToWrite);
}

uint8_t radio_hal_SpiReadByte(void)
{
  return SpiReadWrite(0xFF);
}

void radio_hal_SpiWriteData(uint8_t byteCount, uint8_t* pData)
{
  SpiWriteData(byteCount, pData);
}

void radio_hal_SpiReadData(uint8_t byteCount, uint8_t* pData)
{
  SpiReadData(byteCount, pData);
}

#ifdef RADIO_DRIVER_EXTENDED_SUPPORT
unsigned char radio_hal_Gpio0Level(void)
{
	unsigned char retVal = 0;

  return retVal;
}

unsigned char radio_hal_Gpio1Level(void)
{
	unsigned char retVal = 0;
  return retVal;
}

unsigned char radio_hal_Gpio2Level(void)
{
	unsigned char retVal = 0;

  return retVal;
}

unsigned char radio_hal_Gpio3Level(void)
{
	unsigned char retVal = 0;



  return retVal;
}

#endif
