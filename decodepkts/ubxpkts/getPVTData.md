
```
Message:        UBX-NAV-PVT
Description:    Navigation position velocity time solution
Manual:         Section 32.17.17.1, Pg 375
```

```
static const uint8_t getPVTData[]={
    // HEADER
    0xB5,0x62,  // SYNC CHARS
    0x01,       // Class    UBX-NAV
    0x07,       // ID       UBX-NAV-PVT
    0x00,0x00,  // Length = 0d (little endian)
    
    // CHECKSUM
    0x08,0x19
};
```