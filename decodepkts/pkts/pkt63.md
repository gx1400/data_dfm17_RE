# Pkt 63 - SET_PROPERTY - PREAMBLE (1 Property)

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