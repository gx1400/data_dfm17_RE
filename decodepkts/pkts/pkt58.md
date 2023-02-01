# Pkt 58 - GPIO_PIN_CFG

**Function:**   GPIO_PIN_CFG

**Summary:**    Configures the GPIO pins.


```
LENGTH:     0x 08
DATA:       0x 13 10 0F 07 04 00 0B 00
```

| Byte Index | Bits | Value         | Function         | Decode |
| ---------: | ---: | ----:         | :-------         | :----- |
| 0x00       | 7:0  | 0x13          | GPIO_PIN_CFG Cmd |        |
| 0x01       | 6    | 0b0           | GPIO0 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x01       | 5:0  | 0b10000 = 16d | GPIO0 MODE       | 16d = TX_DATA_CLK |
| 0x02       | 6    | 0b0           | GPIO1 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x02       | 5:0  | 0b01111 = 15d | GPIO1 MODE       | 15d = EN_PA |
| 0x03       | 6    | 0b0           | GPIO2 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x03       | 5:0  | 0b00111 = 7d  | GPIO2 MODE       | 7d = DIV_CLK  |
| 0x04       | 6    | 0b0           | GPIO3 PULL_CTL   | PULL_DIS, disable pull up resistor |
| 0x04       | 5:0  | 0b00100 = 4d  | GPIO2 MODE       | 4d = INPUT |
| 0x05       | 6    | 0b0           | NIRQ PULL_CTL    | PULL_DIS, disable pull up resistor |
| 0x05       | 5:0  | 0b00000 = 0d  | NIRQ_MODE        | DONOTHING |
| 0x06       | 6    | 0b0           | SDO PULL_CTL     | PULL_DIS, disable pull up resistor |
| 0x06       | 5:0  | 0x0B = 11d    | SDO_MODE         | 11d = SDO,  |
| 0x07       | 6:5  | 0b00 = 0d     | DRV_STRENGTH     | 0d = HIGH, GPIOs configured to have highest drive strength |

**GPIO0 Mode:** TX_DATA_CLK
- STM32 Pin: Not Connected?
- This signal is a square wave at the selected TX data rate, and is intended for use in TX Direct Synchronous Mode (i.e., in conjunction with a pin configured for TX Data Input).

**GPIO1 Mode:** EN_PA
- STM32 Pin: Not Connected, routes to PTH Test point directly above pin
- This output goes high when the internal PA is enabled.

**GPIO2 Mode:** DIV_CLK
- STM32 Pin: PD0
- Outputs the divided clock signal (or the divided boot clock signal in SPI ACTIVE state). 
- This output is low while the chip is in SLEEP state as the source (e.g., the Xtal Oscillator) for the divided clock signal is not running, and outputs the divided XtalOsc signal in all other states. 
- The divider is configured using the GLOBAL_CLK_CFG:DIVIDED_CLK_SEL

**GPIO3 Mode:** INPUT
- STM32 Pin: PA4
- Pin is configured as a CMOS input. This is used for all GPIO functions that require the pin to be an input (e.g., TXDATA input for TX Direct Mode). 
- However, configuration of this pin as an input does NOT additionally select which internal circuit receives that input; that functionality is controlled by other properties, as appropriate.

**NIRQ Mode:** DONOTHING
- STM Pin: Not connected
- Behavior of this pin is not modified

**SDO Mode:**: SDO
- STM32 Pin: PA6
- Outputs serial data out signal for SPI bus