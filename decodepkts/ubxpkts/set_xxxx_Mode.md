
```
Message:        UBX-CFG-NAV5
Description:    Navigation Engine settings
Manual:         Section 32.10.19.1
```

```
static const uint8_t setStationaryMode[]={
    // HEADER
    0xB5,0x62,  // SYNC CHARS
    0x06,       // Class    UBX-CFG
    0x24,       // ID       UBX-CFG-NAV5
    0x24,0x00,  // Length = 36
    
    // PAYLOAD
    0xFF,0xFF,                  // Offset 00: mask
    0x02,                       // Offset 02: dynMode1 = Stationary
    0x03,                       // Offset 03: fixMode = auto 2D/3D
    0x00,0x00,0x00,0x00,        // Offset 04: fixedAlt (for 2D fix mode) = 0m
    0x10,0x27,0x00,0x00,        // Offset 08: fixedAltVar (for 2D fix mode) 
    0x05,                       // Offset 12: minElev = 5deg
    0x00,                       // Offset 13: drLimit (Reserved)
    0xFA,0x00,                  // Offset 14: pDop (Position DOP mask)
    0xFA,0x00,                  // Offset 16: tDop (Time DOP mask)
    0x64,0x00,                  // Offset 18: pAcc (Position accuracy mask)
    0x5E,0x01,                  // Offset 20: tAcc (Time accuracy mask)
    0x00,                       // Offset 22: staticHoldThresh (Static hold threshold)
    0x3C,                       // Offset 23: dgnssTimeout = 60sec
    0x00,                       // Offset 24: cnoThreshNumSVs
    0x00,                       // Offset 25: cnoThresh
    0x00,0x00,                  // Offset 26: reserved1
    0x00,0x00,                  // Offset 28: staticHoldMaxDist
    0x00,                       // Offset 30: utcStandard = Automatic
    0x00,0x00,0x00,0x00,0x00,   // Offset 31: reserved
    
    // CHECKSUM
    0x7E,0x3C

};
```

*\*Note* - The following functions all use the same payload except for the Offset 02 dynMode1 setting (and checksum): 
```
- setPortableMode[]     :   dynMode = 0x00
- setStationaryMode[]   :   dynMode = 0x02
- setPedestrianMode[]   :   dynMode = 0x03
- setAutomotiveMode[]   :   dynMode = 0x04
- setAirbone1GMode[]    :   dynMode = 0x06
- setAirbone2GMode[]    :   dynMode = 0x07
- setAirbone4GMode[]    :   dynMode = 0x08
- setWirstMode[]        :   dynMode = 0x09
- setBikeMode[]         :   dynMode = 0x0A
```