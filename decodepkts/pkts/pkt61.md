# Pkt 61 - RF_INT_CTL_ENABLE_1

**Summary**
```
Set properties:           RF_INT_CTL_ENABLE_1
Number of properties:     1
Group ID:                 0x01
Start ID:                 0x00
Default values:           0x04, 
Descriptions:
  INT_CTL_ENABLE - This property provides for global enabling of the three interrupt groups (Chip, Modem and Packet Handler) in order to generate HW interrupts at the NIRQ pin.
```

**Packet**
```
LENGTH:     0x 05
DATA:       0x 11 01 01 00 00
```
- Group:            01  INT_CTL
- Property Count:   01
  - Property:       01  INT_CTL_PH_ENABLE


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