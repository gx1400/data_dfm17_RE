# Pkt 65 - SET_PROPERTY - MODEM (1 Property)

**Summary**
```
Set properties:           RF_MODEM_FREQ_DEV_0_1
Number of properties:     1
Group ID:                 0x20
Start ID:                 0x0C
Default values:           0xD3, 
Descriptions:
  MODEM_FREQ_DEV_0 - 17-bit unsigned TX frequency deviation word.
```
*\*Note - 0C is bottom words of MODEM_FREQ_DEV.  [Pkt 64](pkt64.md) has first and second word.*

**Packet**
```
LENGTH:     0x 05
DATA:       0x 11 20 01 0C 33
```


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
