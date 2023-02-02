# Pkt 66 - SET_PROPERTY - MODEM (12 Properties)

```
LENGTH:     0x 10
DATA:       0x 11 20 0C 18 01 80 08 03 60 00 70 20 0C E8 01 40
```
- Group:            20  MODEM
- Property Count:   0C
  - Property:       18      MODEM_TX_RAMP_DELAY
  - Property:       19      MODEM_MDM_CTRL
  - Property:       1A      MODEM_IF_CONTROL
  - Property:       1B:1D   MODEM_IF_FREQ
  - Property:       1E      MODEM_DECIMATION_CFG1
  - Property:       1F      MODEM_DECIMATION_CFG0
  - Property:       20      MODEM_RESERVED_20_20
  - Property:       21      MODEM_RESERVED_20_21
  - Property:       22:23   MODEM_BCR_OSR

## Property 18 - MODEM_TX_RAMP_DELAY

**Summary:**    TX ramp-down delay setting.

**Byte:**       0x 01 = 0b 0000 0001

```
This property specifies the delay time between transmission of the final symbol of a 2(G)FSK or 4(G)FSK packet and the start of the ramp-down of the PA output power. This configurable delay time ensures that all symbols have been fully transmitted before any reduction in output power occurs
```


| Property | Bits | Value      | Function                | Decode   |
| -------: | ---: | ----:      | :-------                | :-----   |
| 0x18     | 2:0  | 0b001 = 1d | RAMP_DLY                |          |

*\*Note - Documentation suggests WDS Calculator will suggest an appropriate delay value based on modulation type and data rate*

- Min 0x1
- Max 0x7

## Property 19 - MODEM_MDM_CTRL

**Summary:**    MDM Control. Detector selection and PM pattern configuration.

**Byte:**       0x 80  = 0b 1000 0000

| Property | Bits | Value      | Function                | Decode   |
| -------: | ---: | ----:      | :-------                | :-----   |
| 0x19     | 7    | 0b1 = 1d   | PH_SRC_SEL              | ENUM_1 - BCR/Slicer phase source = detector output |
| 0x19     | 0    | 0b0 = 0d   | FIFO_SRC_SEL            | 0 = PH, FIFO contents come from packet handler |

## Property 1A - MODEM_IF_CONTROL

**Summary:**     Selects Fixed-IF, Scaled-IF, or Zero-IF mode of RX modem operation

**Byte:**        0x 08 = 0b 0000 1000

| Property | Bits | Value      | Function                | Decode   |
| -------: | ---: | ----:      | :-------                | :-----   |
| 0x1A     | 4    | 0b0 = 0d   | ZEROIF                  | 0 = NORMAL, non zero-IF mode |
| 0x1A     | 3    | 0b1 = 1d   | FIXIF                   | 1 = FIXED, Fixed-IF mode |
| 0x1A     | 1:0  | 0b00 = 0d  | ETSI_MODE               | 0 = DISABLE, ETSI disabled |

## Property 1B:1D - MODEM_IF_FREQ

**Summary:**    IF Frequency setting (18-bit signed number)

**Byte:**       0x 03 60 00

| Property | Bits | Value      | Function                | Decode   |
| -------: | ---: | ----:      | :-------                | :-----   |
| 0x1B     | 1:0  | 0b11       | IF_FREQ[17:16]          |          | 
| 0x1C     | 7:0  | 0x60       | IF_FREQ[15:8]           |          |
| 0x1D     | 7:0  | 0x00       | IF_FREQ[7:0]            |          |

0x 03 60 00 = 221,184d

$IF\_FREQ\_Hz = (\frac{freq\_xo}{64\times{N}})$

Whereas:
- $freq\_xo = 25,600,000 Hz$
- N = 1 because in Fixed-IF mode

$IF\_FREQ\_Hz = 400,000 Hz$

$MODEM\_IF\_FREQ = (\frac{2^{19}\times{outdiv}\times{IF\_FREQ\_HZ}}{Npresc\times{freq\_xo}})$

## Property 1E - MODEM_DECIMATION_CFG1

**Summary:**    Specifies three decimator ratios for the Cascaded Integrator Comb (CIC) filter.

**Byte:**       0x 70 = 0b 0111 0000

| Property | Bits | Value      | Function                | Decode   |
| -------: | ---: | ----:      | :-------                | :-----   |
| 0x1E     | 7:6  | 0b01 = 1d  | NDEC2                   | 1 = ENUM_1, decimate by 2 |
| 0x1E     | 5:4  | 0b11 = 3d  | NDEC1                   | 2 = ENUM_3, decimate by 8 |
| 0x1E     | 3:1  | 0b000 = 0d | NDEC0                   | 0 = ENUM_0, decimate by 1 |

- NDEC2
   - Decimation coefficient for the second of two cascaded decimation circuit blocks in the CIC filter.
   - Decimating rate is 2^NDEC2
- NDEC1
   -  Decimation coefficient for the first of two cascading decimation circuit blocks in the CIC filter.
    - Decimating rate is 2^NDEC1
- NEC0
    - Decimation coefficient for the additional decimation circuit block used in the RX Modem during OOK reception.
    - Decimating rate is 2^NDEC0
    - NDEC0 should be set to 0 when not in OOK mode. 

## Property 1F - MODEM_DECIMATION_CFG0

**Summary:**    Specifies miscellaneous parameters and decimator ratios for the Cascading Integrator Comb (CIC) filter.

**Byte:**       0x 20 = 0b 0010 0000

| Property | Bits | Value      | Function                | Decode   |
| -------: | ---: | ----:      | :-------                | :-----   |
| 0x1F     | 7    | 0b0        | CHFLT_LOPW              | 0 = Normal mode, 27 tap filer |
| 0x1F     | 6    | 0b0        | DROOPFLTBYP             | 0 = Enabled droop compensation filter |
| 0x1F     | 5    | 0b1        | DWN3BYP                 | 1 = Bypass the decimate-by-3 polyphase filter |
| 0x1F     | 4    | 0b0        | DWN2BYP                 | 0 = Bypass the decimate-by-2 polyphase filter |
| 0x1F     | 0    | 0b0        | RXGAINX2                | 0 = Normal decimate-by-8 filter gain |

## Property 20 - MODEM_RESERVED_20_20

**Summary:**    Reserved

**Byte:**       0x 0C

## Property 21 - MODEM_RESERVED_20_21

**Summary:**    Reserved

**Byte:**       0x E8


## Property 22:23 - MODEM_BCR_OSR

**Summary:**    RX BCR/Slicer oversampling rate (12-bit unsigned number).

**Byte:**       0x 01 40 = 0b 0000 0001 0100 0000

| Property | Bits | Value       | Function                | Decode   |
| -------: | ---: | ----:       | :-------                | :-----   |
| 0x22     | 3:0  | 0b0001 = 1d | RXOSR[11:8]             |          |
| 0x23     | 7:0  | 0x40        | RXOSR[7:0]              |          | 

0x 01 40 = 320d