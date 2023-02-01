# Pkt 65 - SET_PROPERTY - MODEM (1 Property)

```
LENGTH:     0x 05
DATA:       0x 11 20 01 0C 33
```
- Group:            20  MODEM
- Property Count:   01
  - Property:       0C  MODEM_FREQ_DEV [0]*

*\*Note - 0C is bottom words of MODEM_FREQ_DEV.  [Pkt 64](pkt64.md) has first and second word.*

| Property | Bits | Value            | Function       | Decode   |
| -------: | ---: | ----:            | :-------       | :-----   |
| 0x0A\*   | 0    | 0b0              | FREQDEV[16:16] | |
| 0x0B\*   | 7:0  | 0x 01            | FREQDEV[15:8]  | |
| 0x0C     | 7:0  | 0x 33            | FREQDEV[7:0]   | |

0x 00 01 33 = 307d

$MODEM\_FREQ\_DEV=\left(\frac{2^{19} \times outdiv \times Desired\_Dev\_Hz}{N_{PRESC} \times freq\_xo}\right)$

Whereas:
- $outdiv = 10$
- $Desired\_Dev\_Hz = 307$
- $N_{PRESC} = 2$
- $freq\_xo = 25,600,600$

$MODEM\_FREQ\_DEV = 3.14 Hz??$
