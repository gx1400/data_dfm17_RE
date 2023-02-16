
```
Message:        UBX-NAV-POSECEF
Description:    Position Solution in ECEF
Manual:         Section 32.17.15.1, Pg 374
```

```
static const uint8_t getPOSLLHData[]={
    //HEADER
    0xB5,0x62,  // SYNC CHARS
    0x01,       // Class    UBX-NAV
    0x02,       // ID       UBX-NAV-POSECEF
    0x00,0x00,  // Length = 0d (little endian)
    
    // CHECKSUM
    0x03,0x0A
};
```