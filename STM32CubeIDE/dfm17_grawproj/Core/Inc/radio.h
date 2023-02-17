/*! @file radio.h
 * @brief This file contains the public functions controlling the radio chip.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef RADIO_H_
#define RADIO_H_

#define SEG_FAR
#define SEG_DATA
#define SEG_CODE

#define SEGMENT_VARIABLE(name, vartype, locsegment) vartype locsegment name
#define SEG_XDATA

#include "main.h"
#include "../drivers/compiler_defs.h"
#include "../drivers/radio/radio_comm.h"
#include "../drivers/radio/Si446x/si446x_api_lib.h"
#include "../drivers/radio/Si446x/si446x_defs.h"
#include "../drivers/radio/Si446x/si446x_nirq.h"



/*****************************************************************************
 *  Global Macros & Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Global Typedefs & Enums
 *****************************************************************************/
typedef struct
{
    uint8_t   *Radio_ConfigurationArray;

    uint8_t   Radio_ChannelNumber;
    uint8_t   Radio_PacketLength;
    uint8_t   Radio_State_After_Power_Up;

    uint16_t  Radio_Delay_Cnt_After_Reset;
} tRadioConfiguration;

/*****************************************************************************
 *  Global Variable Declarations
 *****************************************************************************/
extern const tRadioConfiguration   *pRadioConfiguration;

/*! Si446x configuration array */
extern const uint8_t    Radio_Configuration_Data_Array[];

/*****************************************************************************
 *  Global Function Declarations
 *****************************************************************************/
void  vRadio_Init(void);
void  vRadio_StartTx(uint8_t, uint8_t *);
uint8_t    bRadio_Check_Ezconfig(uint16_t);

#endif /* RADIO_H_ */
