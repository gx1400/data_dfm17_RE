# Frequency Calculation

## Calculation

$RF_{Channel_{Hz}}=\left(fc_{inte}+\frac{fc_{frac}}{2^{19}}\right) \times \left(\frac{N_{PRESC} \times freq\_xo}{outdiv}\right)$

Whereas:
- FREQ_CONTROL_INTE: $fc_{inte}$ = 77
- FREQ_CONTROL_FRAC: $fc_{frac} = 589,824$
- N_PRESC: $N_{PRESC} = 2$
- FREQ_XO: $freq\_xo = 25,600,000$
- OUTDIV: $outdiv = 10$

$RF_{Channel_{Hz}}=400,000,000 Hz$

## Calculation Steps

1) $RF_{Channel_{Hz}}=\left(fc_{inte}+\frac{fc_{frac}}{2^{19}}\right) \times \left(\frac{N_{PRESC} \times freq\_xo}{outdiv}\right)$
2) $RF_{Channel_{Hz}}=\left(77+\frac{589,824}{2^{19}}\right) \times \left(\frac{2 \times 25,600,000}{10}\right)$
3) $RF_{Channel_{Hz}}=\left(77+{1.125}\right) \times \left(\frac{51,200,000}{10}\right)$
4) $RF_{Channel_{Hz}}=78.125 \times 5,120,000$
5) $RF_{Channel_{Hz}}=400,000,000 Hz = 400Mhz$


## Values
### FREQ_CONTROL_INTE Value


[Value in Packet 76](../pkts/pkt76.md#property-00---freq_control_inte)

```
PACKET      76
LENGTH:     0x 0B
DATA:       0x 11 40 07 00 4D 09 00 00 04 00 20
```

Byte #4 = 0x4D = 77

### FREQ_CONTROL_FRAC

```
PACKET:     76
LENGTH:     0x 0B
DATA:       0x 11 40 07 00 4D 09 00 00 04 00 20
```

Bytes #5-7 = 0x09 00 00 = 589,824

[Value in Packet 76](../pkts/pkt76.md#property-0103---freq_control_frac)

### N_PRESC

The prescaler divider value NPRESC is configured as a function of the selected synthesizer performance mode and may take on the values NPRESC=2 or NPRESC=4, as specified in property MODEM_CLKGEN_BAND:SY_SEL. This value is in Packet 72.

```
PACKET:     72
LENGTH:     0x 06
DATA:       0x 11 20 02 50 94 09
```
Byte #5 = 0x09 = 0b 0000 1001

N_Presc determined by SY_SEL which is bit 3: 0b1

SY_SEL = 0b1 = ENUM_1
- High Performance mode (fixed prescaler = Div-by-2).

*N_PRESC* = **2**

### OUTDIV

The output divider value OUTDIV is configured as a function of the desired frequency band, and is specified in property MODEM_CLKGEN_BAND:BAND. This value is in Packet 72.

```
PACKET:     72
LENGTH:     0x 06
DATA:       0x 11 20 02 50 94 09
```
Byte #5 = 0x09 = 0b 0000 1001

OUTDIV determined by BAND which is bit 2:0 : 0b001

BAND = 1

*\*NOTE* - API Documents show BAND 1 as BAND ENUM: FVCO_DIV_6, but outdiv is 10, confirmed in WDS3

*OUTDIV* = **10**