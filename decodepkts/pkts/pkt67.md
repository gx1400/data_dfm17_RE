# Pkt 67 - SET_PROPERTY - MODEM (12 Properties)

```
LENGTH:     0x 10
DATA:       0x 11 20 0C 24 01 99 9A 00 CD 00 C2 00 54 62 80 6B
```
- Group:            20  MODEM
- Property Count:   0C
  - Property:       24:26   MODEM_BCR_NCO_OFFSET  
  - Property:       27:28   MODEM_BCR_GAIN  
  - Property:       29      MODEM_BCR_GEAR
  - Property:       2A      MODEM_BCR_MISC1
  - Property:       2B      MODEM_BCR_MISC0
  - Property:       2C      MODEM_AFC_GEAR
  - Property:       2D      MODEM_AFC_WAIT
  - Property:       2E:2F   MODEM_AFC_GAIN

## Property 24:26 - MODEM_BCR_NC0_OFFSET

**Summary:**    RX BCR NCO offset value (an unsigned 22-bit number).

**Bytes:**      0x 01 99 9A

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x24     | 5:0  | 0b00001          | NCOFF[21:16] | |
| 0x25     | 7:0  | 0x99             | NCOFF[15:8]  | | 
| 0x26     | 7:0  | 0x9A             | NCOFF[7:0]   | |

0x 01 99 9A = 104,858d


## Property 27:28 - MODEM_BCR_GAIN

**Summary:**    

**Bytes:**      0x 00 CD

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x27     | 2:0  | 0b000            | CRGAIN[10:8]            |          | 
| 0x28     | 7:0  | 0xCD             | CRGAIN[7:0]             |          | 

0x 00 CD = 205d

## Property 29 - MODEM_BCR_GEAR

**Summary:**    RX BCR Loop gear control

**Byte:**       0x 00

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x29     | 5:3  | 0b000            | CRFAST                  |          |
| 0x29     | 2:0  | 0b000            | CRSLOW                  |          | 

## Property 2A - MODEM_BCR_MISC1

**Summary:**    Miscellaneous control bits for the RX BCR loop.

**Byte:**       0x C2 = 0b 1100 0010

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x2A     | 7    | 0b1              | BCRFBBYP                | Disabled, Feedback to BCR tracking loop is bypassed |
| 0x2A     | 6    | 0b1              | SLICEFBBYP              | Disabled, feedback of the compensation term to the slicer is bypassed |
| 0x2A     | 4    | 0b0              | RXNCOCOMP               | Disabled, compensation of the BCR NC0 freq is disabled |
| 0x2A     | 3    | 0b0              | RXCOMP_LAT              | BCR NCO compensation is sampled upon detection of the end of the Preamble (i.e., boundary between Preamble and Sync Word) |
| 0x2A     | 2    | 0b0              | CRGAINX2                | BCR Loop gain is not doubled |
| 0x2A     | 1    | 0b0              | DIS_MIDPT               | Correction of a BCR mid-point phase sampling condition by resetting the NCO is enabled (normal operation). |
| 0x2A     | 0    | 0b0              | ESC_MIDPT               | Upon detection of a BCR mid-point phase sampling condition, the NCO will stop running for one sample clock to escape. |

## Property 2B - MODEM_BCR_MISC2

**Summary:**    Miscellaneous RX BCR loop controls.

**Byte:**       0x 00

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x2B     | 7    | 0b0              | ADCWATCH                | ADC Watch dog is disabled |
| 0x2B     | 6    | 0b0              | ADCRST                  | ADC Watch dog is disabled, no reset |
| 0x2B     | 5    | 0b0              | DISTOGG                 | Normal, no discriminator output toggle |
| 0x2B     | 4    | 0b0              | PH0SIZE                 | 5 consec zeros in phase differential output will reset RX machine |
| 0x2B     | 3    | 0b0              | RES_LOCKUP_BYP          | Disable lockup detect |
| 0x2B     | 0    | 0b0              | DSA_BCR_RST             | Disable BCR reset from phase difference zero checking block |

## Property 2C - MODEM_AFC_GEAR

**Summary:**    RX AFC loop gear control.

**Byte:**       0x 54 = 0b 0101 0100

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x2C     | 7:6  | 0b01 = 1d        | GEAR_SW                 | Sync word detection |
| 0x2C     | 5:3  | 0b010 = 2d       | AFC_FAST                | AFC Fast gain | 
| 0x2C     | 2:0  | 0b100 = 4d       | AFC_SLOW                | AFC Slow gain |


## Property 2D - MODEM_AFC_WAIT

**Summary:**    RX AFC loop wait time control.

**Byte:**       0x 62

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x2D     | 7:4  | 0b0110 = 6d      | SHWAIT                  | Short wait period |
| 0x2D     | 3:0  | 0b0010 = 2d      | LGWAIT                  | Long wait period  | 

## Property 2E:2F - MODEM_AFC_GAIN

**Summary**     Sets the gain of the PLL-based AFC acquisition loop, and provides miscellaneous control bits for AFC functionality.

**Byte:**       0x 80 6B = 0b 1000 0000 0110 1011

| Property | Bits | Value            | Function                | Decode   |
| -------: | ---: | ----:            | :-------                | :-----   |
| 0x2E     | 7    | 0b1              | ENAFC                   | 1 = Enable estimation of freq. error |
| 0x2E     | 6    | 0b0              | AFCBC                   | 0 = Adaptive RX bandwidth disabled   | 
| 0x2E     | 5    | 0b0              | AFC_GAIN_DIV            | 0 = AFC gain not reduced by half     | 
| 0x2E     | 4:0  | 0b00000          | AFC_GAIN[12:8]          |          | 
| 0x2E     | 7:0  | 0x6B             | AFC_GAIN[7:0]           |          | 

AFC_Gain = 0x 00 6B = 107d