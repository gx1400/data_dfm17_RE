# Si4063 Packet Decoding Notes

# Reference

- [Application Note AN633: PROGRAMMING GUIDE FOR EZRADIOPRO® Si4X6X DEVICES](../docs/AN633.pdf)
- [API documentation (zip file)](../docs/EZRadioPRO_REVC2_API.zip)
- [Errata with PATCH information](../docs/ezradio-ezradiopro-c2a-a2a-errata.pdf)

# Calcuations

- [Frequency Calculation](calculations/freq.md)

#  Packets from Firmware

## PATCH DATA Packets

- See [Errata with PATCH information](../docs/ezradio-ezradiopro-c2a-a2a-errata.pdf) for more info on patch
- [Silicon Labs Knowledge Article "Latest patch for  EZRadio/PRO and do I need to use it?"](https://community.silabs.com/s/article/latest-patch-for-ezradio-pro-and-do-i-need-to-use-it-x?language=en_US) - [PDF Print of page](patchfile/patchfile_helppage.pdf)
- [Latest Patchfile](patchfile/fw_6_0_2_4668.csg)

[Click here to see Packets 01-56 with PATCH_IMAGE, PATCH_ARGS, & PATCH_DATA](patchfile/patchfromfw.md)


## RADIO CONFIGURATION Packets

| Packet Number | FW Address | Bytes | Transmit Data (HEX) | Command Type |
| :-----------: | :--------- | ----: | :------------------ | :----------- |
| 57 | 0x0000a20a | 07 | 02 81 01 01 86 A0 00    | [RF_POWER_UP](pkts/pkt57.md)     |
| 58 | 0x0000a212 | 08 | 13 10 0F 07 04 00 0B 00 | [RF_GPIO_PIN_CFG](pkts/pkt58.md) |
| 59 | 0x0000a21b | 06 | 11 00 02 00 62 60       | [RF_GLOBAL_XO_TUNE_2](pkts/pkt59.md)       |
| 60 | 0x0000a222 | 05 | 11 00 01 03 20          | [RF_GLOBAL_CONFIG_1](pkts/pkt60.md)       |
| 61 | 0x0000a228 | 05 | 11 01 01 00 00          | [RF_INT_CTL_ENABLE_1](pkts/pkt61.md)      |
| 62 | 0x0000a22e | 08 | 11 02 04 00 00 00 00 00 | [RF_FRR_CTL_A_MODE_4](pkts/pkt62.md)      |
| 63 | 0x0000a237 | 05 | 11 10 01 04 21          | [RF_PREAMBLE_CONFIG_1](pkts/pkt63.md)     |
| 64 | 0x0000a23d | 10 | 11 20 0C 00 6B 00 07 01 86 A0 05 86 A0 00 00 01 | [RF_MODEM_MOD_TYPE_12](pkts/pkt64.md) |
| 65 | 0x0000a24e | 05 | 11 20 01 0C 33          | [RF_MODEM_FREQ_DEV_0_1](pkts/pkt65.md)                         |
| 66 | 0x0000a254 | 10 | 11 20 0C 18 01 80 08 03 60 00 70 20 0C E8 01 40 | [RF_MODEM_TX_RAMP_DELAY_12](pkts/pkt66.md) |
| 67 | 0x0000a265 | 10 | 11 20 0C 24 01 99 9A 00 CD 00 C2 00 54 62 80 6B | [RF_MODEM_BCR_NCO_OFFSET_2_12](pkts/pkt67.md) |
| 68 | 0x0000a276 | 07 | 11 20 03 30 01 E5 80    | [RF_MODEM_AFC_LIMITER_1_3](pkts/pkt68.md)                        |
| 69 | 0x0000a27e | 05 | 11 20 01 35 E0          | [RF_MODEM_AGC_CONTROL_1](pkts/pkt69.md)                         |
| 70 | 0x0000a284 | 10 | 11 20 0C 38 11 46 46 80 1A 99 9A 00 2A 0C 84 23 | [RF_MODEM_AGC_WINDOW_SIZE_12](/pkts/pkt70.md) |
| 71 | 0x0000a295 | 07 | 11 20 03 45 8F 00 9C    | [RF_MODEM_RAW_CONTROL_3](pkts/pkt71.md)                         |
| 72 | 0x0000a29d | 06 | 11 20 02 50 94 09       | [RF_MODEM_RAW_SEARCH2_2](pkts/pkt72.md)                         |
| 73 | 0x0000a2a4 | 05 | 11 20 01 54 03          | [RF_MODEM_SPIKE_DET_1](pkts/pkt73.md)                         |
| 74 | 0x0000a2aa | 08 | 11 22 04 00 08 7F 00 1F | [RF_PA_MODE_4](pkts/pkt74.md)                         |
| 75 | 0x0000a2b3 | 0B | 11 23 07 00 2C 0E 0B 04 0C 73 03 | [RF_SYNTH_PFDCP_CPFF_7](pkts/pkt75.md)                |
| 76 | 0x0000a2bf | 0B | 11 40 07 00 4D 09 00 00 04 00 20 | [RF_FREQ_CONTROL_INTE_7](pkts/pkt76.md)         |

## Additional Setup Packets

Note the response packets below do not have including the "0xFF 0xxFF" response to the "0x44" READ_CMD_BUFF.

| Packet Number | Bytes | Command/Response | Data (HEX) | Command Type |
| :-----------: | ----: | :----------- | :--------- | :----------- |
| 77            | 01    | Command      | 33         | REQUEST_DEVICE_STATE |
| 78            | 02    | Response     | 03 00      | state READY | 
| 79            | 02    | Command      | 34 03      | CHANGE_STATE to READY |
| 80            | 0B    | Command      | 11 40 04 00 4D 05 B4 00 04 00 20 | SET_PROPERTY FREQ_CONTROL |
| 81            | 06    | Command      | 11 20 02 0D 00 00 | SET_PROPERTY MODEM_DSM_CTRL? |
| 82            | 06    | Command      | 11 20 02 0B 01 33 | SET_PROPERTY MODEM_DSM_CTRL? |
| 83            | 02    | Command      | 34 07      | CHANGE_STATE to TX |
| 84            | 01    | Command      | 33         | REQUEST_DEVICE_STATE |
| 85            | 02    | Response     | 07 00      | state TX |
| 86            | 02    | Command      | 34 03      | CHANGE_STATE to READY |
| 87            | 0B    | Command      | 11 40 04 00 4D 05 B4 00 04 00 20 | SET_PROPERTY FREQ_CONTROL |
| 88            | 02    | Command      | 34 07      | CHANGE_STATE to TX |
| 92            | 0B    | Command      | 11 40 04 00 4D 05 B4 00 04 00 20 | SET_PROPERTY FREQ_CONTROL |

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