
```
Message:        UBX-CFG-GNSS
Description:    Gets or sets the GNSS system channel sharing configuration.
Manual:         Section 32.10.13.1, Pg 207
```

```
static const uint8_t setGNSS[]={
    // HEADER
    0xB5,0x62,      // SYNC CHARS
    0x06,           // Class    UBX-CFG
    0x3E,           // ID       UBX-CFG-GNSS
    0x24,0x00,      // Length = 36d (little endian)

    // PAYLOAD
    0x00,                   // Offset 00: msgVer, always 0x00
    0x00,                   // Offset 01: numTrkChHw (read only)
    0x20,                   // Offset 02: numTrkChUse, = 32d Number of tracking channels to use
    0x04,                   // Offset 03: numConfigBlocks = 4

    // CONFIG BLOCK 1
    0x00,                   // OFFSET 04 + 8*0 = 04: gnssId = GPS
    0x08,                   // OFFSET 05 + 8*0 = 05: resTrkCh
    0x10,                   // OFFSET 06 + 8*0 = 06: maxTrkCh
    0x00,                   // OFFSET 07 + 8*0 = 07: reserved1
    0x01,0x00,0x01,0x01,    // OFFSET 08 + 8*0 = 08: flags, enable GPS
    
    // CONFIG BLOCK 2
    0x01,                   // OFFSET 04 + 8*1 = 12: gnssId = SBAS
    0x01,                   // OFFSET 05 + 8*1 = 13: resTrkCh
    0x03,                   // OFFSET 06 + 8*1 = 14: maxTrkCh
    0x00,                   // OFFSET 07 + 8*1 = 15: reserved1
    0x01,0x00,0x01,0x01,    // OFFSET 08 + 8*1 = 16: flags, enable SBAS
    
    // CONFIG BLOCK 3
    0x02,                   // OFFSET 04 + 8*2 = 20: gnssId = Galileo
    0x04,                   // OFFSET 05 + 8*2 = 21: resTrkCh
    0x08,                   // OFFSET 06 + 8*2 = 22: maxTrkCh
    0x00,                   // OFFSET 07 + 8*2 = 23: reserved1
    0x01,0x00,0x01,0x01,    // OFFSET 08 + 8*0 = 24: flags, enable Galileo
    
    // CONFIG BLOCK 4
    0x06,                   // OFFSET 04 + 8*3 = 28: gnssId = GLONASS
    0x08,                   // OFFSET 05 + 8*3 = 29: resTrkCh
    0x0E,                   // OFFSET 06 + 8*3 = 30: maxTrkCh
    0x00,                   // OFFSET 07 + 8*3 = 31: reserved1
    0x01,0x00,0x01,0x01,    // OFFSET 08 + 8*3 = 32: flags, enable GLONAS

    // CHECKSUM
    0xDF,0xFB};

```