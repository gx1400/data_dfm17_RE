# Pkt 59 - SET_PROPERTY - GLOBAL (2 Properties)

**Summary:** 
```
Set properties:           RF_GLOBAL_XO_TUNE_2
Number of properties:     2
Group ID:                 0x00
Start ID:                 0x00
Default values:           0x40, 0x00, 
Descriptions:
  GLOBAL_XO_TUNE - Configure the internal capacitor frequency tuning bank for the crystal oscillator.
  GLOBAL_CLK_CFG - Clock configuration options.
```

**Packet**
```
LENGTH:     0x 06 
DATA:       0x 11 00 02 00 62 60
```

## Property 00 - GLOBAL_XO_TUNE

**Summary:**    Configure the internal capacitor frequency tuning bank for the crystal oscillator. 

**Byte:**       0x 62 = 0b 0110 0010

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x00     | 6:0  | 0b1100010 = 98d  | TUNE_VALUE       | 98d * 70e-15 pF = 6.86pF |

## Property 01 - GLOBAL_CLK_CFG

**Summary:**    Clock configuration options.

**Byte:**       0x 60 = 0b 0110 0000

| Property | Bits | Value            | Function         | Decode |
| -------: | ---: | ----:            | :-------         | :----- |
| 0x01     | 6    | 0b1              | DIVIDED_CLK_EN   | Divided system clock output is enabled |
| 0x01     | 5:3  | 0b100 = 4d       | DIVIDED_CLK_SEL  | 4d = DIV_10, Clock output is divided by 10 |
| 0x01     | 1:0  | 0b00 = 0d        | CLK_32K_SEL      | 0d = OFF, 32KHz clock is disabled. |