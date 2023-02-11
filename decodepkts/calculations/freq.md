# Frequency Calculation

## Default Setup

$RF_{Channel_{Hz}}=\left(fc_{inte}+\frac{fc_{frac}}{2^{19}}\right) \times \left(\frac{N_{PRESC} \times freq\_xo}{outdiv}\right)$

Whereas:
- FREQ_CONTROL_INTE: $fc_{inte}$ = 77
- $fc_{frac} = 589,824$
- $N_{PRESC} = 2$
- $freq\_xo = 25,600,000$
- $outdiv = 10$

$RF_{Channel_{Hz}}=400,000,000 Hz$

### FREQ_CONTROL_INTE Value


[Value in Packet 76](../pkts/pkt76.md#property-00---freq_control_inte)

```
LENGTH:     0x 0B
DATA:       0x 11 40 07 00 4D 09 00 00 04 00 20
```

Byte #4 = 0x4D = 77