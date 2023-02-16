
```
Message:        UBX-NAV-TIMEUTC
Description:    UTC time solution
Manual:         Section 32.17.32.1, Pg 400
```

```
static const uint8_t getNavigatorData[]={
    // HEADER
    0xB5,0x62,  // SYNC CHARS
    0x01,       // Class    UBX-NAV
    0x21,       // ID       UBX-NAV-TIMEUTC
    0x00,0x00,  // Length = 0d (little endian)
    
    // CHECKSUM
    0x22,0x67
};
```