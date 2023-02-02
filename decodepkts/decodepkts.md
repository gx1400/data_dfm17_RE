# Si4063 Packet Decoding Notes

# Reference

- [Application Note AN633: PROGRAMMING GUIDE FOR EZRADIOPRO® Si4X6X DEVICES](../docs/AN633.pdf)
- [API documentation (zip file)](../docs/EZRadioPRO_REVC2_API.zip)
- [Errata with PATCH information](../docs/ezradio-ezradiopro-c2a-a2a-errata.pdf)

#  Packets from Firmware

## PATCH DATA Packets

- See [Errata with PATCH information](../docs/ezradio-ezradiopro-c2a-a2a-errata.pdf) for more info on patch
- [Silicon Labs Knowledge Article "Latest patch for  EZRadio/PRO and do I need to use it?"](https://community.silabs.com/s/article/latest-patch-for-ezradio-pro-and-do-i-need-to-use-it-x?language=en_US) - [PDF Print of page](patchfile/patchfile_helppage.pdf)
- [Latest Patchfile](patchfile/fw_6_0_2_4668.csg)

[Click here to see Packets 01-56 with PATCH_IMAGE, PATCH_ARGS, & PATCH_DATA](patchfile/patchfromfw.md)


## RADIO CONFIGURATION Packets

| Packet Number | FW Address | Bytes | Transmit Data (HEX) | Command Type |
| :-----------: | :--------- | ----: | :------------------ | :----------- |
| 57 | 0x0000a20a | 07 | 02 81 01 01 86 A0 00    | [POWER_UP](pkts/pkt57.md)     |
| 58 | 0x0000a212 | 08 | 13 10 0F 07 04 00 0B 00 | [GPIO_PIN_CFG](pkts/pkt58.md) |
| 59 | 0x0000a21b | 06 | 11 00 02 00 62 60       | [SET_PROPERTY - Group 00: GLOBAL](pkts/pkt59.md)       |
| 60 | 0x0000a222 | 05 | 11 00 01 03 20          | [SET_PROPERTY - Group 00: GLOBAL](pkts/pkt60.md)       |
| 61 | 0x0000a228 | 05 | 11 01 01 00 00          | [SET_PROPERTY - Group 01: INT_CTL](pkts/pkt61.md)      |
| 62 | 0x0000a22e | 08 | 11 02 04 00 00 00 00 00 | [SET_PROPERTY - Group 02: FRR_CTL](pkts/pkt62.md)      |
| 63 | 0x0000a237 | 05 | 11 10 01 04 21          | [SET_PROPERTY - Group 10: PREAMBLE](pkts/pkt63.md)     |
| 64 | 0x0000a23d | 10 | 11 20 0C 00 6B 00 07 01 86 A0 05 86 A0 00 00 01 | [SET_PROPERTY - Group 20: MODEM](pkts/pkt64.md) |
| 65 | 0x0000a24e | 05 | 11 20 01 0C 33          | [SET_PROPERTY - Group 20: MODEM](pkts/pkt65.md)                         |
| 66 | 0x0000a254 | 10 | 11 20 0C 18 01 80 08 03 60 00 70 20 0C E8 01 40 | [SET_PROPERTY - Group 20: MODEM](pkts/pkt66.md) |
| 67 | 0x0000a265 | 10 | 11 20 0C 24 01 99 9A 00 CD 00 C2 00 54 62 80 6B | SET_PROPERTY - Group 20: MODEM |
| 68 | 0x0000a276 | 07 | 11 20 03 30 01 E5 80    | SET_PROPERTY - Group 20: MODEM                         |
| 69 | 0x0000a27e | 05 | 11 20 01 35 E0          | SET_PROPERTY - Group 20: MODEM                         |
| 70 | 0x0000a284 | 10 | 11 20 0C 38 11 46 46 80 1A 99 9A 00 2A 0C 84 23 | SET PROPERTY - Group 20: MODEM |
| 71 | 0x0000a295 | 07 | 11 20 03 45 8F 00 9C    | SET_PROPERTY - Group 20: MODEM                         |
| 72 | 0x0000a29d | 06 | 11 20 02 50 94 09       | SET_PROPERTY - Group 20: MODEM                         |
| 73 | 0x0000a2a4 | 05 | 11 20 01 54 03          | SET_PROPERTY - Group 20: MODEM                         |
| 74 | 0x0000a2aa | 08 | 11 22 04 00 08 7F 00 1F | SET_PROPERTY - Group 22: PA                            |
| 75 | 0x0000a2b3 | 0B | 11 23 07 00 2C 0E 0B 04 0C 73 03 | SET_PROPERTY - Group 23: SYNTH                |
| 76 | 0x0000a2bf | 0B | 11 40 07 00 4D 09 00 00 04 00 20 | [SET_PROPERTY - Group 40: FREQ_CONTROL](pkts/pkt76.md)         |

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

# Startup Process

- [Knowledge Article "Si4x6x, Si4x55 startup sequence"](https://community.silabs.com/s/article/si4x6x-c2a-si4x55-c2a-startup-sequence)


```
In the Si4x6x chips there is a timeout after POR built-in to make sure if there is no host activity (SPI comms), the chip would go back to inactive state saving energy.
Feb 2, 2022•Knowledge
Details

In the Si4x6x chips there is a timeout after POR built-in to make sure if there is no host activity (SPI comms), the chip would go back to inactive state saving energy. Inactive state is the state the chip is sitting in after POR.
Because of this time-out, some refinement is necessary on the recommended startup sequence of AN633, as follows:
 

    Assert SDN
    Wait at least 10µs
    Deassert SDN
    a) Wait at least 14ms or b) wait until GPIO1(CTS) goes HIGH
    Issue the POWER_UP command over SPI (or send first line of patch if applied)

This first SPI transaction has to finish in less than 4ms.
In case 4.a) it is counted from NSEL falling edge to NSEL rising edge.
In case 4.b) it is counted from GPIO1 rising edge to NSEL rising edge.
If it cannot be guaranteed, send a shorter command (e.g. NOP) first, check CTS, then send POWER_UP or patch.

This information applies to both the B and C revisions of Si4x6x and Si4x55, and to the Si106x, Si108x and EZR32 WMCUs. 
```

# Packet Decoding






  
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



