
```
Message:        UBX-CFG-PRT
Description:    Port configuration for UART ports
Manual:         Section 32.10.25.2, Pg 243
```

```c
static const uint8_t configUBX[]={
    // HEADER
    0xB5,0x62,  // SYNC CHARS
    0x06,       // Class    UBX-CFG
    0x00,       // ID       UBX-CFG-PRT
    0x14, 0x00, // Length = 20d (little endian)

    // PAYLOAD        
    0x01,                   // Offset 00: portID = 1
    0x00,                   // Offset 01: reserved1 = always 0x00
    0x00,0x00,              // Offset 02: txReady
    0xD0,0x08,0x00,0x00,    // Offset 04: mode
    0x80,0x25,0x00,0x00,    // Offset 08: baudrate in Bits/s = 0x2580 = 9600
    0x01,0x00,              // Offset 12: inProtoMask = inUbx
    0x01,0x00,              // Offset 14: outProtoMask = outUbx 
    0x00,0x00,              // Offset 16: flags
    0x00,0x00,              // Offset 18: reserved2 = always 0x0000
    
    // CHECKSUM
    0x9A,0x79
};
```