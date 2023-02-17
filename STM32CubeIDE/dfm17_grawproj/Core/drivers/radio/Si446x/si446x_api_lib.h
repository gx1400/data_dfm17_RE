/*!
 * File:
 *  si446x_api_lib.h
 *
 * Description:
 *  This file contains the Si446x API library.
 *
 * Silicon Laboratories Confidential
 * Copyright 2011 Silicon Laboratories, Inc.
 */

#ifndef _SI446X_API_LIB_H_
#define _SI446X_API_LIB_H_

#include "radio.h"

extern union si446x_cmd_reply_union    Si446xCmd;
extern uint8_t    Pro2Cmd[16];


#define SI466X_FIFO_SIZE 64

enum
{
    SI446X_SUCCESS,
    SI446X_NO_PATCH,
    SI446X_CTS_TIMEOUT,
    SI446X_PATCH_FAIL,
    SI446X_COMMAND_ERROR
};

/* Minimal driver support functions */
void si446x_reset(void);
void si446x_power_up(uint8_t BOOT_OPTIONS, uint8_t XTAL_OPTIONS, uint32_t XO_FREQ);

uint8_t si446x_configuration_init(const uint8_t* pSetPropCmd);
uint8_t si446x_apply_patch(void);
void si446x_part_info(void);

void si446x_start_tx(uint8_t CHANNEL, uint8_t CONDITION, uint16_t TX_LEN);
void si446x_start_rx(uint8_t CHANNEL, uint8_t CONDITION, uint16_t RX_LEN, uint8_t NEXT_STATE1, uint8_t NEXT_STATE2, uint8_t NEXT_STATE3);

void si446x_get_int_status(uint8_t PH_CLR_PEND, uint8_t MODEM_CLR_PEND, uint8_t CHIP_CLR_PEND);
void si446x_gpio_pin_cfg(uint8_t GPIO0, uint8_t GPIO1, uint8_t GPIO2, uint8_t GPIO3, uint8_t NIRQ, uint8_t SDO, uint8_t GEN_CONFIG);

void si446x_set_property( uint8_t GROUP, uint8_t NUM_PROPS, uint8_t START_PROP, ... );
void si446x_change_state(uint8_t NEXT_STATE1);




#endif //_SI446X_API_LIB_H_
