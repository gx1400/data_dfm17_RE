# Si4063 signal capture notes

## Reference

[Application Note AN633: PROGRAMMING GUIDE FOR EZRADIOPRO® Si4X6X DEVICES](../../docs/AN633.pdf)

## Capture method

Saleae Logic Pro 8 using Logic 2 software.

<img src="imgs/pcbbite.jpg" height="400">

PCBite probes on STM pins for Si4063 SPI:
- PB2 = CS/nSEL
- PA7 = SDI
- PA6 = SDO
- PA5 = SCLK

## Startup Capture

### Wait for CTS 

On power up, the MCU should sent the READ_BUFF_CMD (0x44) until the Si4063 sents back a CTS signal (0xFF).

![READ_CMD_BUFF excerpt from AN633](imgs/READ_CMD_BUFF.png)

From AN633 Section 7.2 pg 15:

![AN633 Section 7.2 excerpt](imgs/CTS.png)

The next image shows the MCU sending READ_CMD_BUFF commands to the Si4063, but NOT receiving the CTS response.

![MCU sending READ_CMD_BUFF but not receiving CTS](imgs/start_notcts.png)

In the Logic 2 capture file ["SI4063_startup1.sal"](SI4063_startup1.sal), the CTS signal is not received until transmit attempt #16 shown below.

![MCU sending READ_CMD_BUFF but receiving CTS](imgs/start_cts.png)