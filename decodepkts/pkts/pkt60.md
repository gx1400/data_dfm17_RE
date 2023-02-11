# Pkt 60 - SET_PROPERTY - GLOBAL_CONFIG (1 Property)

**Summary**
```
 Set properties:           RF_GLOBAL_CONFIG_1
 Number of properties:     1
 Group ID:                 0x00
 Start ID:                 0x03
 Default values:           0x20, 
 Descriptions:
   GLOBAL_CONFIG - Global configuration settings.
```

**Packet**
```
LENGTH:     0x 05
DATA:       0x 11 00 01 03 20
```


  
## Property 03 - GLOBAL_CONFIG

**Summary:**    Global configuration settings.

**Byte:**       0x 20 = 0b 0010 0000

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x03     | 5    | 0b1              | SEQUENCER_MODE   | 1 = FAST, Enter TX mode as quickly as possible after START_TX Cmd |
| 0x03     | 4    | 0b0              | FIFO_MODE        | 0 = SPLIT_FIFO, Tx & Rx FIFO are independent (not applicable for Si4063) |
| 0x03     | 3:1  | 0b000 = 0d       | PROTOCOL         | 0 = GENERIC packet format |
| 0x03     | 0    | 0b0              | POWER_MODE       | 0 = HIGH_PERF, high performance mode |