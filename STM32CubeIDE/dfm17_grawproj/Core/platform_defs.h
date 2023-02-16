/*! @file platform_defs.h
 * @brief This file contains platform specific definitions.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef PLATFORM_DEFS_H_
#define PLATFORM_DEFS_H_


/*---------------------------------------------------------------------*/
/*            Platform specific global definitions                     */
/*---------------------------------------------------------------------*/
#define PLATFORM_GRAW_DFM17
#define SILABS_RADIO_SI406X

// Select Radio Mode with the following define
// 0 = use radio_config.h in Src folder
// 1 = use config packets from Graw Firmware
// 2 = use PN9 mode
// 3 = use Carrier Tx
#define RADIO_MODE_SELECT 	1

#endif /* PLATFORM_DEFS_H_ */
