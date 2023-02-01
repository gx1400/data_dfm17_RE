# Pkt 57 - POWER_UP

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