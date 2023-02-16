
```
Message:        UBX-SEC-UNIQID
Description:    This message is used to retrieve a unique chip identifier (40 bits, 5 bytes).
Manual:         Section 32.19.1.1, Pg 423
```

```
static const uint8_t getDeviceID[]={
    // HEADER
    0xB5,0x62,  // SYNC CHARS
    0x27,       // Class    UBX-SEC-
    0x03,       // ID       UBX-SEC-UNIQID
    0x00,0x00,  // Length = 0d (little endian)
    
    // CHECKSUM
    0x2A,0xA5
};
```