# Frequency Calculation

$RF_{Channel_{Hz}}=\left(fc_{inte}+\frac{fc_{frac}}{2^{19}}\right) \times \left(\frac{N_{PRESC} \times freq\_xo}{outdiv}\right)$

Whereas:
- [$fc_{inte} = 77$](../pkts/pkt76.md#property-00---freq_control_inte)
- $fc_{frac} = 589,824$
- $N_{PRESC} = 2$
- $freq\_xo = 25,600,000$
- $outdiv = 10$

$RF_{Channel_{Hz}}=400,000,000 Hz$