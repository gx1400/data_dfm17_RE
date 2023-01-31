# Si4063 Packet Decoding Notes

# Reference

- [Application Note AN633: PROGRAMMING GUIDE FOR EZRADIOPRO® Si4X6X DEVICES](../docs/AN633.pdf)
- [API documentation (zip file)](../docs/EZRadioPRO_REVC2_API.zip)

#  Packets from Firmware

| Packet Number | FW Address | Bytes | Transmit Data (HEX) | Command Type |
| :-----------: | :--------- | ----: | :------------------ | :----------- |
| 01 | 0x0000a012 | 08 | 04 21 71 4B 00 00 BA 9E | PATCH_IMAGE, Verify CRC, Use TRX Image, CRC 0x714B, Key 0xBA9E |
| 02 | 0x0000a01b | 08 | 05 48 23 2E 2B 90 B1 4E | PATCH_ARGS   |
| 03 | 0x0000a024 | 08 | EA 3F B9 E8 8B A9 CA D6 | PATCH_DATA   |
| 04 | 0x0000a02d | 08 | 05 D2 E5 BE D1 27 55 82 | PATCH_ARGS   |
| 05 | 0x0000a036 | 08 | E5 56 2A 3B 76 76 96 48 | PATCH_DATA   |
| 06 | 0x0000a03f | 08 | 05 8E 26 D8 5D 01 A7 88 | PATCH_ARGS   |
| 07 | 0x0000a048 | 08 | E2 89 CC 63 79 95 00 4B | PATCH_DATA   |
| 08 | 0x0000a051 | 08 | 05 E0 75 CD A4 B9 46 BC | PATCH_ARGS   |
| 09 | 0x0000a05a | 08 | EA D3 37 D2 9A 89 82 EA | PATCH_DATA   |
| 10 | 0x0000a063 | 08 | 05 0C AE 4C F5 F6 3C B3 | PATCH_ARGS   |
| 11 | 0x0000a06c | 08 | E9 A7 70 DF F1 14 4F 04 | PATCH_DATA   |
| 12 | 0x0000a075 | 08 | 05 FE 5B DF 47 0A 7C 5B | PATCH_ARGS   |
| 13 | 0x0000a07e | 08 | E2 FB 3E 21 A2 1B AA 93 | PATCH_DATA   |
| 14 | 0x0000a087 | 08 | 05 BF FD AB 69 6C A8 5A | PATCH_ARGS   |
| 15 | 0x0000a090 | 08 | E2 66 B7 2E 2C 45 2D FB | PATCH_DATA   |
| 16 | 0x0000a099 | 08 | 05 0D 55 BD C2 37 00 72 | PATCH_ARGS   |
| 17 | 0x0000a0a2 | 08 | E2 FF 57 4D 7C 6C 00 2C | PATCH_DATA   |
| 18 | 0x0000a0ab | 08 | 05 9E F2 46 FD D3 16 1B | PATCH_ARGS   |
| 19 | 0x0000a0b4 | 08 | EA 16 7F 67 4D E5 E2 C8 | PATCH_DATA   |
| 20 | 0x0000a0bd | 08 | 05 37 33 1C FA BB EE EF | PATCH_ARGS   |
| 21 | 0x0000a0c6 | 08 | EA 00 5F BE A4 FC BF C1 | PATCH_DATA   |
| 22 | 0x0000a0cf | 08 | 05 95 12 2F 0A CF 55 8C | PATCH_ARGS   |
| 23 | 0x0000a0d8 | 08 | E7 70 C2 D4 F0 81 95 C8 | PATCH_DATA   |
| 24 | 0x0000a0e1 | 08 | E7 72 00 F9 8D 15 01 A3 | PATCH_DATA   |
| 25 | 0x0000a0ea | 08 | E7 18 E5 6C 51 1F 86 9F | PATCH_DATA   |
| 26 | 0x0000a0f3 | 08 | E7 DD 37 59 4B AD B0 9C | PATCH_DATA   |
| 27 | 0x0000a0fc | 08 | E7 C8 E8 84 CD 55 41 83 | PATCH_DATA   |
| 28 | 0x0000a105 | 08 | EF 4F 8E 38 CB 37 02 87 | PATCH_DATA   |
| 29 | 0x0000a10e | 08 | E7 F5 00 88 4C 09 65 CE | PATCH_DATA   |
| 30 | 0x0000a117 | 08 | EF DD BC 65 62 AC 75 62 | PATCH_DATA   |
| 31 | 0x0000a120 | 08 | E7 C0 F1 5D 98 B0 DD 43 | PATCH_DATA   |
| 32 | 0x0000a129 | 08 | E7 19 B4 F8 9F 6D 8C CB | PATCH_DATA   |
| 33 | 0x0000a132 | 08 | E1 DE 63 C2 32 C6 E4 2F | PATCH_DATA   |
| 34 | 0x0000a13b | 08 | 05 F4 33 B7 2E 72 9A F9 | PATCH_DATA   |
| 35 | 0x0000a144 | 08 | E7 65 D9 38 B8 FE 31 16 | PATCH_DATA   |
| 36 | 0x0000a14d | 08 | E7 F3 06 2D F5 FE 0C 38 | PATCH_DATA   |
| 37 | 0x0000a156 | 08 | E7 70 4F E7 49 B4 58 39 | PATCH_DATA   |
| 38 | 0x0000a15f | 08 | EF F1 46 A9 23 38 64 C0 | PATCH_DATA   |
| 39 | 0x0000a168 | 08 | E7 09 4E 04 D3 46 15 02 | PATCH_DATA   |
| 40 | 0x0000a171 | 08 | EF 8D C7 20 C3 90 87 4D | PATCH_DATA   |
| 41 | 0x0000a17a | 08 | EF 00 AB 7F 27 02 C6 A0 | PATCH_DATA   |
| 42 | 0x0000a183 | 08 | E7 23 A6 A6 A4 27 11 7D | PATCH_DATA   |
| 43 | 0x0000a18c | 08 | EF B3 F1 9E 6A B3 19 AF | PATCH_DATA   |
| 44 | 0x0000a195 | 08 | E7 AB F5 15 78 5E 48 F8 | PATCH_DATA   |
| 45 | 0x0000a19e | 08 | EF 5B B1 2E AF 2A FF 16 | PATCH_DATA   |
| 46 | 0x0000a1a7 | 08 | E7 30 62 5C 82 7A 3F 83 | PATCH_DATA   |
| 47 | 0x0000a1b0 | 08 | EF 91 A7 D3 1B 64 85 BE | PATCH_DATA   |
| 48 | 0x0000a1b9 | 08 | E7 4D 81 94 E4 AA E8 DB | PATCH_DATA   |
| 49 | 0x0000a1c2 | 08 | EF A0 CC 4A 23 A5 7E 36 | PATCH_DATA   |
| 50 | 0x0000a1cb | 08 | EF 0C 72 4C FB 26 5A EC | PATCH_DATA   |
| 51 | 0x0000a1d4 | 08 | EF 0E 42 FA AF 49 A0 A8 | PATCH_DATA   |
| 52 | 0x0000a1dd | 08 | E7 6D 12 DF 2B 0C 61 58 | PATCH_DATA   |
| 53 | 0x0000a1e6 | 08 | EA B6 9B DE 81 B9 FF FF | PATCH_DATA   |
| 54 | 0x0000a1ef | 08 | 05 04 EB D8 12 D6 8D E0 | PATCH_ARGS   |
| 55 | 0x0000a1f8 | 08 | EC 29 66 4B DE B7 DE 36 | PATCH_DATA   |
| 56 | 0x0000a201 | 08 | 05 0D 28 B9 0A 89 31 1A | PATCH_ARGS   |
| 57 | 0x0000a20a | 07 | 02 81 01 01 86 A0 00    | POWER_UP     |
| 58 | 0x0000a212 | 08 | 13 10 0F 07 04 00 0B 00 | GPIO_PIN_CFG |
| 59 | 0x0000a21b | 06 | 11 00 02 00 62 60       | SET_PROPERTY - Group 00: GLOBAL                        |
| 60 | 0x0000a222 | 05 | 11 00 01 03 20          | SET_PROPERTY - Group 00: GLOBAL                        |
| 61 | 0x0000a228 | 05 | 11 01 01 00 00          | SET_PROPERTY - Group 01: INT_CTL                       |
| 62 | 0x0000a22e | 08 | 11 02 04 00 00 00 00 00 | SET_PROPERTY - Group 02: FRR_CTL                       |
| 63 | 0x0000a237 | 05 | 11 10 01 04 21          | SET_PROPERTY - Group 10: PREAMBLE                      |
| 64 | 0x0000a23d | 10 | 11 20 0C 00 6B 00 07 01 86 A0 05 86 A0 00 00 01 | SET_PROPERTY - Group 20: MODEM |
| 65 | 0x0000a24e | 05 | 11 20 01 0C 33          | SET_PROPERTY - Group 20: MODEM                         |
| 66 | 0x0000a254 | 10 | 11 20 0C 18 01 80 08 03 60 00 70 20 0C E8 01 40 | SET_PROPERTY - Group 20: MODEM |
| 67 | 0x0000a265 | 10 | 11 20 0C 24 01 99 9A 00 CD 00 C2 00 54 62 80 6B | SET_PROPERTY - Group 20: MODEM |
| 68 | 0x0000a276 | 07 | 11 20 03 30 01 E5 80    | SET_PROPERTY - Group 20: MODEM                         |
| 69 | 0x0000a27e | 05 | 11 20 01 35 E0          | SET_PROPERTY - Group 20: MODEM                         |
| 70 | 0x0000a284 | 10 | 11 20 0C 38 11 46 46 80 1A 99 9A 00 2A 0C 84 23 | SET PROPERTY - Group 20: MODEM |
| 71 | 0x0000a295 | 07 | 11 20 03 45 8F 00 9C    | SET_PROPERTY - Group 20: MODEM                         |
| 72 | 0x0000a29d | 06 | 11 20 02 50 94 09       | SET_PROPERTY - Group 20: MODEM                         |
| 73 | 0x0000a2a4 | 05 | 11 20 01 54 03          | SET_PROPERTY - Group 20: MODEM                         |
| 74 | 0x0000a2aa | 08 | 11 22 04 00 08 7F 00 1F | SET_PROPERTY - Group 22: PA                            |
| 75 | 0x0000a2b3 | 0B | 11 23 07 00 2C 0E 0B 04 0C 73 03 | SET_PROPERTY - Group 23: SYNTH                |
| 76 | 0x0000a2bf | 0B | 11 40 07 00 4D 09 00 00 04 00 20 | SET_PROPERTY - Group 40: FREQ_CONTROL         |

## Additional Setup Packets

Note the response packets below do not have including the "0xFF 0xxFF" response to the "0x44" READ_CMD_BUFF.

| Packet Number | Bytes | Command/Response | Data (HEX) | Command Type |
| :-----------: | ----: | :----------- | :--------- | :----------- |
| 77            | 01    | Command      | 33         | REQUEST_DEVICE_STATE |
| 78            | 02    | Response     | 03 00      | state READY | 
| 79            | 02    | Command      | 34 03      | CHANGE_STATE to READY |
| 80            | 0B    | Command      | 11 40 04 00 4D 05 B4 00 04 00 20 | SET_PROPERTY FREQ_CONTROL_CHANNEL_STEP_SIZE |
| 81            | 06    | Command      | 11 20 02 0D 00 00 | SET_PROPERTY MODEM_DSM_CTRL? |
| 82            | 06    | Command      | 11 20 02 0B 01 33 | SET_PROPERTY MODEM_DSM_CTRL? |
| 83            | 02    | Command      | 34 07      | CHANGE_STATE to TX |
| 84            | 01    | Command      | 33         | REQUEST_DEVICE_STATE |
| 85            | 02    | Response     | 07 00      | state TX |
| 86            | 02    | Command      | 34 03      | CHANGE_STATE to READY |
| 87            | 0B    | Command      | 11 40 04 00 4D 05 B4 00 04 00 20 | SET_PROPERTY FREQ_CONTROL_CHANNEL_STEP_SIZE |
| 88            | 02    | Command      | 34 07      | CHANGE_STATE to TX |
| 92            | 0B    | Command      | 11 40 04 00 4D 05 B4 00 04 00 20 | SET_PROPERTY FREQ_CONTROL_CHANNEL_STEP_SIZE |

### State Enum
| State Name | Value | 
| :--------- | :---: |
| NO CHANGE  | 0     | 
| SLEEP      | 1     |
| SPI_ACTIVE | 2     |
| READY      | 3     | 
| READY2     | 4     | 
| TX_TUNE    | 5     |
| RX_TUNE    | 6     |
| TX         | 7     | 
| RX         | 8     | 

# Packet Decoding

## Pkt 57 - POWER_UP

**Function:**   POWER_UP

**Summary:**    Command to power-up the device and select the operational mode and functionality.

```
LENGTH:     0x 07
DATA:       0x 02 81 01 01 86 A0 00
```

| Byte Index | Bits | Value       | Function     | Decode |
| ---------: | ---: | ----:       | :-------     | :----- |
| 0x00       | 7:0  | 0x02        | POWER_UP Cmd |        |
| 0x01       | 7    | 0b1         | PATCH        | Patch has been applied |
| 0x01       | 5:0  | 1d          | FUNC         | Stay in boot mode      |
| 0x02       | 0    | 0b1         | TCXO         | Reference signal is derived from external TXCO |
| 0x03:06    | all  | 0x0186 A000 | XO_FREQ      | 0x0186A000 = 25600000Hz = 25.6Mhz external clock |

## Pkt 58 - GPIO_PIN_CFG

**Function:**   GPIO_PIN_CFG

**Summary:**    Configures the GPIO pins.


```
LENGTH:     0x 08
DATA:       0x 13 10 0F 07 04 00 0B 00
```

| Byte Index | Bits | Value         | Function         | Decode |
| ---------: | ---: | ----:         | :-------         | :----- |
| 0x00       | 7:0  | 0x13          | GPIO_PIN_CFG Cmd |        |
| 0x01       | 6    | 0b0           | GPIO0 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x01       | 5:0  | 0b10000 = 16d | GPIO0 MODE       | 16d = TX_DATA_CLK |
| 0x02       | 6    | 0b0           | GPIO1 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x02       | 5:0  | 0b01111 = 15d | GPIO1 MODE       | 15d = EN_PA |
| 0x03       | 6    | 0b0           | GPIO2 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x03       | 5:0  | 0b00111 = 7d  | GPIO2 MODE       | 7d = DIV_CLK  |
| 0x04       | 6    | 0b0           | GPIO3 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x04       | 5:0  | 0b00100 = 4d  | GPIO2 MODE       | 4d = INPUT |
| 0x05       | 6    | 0b0           | NIRQ PULL_CTL    | PULL_DIS, disable pull up resistor |
| 0x05       | 5:0  | 0b00000 = 0d  | NIRQ_MODE        | DONOTHING |
| 0x06       | 6    | 0b0           | SDO PULL_CTL     | PULL_DIS, disable pull up resistor |
| 0x06       | 5:0  | 0x0B = 11d    | SDO_MODE         | 11d = SDO,  |
| 0x07       | 6:5  | 0b00 = 0d     | DRV_STRENGTH     | 0d = HIGH, GPIOs configured to have highest drive strength |

**GPIO0 Mode:** TX_DATA_CLK
- STM32 Pin: Not Connected?
- This signal is a square wave at the selected TX data rate, and is intended for use in TX Direct Synchronous Mode (i.e., in conjunction with a pin configured for TX Data Input).

**GPIO1 Mode:** EN_PA
- STM32 Pin: Not Connected, routes to PTH Test point directly above pin
- This output goes high when the internal PA is enabled.

**GPIO2 Mode:** DIV_CLK
- STM32 Pin: PD0
- Outputs the divided clock signal (or the divided boot clock signal in SPI ACTIVE state). 
- This output is low while the chip is in SLEEP state as the source (e.g., the Xtal Oscillator) for the divided clock signal is not running, and outputs the divided XtalOsc signal in all other states. 
- The divider is configured using the GLOBAL_CLK_CFG:DIVIDED_CLK_SEL

**GPIO3 Mode:** INPUT
- STM32 Pin: PA4
- Pin is configured as a CMOS input. This is used for all GPIO functions that require the pin to be an input (e.g., TXDATA input for TX Direct Mode). 
- However, configuration of this pin as an input does NOT additionally select which internal circuit receives that input; that functionality is controlled by other properties, as appropriate.

**NIRQ Mode:** DONOTHING
- STM Pin: Not connected
- Behavior of this pin is not modified

**SDO Mode:**: SDO
- STM32 Pin: PA6
- Outputs serial data out signal for SPI bus

## Pkt 59 - SET_PROPERTY - GLOBAL (2 Properties)

**Function:**   SET_PROPERTY

**Summary:**    Sets the value of one or more properties.

- Group:            00  GLOBAL
- Property Count:   02
  - Property:       00  GLOBAL_XO_TUNE
  - Property:       01  GLOBAL_CLK_CFG

```
LENGTH:     0x 06 
DATA:       0x 11 00 02 00 62 60
```

### Property 00 - GLOBAL_XO_TUNE

**Summary:**    Configure the internal capacitor frequency tuning bank for the crystal oscillator. 

**Byte:**       0x 62 = 0b 0110 0010

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x00     | 6:0  | 0b1100010 = 98d  | TUNE_VALUE       | 98d * 70e-15 pF = 6.86pF |

### Property 01 - GLOBAL_CLK_CFG

**Summary:**    Clock configuration options.

**Byte:**       0x 60 = 0b 0110 0000

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x01     | 6    | 0b1              | DIVIDED_CLK_EN   | Divided system clock output is enabled |
| 0x01     | 5:3  | 0b100 = 4d       | DIVIDED_CLK_SEL  | 4d = DIV_10, Clock output is divided by 10 |
| 0x01     | 1:0  | 0b00 = 0d        | CLK_32K_SEL      | 0d = OFF, 32KHz clock is disabled. |

## Pkt 60 - SET_PROPERTY - GLOBAL_CONFIG (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 00 01 03 20
```
- Group:            00  GLOBAL
- Property Count:   01
  - Property:       03  GLOBAL_CONFIG
  
### Property 03 - GLOBAL_CONFIG

**Summary:**    Global configuration settings.

**Byte:**       0x 20 = 0b 0010 0000

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x03     | 5    | 0b1              | SEQUENCER_MODE   | 1 = FAST, Enter TX mode as quickly as possible after START_TX Cmd |
| 0x03     | 4    | 0b0              | FIFO_MODE        | 0 = SPLIT_FIFO, Tx & Rx FIFO are independent (not applicable for Si4063) |
| 0x03     | 3:1  | 0b000 = 0d       | PROTOCOL         | 0 = GENERIC packet format |
| 0x03     | 0    | 0b0              | POWER_MODE       | 0 = HIGH_PERF, high performance mode |

## Pkt 61 - SET_PROPERTY - INT_CTL (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 01 01 00 00
```
- Group:            01  INT_CTL
- Property Count:   01
  - Property:       01  INT_CTL_PH_ENABLE

**Summary:**    Enable individual interrupt sources within the Packet Handler Interrupt Group to generate a HW interrupt on the NIRQ output pin.

**Byte:**       0x 00 = 0b 0000 0000

| Property | Bits | Value            | Function                | Decode |
| -------: | ---: | ----:            | :-------                | :----- |
| 0x00     | 7    | 0b0              | FILTER_MATCH_EN         |        |
| 0x00     | 6    | 0b0              | FILTER_MISS_EN          |        |
| 0x00     | 5    | 0b0              | PACKET_SENT_EN          |        |
| 0x00     | 4    | 0b0              | PACKET_RX_EN            |        |
| 0x00     | 3    | 0b0              | CRC_ERROR_EN            |        |
| 0x00     | 2    | 0b0              | ALT_CRC_ERROR_EN        |        |
| 0x00     | 1    | 0b0              | TX_FIFO_ALMOST_EMPTY_EN |        |
| 0x00     | 0    | 0b0              | RX_FIFO_ALMOST_FULL_EN  |        |

*\*Note - All interrupts disabled*


## Pkt 62 - SET_PROPERTY - FRR_CTL (4 Properties)

```
LENGTH:     0x 08
DATA:       0x 11 02 04 00 00 00 00 00
```
- Group:            02  FRR_CTL
- Property Count:   04
  - Property:       00  FRR_CTL_A_MODE
  - Property:       01  FRR_CTL_B_MODE
  - Property:       02  FRR_CTL_C_MODE
  - Property:       03  FRR_CTL_D_MODE

### Property 00 - FRR_CTL_A_MODE

**Summary:**    Fast Response Register A Configuration.

**Byte:**       0x 00

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x00     | 7:0  | 0x00             | FRR_A_MODE              | Disabled |

### Property 01 - FRR_CTL_B_MODE

**Summary:**    Fast Response Register B Configuration.

**Byte:**       0x 00

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x00     | 7:0  | 0x00             | FRR_B_MODE              | Disabled |


### Property 02 - FRR_CTL_C_MODE

**Summary:**    Fast Response Register C Configuration.

**Byte:**       0x 00

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x00     | 7:0  | 0x00             | FRR_C_MODE              | Disabled |



### Property 03 - FRR_CTL_D_MODE

**Summary:**    Fast Response Register D Configuration.

**Byte:**       0x 00

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x00     | 7:0  | 0x00             | FRR_D_MODE              | Disabled |

## Pkt 63 - SET_PROPERTY - PREAMBLE (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 10 01 04 21
```
- Group:            10  PREAMBLE
- Property Count:   01
  - Property:       04  PREAMBLE_CONFIG

**Summary:**    General configuration bits for the Preamble field.

**Byte:**       0x 21 = 0b 0010 0001

| Property | Bits | Value      | Function           | Decode   |
| -------: | ---: | ----:      | :-------           | :-----   |
| 0x04     | 7    | 0b0        | RX_PREAM_SRC       | 0 = STANDARD_PREAM |
| 0x04     | 5    | 0b1        | PREAM_FIRST_1_OR_0 | 1 = first bit transmitted is a 1 |
| 0x04     | 4    | 0b0        | LENGTH_CONFIG      | 0 = length of PREAMBLE_TX_LENGTH is nibbles |
| 0x04     | 3    | 0b0        | MAN_CONST          | 0 = ... RTFM ... |
| 0x04     | 2    | 0b0        | MAN_ENABLE         | 0 = not Manchester encoding |
| 0x04     | 1:0  | 0b01 = 1d  | STANDARD_PREAM     | 0 = PRE_1010 |

## Pkt 64 - SET_PROPERTY - MODEM (12 Properties)

```
LENGTH:     0x 10
DATA:       0x 11 20 0C 00 6B 00 07 01 86 A0 05 86 A0 00 00 01
```
- Group:            20  MODEM
- Property Count:   0C
  - Property:       00      MODEM_MOD_TYPE
  - Property:       01      MODEM_MAP_CONTROL
  - Property:       02      MODEM_DSM_CTRL
  - Property:       03:05   MODEM_DATA_RATE
  - Property:       06:09   MODEM_TX_NCO_MODE
  - Property:       0A:0B   MODEM_FREQ_DEV [2:1]*

*\*Note - 0A & 0B are top two of three words of MODEM_FREQ_DEV.  Pkt 65 has third word.*
*\*Note - See Packet 65 for MODEM_FREQ_DEV decode*

## Pkt 65 - SET_PROPERTY - MODEM (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 20 01 0C 33
```
- Group:            20  MODEM
- Property Count:   01
  - Property:       0C  MODEM_FREQ_DEV [0]*

*\*Note - 0C is bottom words of MODEM_FREQ_DEV.  Pkt 64 has first and second word.*

## Pkt 66 - SET_PROPERTY - MODEM (12 Properties)

```
LENGTH:     0x 10
DATA:       0x 11 20 0C 18 01 80 08 03 60 00 70 20 0C E8 01 40
```
- Group:            20  MODEM
- Property Count:   0C
  - Property:       18      MODEM_TX_RAMP_DELAY
  - Property:       19      MODEM_MDM_CTRL
  - Property:       1A      MODEM_IF_CONTROL
  - Property:       1B:1D   MODEM_IF_FREQ
  - Property:       1E      MODEM_DECIMATION_CFG1
  - Property:       1F      MODEM_DECIMATION_CFG0
  - Property:       20      MODEM_RESERVED_20_20
  - Property:       21      MODEM_RESERVED_20_21
  - Property:       22:23   MODEM_BCR_OSR
  
## Pkt 67 - SET_PROPERTY - MODEM (12 Properties)

```
LENGTH:     0x 10
DATA:       0x 11 20 0C 24 01 99 9A 00 CD 00 C2 00 54 62 80 6B
```
- Group:            20  MODEM
- Property Count:   0C
  - Property:       24:26   MODEM_BCR_NCO_OFFSET  
  - Property:       27:28   MODEM_BCR_GAIN  
  - Property:       29      MODEM_BCR_GEAR
  - Property:       2A      MODEM_BCR_MISC1
  - Property:       2B      MODEM_BCR_MISC0
  - Property:       2C      MODEM_AFC_GEAR
  - Property:       2D      MODEM_AFC_WAIT
  - Property:       2E:2F   MODEM_AFC_GAIN

## Pkt 68 - SET_PROPERTY - MODEM (3 Properties)

```
LENGTH:     0x 07
DATA:       0x 11 20 03 30 01 E5 80
```
- Group:            20      MODEM
- Property Count:   03
  - Property:       30:31   MODEM_AFC_LIMITER
  - Property:       32      MODEM_AFC_MISC

## Pkt 69 - SET_PROPERTY - MODEM (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 20 01 35 E0
```
- Group:            20  MODEM
- Property Count:   01
  - Property:       35  MODEM_AGC_CONTROL

## Pkt 70 - SET_PROPERTY - MODEM (12 Properties)

```
LENGTH:     0x 10
DATA:       0x 11 20 0C 38 11 46 46 80 1A 99 9A 00 2A 0C 84 23
```
- Group:            20      MODEM
- Property Count:   0C
  - Property:       38      MODEM_AGC_WINDOW_SIZE
  - Property:       39      MODEM_AGC_RFPD_DECAY
  - Property:       3A      MODEM_AGC_IFPD_DECAY
  - Property:       3B      MODEM_FSK4_GAIN1
  - Property:       3C      MODEM_FSK4_GAIN0
  - Property:       3D:3E   MODEM_FSK4_TH
  - Property:       3F      MODEM_FSK4_MAP
  - Property:       40      MODEM_OOK_PDTC
  - Property:       41      MODEM_OOK_BLOPK
  - Property:       42      MODEM_OOK_CNT1
  - Property:       43      MODEM_OOK_MISC

## Pkt 71 - SET_PROPERTY - MODEM (3 Properties)

```
LENGTH:     0x 07
DATA:       0x 11 20 03 45 8F 00 9C
```
- Group:            20      MODEM
- Property Count:   03
  - Property:       45      MODEM_RAW_CONTROL
  - Property:       46:47   MODEM_RAW_EYE

## Pkt 72 - SET_PROPERTY - MODEM (2 Properties)

```
LENGTH:     0x 06
DATA:       0x 11 20 02 50 94 09 
```
- Group:            20      MODEM
- Property Count:   02
  - Property:       50      MODEM_RAW_SEARCH2
  - Property:       51      MODEM_CLKGEN_BAND

## Pkt 73 - SET_PROPERTY - MODEM (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 20 01 54 03
```
- Group:            20      MODEM
- Property Count:   01
  - Property:       54      MODEM_SPIKE_DET

## Pkt 74 - SET_PROPERTY - PA (4 Properties)

```
LENGTH:     0x 08
DATA:       0x 11 22 04 00 08 7F 00 1F
```
- Group:            22      PA
- Property Count:   04
  - Property:       00      PA_MODE
  - Property:       01      PA_PWR_LVL
  - Property:       02      PA_BIAS_CLKDUTY
  - Property:       03      PA_TC

## Pkt 75 - SET_PROPERTY - SYNTH (7 Properties)

```
LENGTH:     0x 0B
DATA:       0x 11 23 07 00 2C 0E 0B 04 0C 73 03
```
- Group:            23      SYNTH
- Property Count:   07
  - Property:       00  SYNTH_PFDCP_CPFF
  - Property:       01  SYNTH_PFDCP_CPINT
  - Property:       02  SYNTH_VCO_KV
  - Property:       03  SYNTH_LPFILT3
  - Property:       04  SYNTH_LPFILT2
  - Property:       05  SYNTH_LPFILT1
  - Property:       06  SYNTH_LPFILT0

## Pkt 76 - SET_PROPERTY - FREQ_CONTROL (1 Property)

```
LENGTH:     0x 0B
DATA:       0x 11 40 07 00 4D 09 00 00 04 00 20
```
- Group:            40      FREQ_CONTROL
- Property Count:   07
  - Property:       00      FREQ_CONTROL_INTE
  - Property:       01:03   FREQ_CONTROL_FRAC
  - Property:       04:05   FREQ_CONTROL_CHANNEL_STEP_SIZE
  - Property:       06      FREQ_CONTROL_W_SIZE

$RF_{Channel_{Hz}}=\left(fc_{inte}+\frac{fc_{frac}}{2^{19}}\right) \times \left(\frac{N_{PRESC} \times freq\_xo}{outdiv}\right)$

Whereas:
- $fc_{inte} = 77$
- $fc_{frac} = 589,824$
- $N_{PRESC} = 2$
- $freq\_xo = 25,600,000$
- $outdiv = 10$

$RF_{Channel_{Hz}}=400,000,000 Hz$

### Property 00 - FREQ_CONTROL_INTE

**Summary:**    Frac-N PLL Synthesizer integer divide number.

**Byte:**       0x 4D = 0b 0100 1101


| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x00     | 6:0  | 0b1001101 = 77d  | INTE             | 77d    |

### Property 01:03 - FREQ_CONTROL_FRAC

**Summary:**    Frac-N PLL Synthesizer integer divide number.

**Bytes:**       0x 09 00 00 = 0b 0000 1001 0000 0000 0000 0000

$RF_{Channel_{Hz}}=\left(fc_{inte}+\frac{fc_{frac}}{2^{19}}\right) \times \left(\frac{N_{PRESC} \times freq\_xo}{outdiv}\right)$

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x01     | 3:0  | 0b1001           | FRAC[19:16]      |        |
| 0x02     | 7:0  | 0b0000 0000      | FRAC[15:8]       |        |
| 0x03     | 7:0  | 0b0000 0000      | FRAC[7:0]        |        |

FRAC = 0x 09 00 00 = 589,824d

### Property 04:05 - FREQ_CONTROL_CHANNEL_STEP_SIZE

**Summary:**    EZ Frequency Programming channel step size.

**Bytes:**      0x 04 00 = 0b 0100 0000 0000 0000


| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x04     | 7:0  | 0b01000000       | CHANNEL_STEP_SIZE[15:8] | |
| 0x05     | 7:0  | 0b00000000       | CHANNEL_STEP_SIZE[7:0]  | |

Channel Step Size = 0x 04 00 = 1024d

FREQ_CONTROL_CHANNEL_STEP_SIZE property is given by the following equation:

$FREQ\_CTRL\_CHAN\_STEP\_SIZE=\frac{2^{19} \times outdiv \times Desired\_Stepsize\_Hz}{N_{PRESC} \times freq\_xo}$

Whereas: 

- $outdiv = 10$
- $Desired\_Stepsize\_Hz =\ 1024$
- $N_{PRESC} = 2$
- $freq\_xo = 25,600,000$

$FREQ\_CTRL\_CHAN\_STEP\_SIZE =\ 104.8576 Hz$

### Property 06 - FREQ_CONTROL_W_SIZE

**Summary:**    Set window gating period (in number of crystal reference clock cycles) for counting VCO frequency during calibration.

**Bytes:**      0x 20 = 32d

*\*Note: This property does not need to change as a function of crystal reference frequency; the chip automatically calculates the target VCO count value as a function of crystal reference frequency and thus this property may remain constant. Silicon Labs recommends setting this property always to 0x20.*

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x06     | 7:0  | 0x20 = 32d       | W_SIZE           |        |

