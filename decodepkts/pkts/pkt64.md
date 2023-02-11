# Pkt 64 - RF_MODEM_MOD_TYPE_12

**Summary**
```
Set properties:           RF_MODEM_MOD_TYPE_12
Number of properties:     12
Group ID:                 0x20
Start ID:                 0x00
Default values:           0x02, 0x80, 0x07, 0x0F, 0x42, 0x40, 0x01, 0xC9, 0xC3, 0x80, 0x00, 0x06, 
Descriptions:
  MODEM_MOD_TYPE - Selects the type of modulation. In TX mode, additionally selects the source of the modulation.
  MODEM_MAP_CONTROL - Controls polarity and mapping of transmit and receive bits.
  MODEM_DSM_CTRL - Miscellaneous control bits for the Delta-Sigma Modulator (DSM) in the PLL Synthesizer.
  MODEM_DATA_RATE_2 - Unsigned 24-bit value used to determine the TX data rate
  MODEM_DATA_RATE_1 - Unsigned 24-bit value used to determine the TX data rate
  MODEM_DATA_RATE_0 - Unsigned 24-bit value used to determine the TX data rate
  MODEM_TX_NCO_MODE_3 - TX Gaussian filter oversampling ratio and Byte 3 of unsigned 26-bit TX Numerically Controlled Oscillator (NCO) modulus.
  MODEM_TX_NCO_MODE_2 - TX Gaussian filter oversampling ratio and Byte 3 of unsigned 26-bit TX Numerically Controlled Oscillator (NCO) modulus.
  MODEM_TX_NCO_MODE_1 - TX Gaussian filter oversampling ratio and Byte 3 of unsigned 26-bit TX Numerically Controlled Oscillator (NCO) modulus.
  MODEM_TX_NCO_MODE_0 - TX Gaussian filter oversampling ratio and Byte 3 of unsigned 26-bit TX Numerically Controlled Oscillator (NCO) modulus.
  MODEM_FREQ_DEV_2 - 17-bit unsigned TX frequency deviation word.
  MODEM_FREQ_DEV_1 - 17-bit unsigned TX frequency deviation word.
```

*\*Note - 0A & 0B are top two of three words of MODEM_FREQ_DEV.  [Pkt 65](pkt65.md) has third word.*
*\*Note - See Packet 65 for MODEM_FREQ_DEV decode*

**Packet**
```
LENGTH:     0x 10
DATA:       0x 11 20 0C 00 6B 00 07 01 86 A0 05 86 A0 00 00 01
```


## Property 00 - MODEM_MOD_TYPE

**Summary:**    Selects the type of modulation. In TX mode, additionally selects the source of the modulation.

**Byte:**       0x 6B = 0b 0110 1011

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x00     | 7    | 0b0              | TX_DIRECT_MODE_TYPE     | 0 = SYNC mode |
| 0x00     | 6:5  | 0b11 = 3d        | TX_DIRECT_MODE_GPIO     | 3 = GPIO3 is TX Direct |
| 0x00     | 4:3  | 0b01 = 1d        | MOD_SOURCE              | 1 = DIRECT, modulation is real time |
| 0x00     | 2:0  | 0b011 = 3d       | MOD_TYPE                | 3 = 2GFSK |

## Property 01 - MODEM_MAP_CONTROL

**Summary:**    Controls polarity and mapping of transmit and receive bits.

**Byte:**       0x 00

| Property | Bits | Value | Function        | Decode   |
| -------: | ---: | ----: | :-------        | :-----   |
| 0x01     | 7    | 0b0   | ENMANCH         | 0 = ENUM_0 do not adjust sync word timeout |
| 0x01     | 6    | 0b0   | ENINV_RXBIT     | 0 = ENUM_0 do not invert RX  bits |
| 0x01     | 5    | 0b0   | ENINV_TXBIT     | 0 = ENUM_0 do not invert TX bits |
| 0x01     | 4    | 0b0   | ENINV_FD        | 0 = ENUM_0 do not invert polarity of freq deviation |
| 0x01     | 3    | 0b0   | ENINV_ADCQ      | 0 = ENUM_0 do not invert ADC Q channel |

## Property 02 - MODEM_DSM_CTRL

**Summary:**    Miscellaneous control bits for the Delta-Sigma Modulator (DSM) in the PLL Synthesizer.

**Byte:**       0x 07 = 0b 0000 0111

| Property | Bits | Value     | Function  | Decode   |
| -------: | ---: | ----:     | :-------  | :-----   |
| 0x02     | 7    | 0b0       | DSMCLK_SEL| 0 = ENUM_0 DSM clk from 30Mhz PLL |
| 0x02     | 6    | 0b0       | DSM_MODE  | 0 = ENUM_0 MASH 1-1-1  |
| 0x02     | 5    | 0b0       | DSMDT_EN  | 0 = ENUM_0 DSM dithering disabled |
| 0x02     | 4    | 0b0       | DSMDTTP   | 0 = ENUM_0 +1/0 added to DSM input LSB |
| 0x02     | 3    | 0b0       | DSM_RST   | 0 = ENUM_0 DSM is operational |
| 0x02     | 2    | 0b1       | DSM_LSB   | 1 = ENUM_1 LSB of DSM input is forced high | 
| 0x02     | 1:0  | 0b11 = 3d | DSM_ORDER | 3 = ENUM_3 3rd order MASH 1-1-1 |

## Property 03:05 - MODEM_DATA_RATE

**Summary:**    Unsigned 24-bit value used to determine the TX data rate

**Byte:**       0x 01 86 A0

| Property | Bits | Value  | Function                | Decode   |
| -------: | ---: | ----:  | :-------                | :-----   |
| 0x03     | 7:0  | 0x01   | DATA_RATE[23:16]        |          |
| 0x04     | 7:0  | 0x86   | DATA_RATE[15:8]         |          | 
| 0x05     | 7:0  | 0xA0   | DATA_RATE[7:0]          |          |

0x 0186A0 = 100,000d 

## Property 06:09 - MODEM_TX_NCO_MODE

**Summary:**    TX Gaussian filter oversampling ratio and Byte 3 of unsigned 26-bit TX Numerically Controlled Oscillator (NCO) modulus.

**Byte:**       0x 05 86 A0 00

0x05 = 0b 0000 0101

| Property | Bits | Value            | Function  | Decode   |
| -------: | ---: | ----:            | :-------  | :-----   |
| 0x06     | 3:2  | 0b01 = 1d        | TXOSR     | 1 = ENUM_1 TX Gaussian filter oversample ratio is 40x |
| 0x06     | 1:0  | 0b01             | NCOMOD[25:24] | |
| 0x07     | 7:0  | 0x86             | NCOMOD[23:16] | |
| 0x08     | 7:0  | 0xA0             | NCOMOD[15:8]  | |
| 0x09     | 7:0  | 0x00             | NCOMOD[7:0]   | |

0x 01 86 A0 00 = 25,600,000d

$NCO\_CLK\_FREQ = (\frac{MODEM\_DATA\_RATE \times Fxtal\_Hz}{MODEM\_TX\_NCO\_MODE})$

$TX\_DATA\_RATE = (\frac{NCO\_CLK\_FREQ}{TXOSR})$

Whereas:
- $MODEM\_DATA\_RATE = 100,000$
- $Fxtal\_Hz = 30,000,000 Hz$
- $MODEM\_TX\_NC0\_MODE = 30,000,000 Hz$
- $TX0SR = 40x$

$NC0\_CLK\_FREQ = 100,000 Hz$

$TX_DATA_RATE = 2500 Hz$