 /*
 * GNSS.h
 *
 *  Created on: 03.10.2020
 *      Author: SimpleMethod
 *
 *Copyright 2020 SimpleMethod
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of
 *this software and associated documentation files (the "Software"), to deal in
 *the Software without restriction, including without limitation the rights to
 *use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *of the Software, and to permit persons to whom the Software is furnished to do
 *so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *THE SOFTWARE.
 ******************************************************************************
 */

#ifndef INC_GNSS_H_
#define INC_GNSS_H_

#include "../bsp.h"

union u_Short
{
	uint8_t bytes[2];
	unsigned short uShort;
};

union i_Short
{
	uint8_t bytes[2];
	signed short iShort;
};

union u_Long
{
	uint8_t bytes[4];
	unsigned long uLong;
};

union i_Long
{
	uint8_t bytes[4];
	signed long iLong;
};

typedef struct
{
	UART_HandleTypeDef *huart;

	uint8_t uniqueID[4];
	uint8_t uartWorkingBuffer[101];

	unsigned short year;
	uint8_t yearBytes[2];
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t fixType;

	signed long lon;
	uint8_t lonBytes[4];
	signed long lat;
	uint8_t latBytes[4];
	float fLon;
	float fLat;

	signed long height;
	signed long hMSL;
	uint8_t hMSLBytes[4];
	unsigned long hAcc;
	unsigned long vAcc;

	signed long gSpeed;
	uint8_t gSpeedBytes[4];
	signed long headMot;

	uint8_t *txDone;
	uint8_t *rxDone;

}GNSS_StateHandle;



enum GNSSMode{Portable=0, Stationary=1, Pedestrian=2, Automotiv=3, Airbone1G=5, Airbone2G=6,Airbone4G=7,Wirst=8,Bike=9};

static const uint8_t configUBX[]={0xB5,0x62,0x06,0x00,0x14,0x00,0x01,0x00,0x00,0x00,0xD0,0x08,0x00,0x00,0x80,0x25,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x9A,0x79};

static const uint8_t setNMEA410[]={0xB5,0x62,0x06,0x17,0x14,0x00,0x00,0x41,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x75,0x57};

//Activation of navigation system: Galileo, Glonass, GPS, SBAS, IMES
static const uint8_t setGNSS[]={0xB5,0x62,0x06,0x3E,0x24,0x00,0x00,0x00,0x20,0x04,0x00,0x08,0x10,0x00,0x01,0x00,0x01,0x01,0x01,0x01,0x03,0x00,0x01,0x00,0x01,0x01,0x02,0x04,0x08,0x00,0x01,0x00,0x01,0x01,0x06,0x08,0x0E,0x00,0x01,0x00,0x01,0x01,0xDF,0xFB};

static const uint8_t getDeviceID[]={0xB5,0x62,0x27,0x03,0x00,0x00,0x2A,0xA5};

static const uint8_t getNavigatorData[]={0xB5,0x62,0x01,0x21,0x00,0x00,0x22,0x67};

static const uint8_t getPOSLLHData[]={0xB5,0x62,0x01,0x02,0x00,0x00,0x03,0x0A};

static const uint8_t getPVTData[]={0xB5,0x62,0x01,0x07,0x00,0x00,0x08,0x19};

static const uint8_t setPortableMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x00,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x3C};

static const uint8_t setStationaryMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x02,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80};

static const uint8_t setPedestrianMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x03,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0xA2};

static const uint8_t setAutomotiveMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x04,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0xC4};

//static const uint8_t setSeaMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x05,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xE6};

static const uint8_t setAirbone1GMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x06,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x84,0x08};

static const uint8_t setAirbone2GMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x07,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x85,0x2A};

static const uint8_t setAirbone4GMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x08,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x86,0x4C};

static const uint8_t setWirstMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x09,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0x6E};

static const uint8_t setBikeMode[]={0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x0A,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x5E,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x90};

static const uint8_t setPortableType[]={};
void GNSS_Init(GNSS_StateHandle *GNSS, UART_HandleTypeDef *huart, uint8_t *txDone, uint8_t *rxDone);
void GNSS_LoadConfig(GNSS_StateHandle *GNSS);
void GNSS_ParseBuffer(GNSS_StateHandle *GNSS);

void GNSS_GetUniqID(GNSS_StateHandle *GNSS);
void GNSS_ParseUniqID(GNSS_StateHandle *GNSS);

void GNSS_GetNavigatorData(GNSS_StateHandle *GNSS);
void GNSS_ParseNavigatorData(GNSS_StateHandle *GNSS);

void GNSS_GetPOSLLHData(GNSS_StateHandle *GNSS);
void GNSS_ParsePOSLLHData(GNSS_StateHandle *GNSS);

void GNSS_GetPVTData(GNSS_StateHandle *GNSS);
void GNSS_ParsePVTData(GNSS_StateHandle *GNSS);

void GNSS_SetMode(GNSS_StateHandle *GNSS, short gnssMode);
#endif /* INC_GNSS_H_ */



