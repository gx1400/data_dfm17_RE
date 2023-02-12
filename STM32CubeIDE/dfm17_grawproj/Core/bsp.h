/*! @file bsp.h
 * @brief This file contains application specific definitions and includes.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef BSP_H
#define BSP_H

/*------------------------------------------------------------------------*/
/*            Application specific global definitions                     */
/*------------------------------------------------------------------------*/
/*! Platform definition */
/* Note: Plaform is defined in Silabs IDE project file as
 * a command line flag for the compiler. */
//#define SILABS_PLATFORM_WMB930

/*! Extended driver support 
 * Known issues: Some of the example projects 
 * might not build with some extended drivers 
 * due to data memory overflow */
#undef  RADIO_DRIVER_EXTENDED_SUPPORT
#undef  RADIO_DRIVER_FULL_SUPPORT
#undef  SPI_DRIVER_EXTENDED_SUPPORT
#undef  HMI_DRIVER_EXTENDED_SUPPORT
#undef  TIMER_DRIVER_EXTENDED_SUPPORT
#undef  UART_DRIVER_EXTENDED_SUPPORT


#define PLATFORM_GRAW_DFM17
#define SILABS_RADIO_SI406X

// Select Radio Mode with the following define
// 0 = use radio_config.h in Src folder
// 1 = use config packets from Graw Firmware
// 2 = use PN9 mode
// 3 = use Carrier Tx
#define RADIO_MODE_SELECT 	0




/*------------------------------------------------------------------------*/
/*            Application specific includes                               */
/*------------------------------------------------------------------------*/

#include "drivers/compiler_defs.h"
#include "platform_defs.h"
#include "hardware_defs.h"

#include "Src/application_defs.h"

#include "drivers/spi.h"


#include "Src/radio.h"

#if (RADIO_MODE_SELECT == 0)
#include "Src/radio_config.h"
#elif (RADIO_MODE_SELECT ==1)
#include "Src/radioconfigs/radio_config_Si4063_GRAW.h"
#elif (RADIO_MODE_SELECT ==2)
#include "Src/radioconfigs/radio_config_Si4063_PN9.h"
#elif (RADIO_MODE_SELECT ==3)
#include "Src/radioconfigs/radio_config_Si4063_CW.h"
#endif


#include "drivers/radio/radio_hal.h"
#include "drivers/radio/radio_comm.h"

#ifdef PLATFORM_GRAW_DFM17
#include "stm32f1xx_hal.h"
#endif

#if ((defined SILABS_RADIO_SI446X) || (defined SILABS_RADIO_SI406X))
#include "drivers/radio/Si446x/si446x_api_lib.h"
#include "drivers/radio/Si446x/si446x_defs.h"
#include "drivers/radio/Si446x/si446x_nirq.h"
//#include "drivers\radio\Si446x\si446x_patch.h"
#endif

#endif //BSP_H
