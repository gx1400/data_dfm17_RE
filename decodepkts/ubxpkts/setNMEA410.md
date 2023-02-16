
```
Message:        UBX-CFG-NMEA
Description:    Extended NMEA protocol configuration V1
Manual:         Section 32.10.21.3, Pg 231
```

```
static const uint8_t setNMEA410[]={
    // HEADER
    0xB5,0x62,  // SYNC CHARS
    0x06,       // Class    UBX-CFG
    0x17,       // ID       UBX-CFG-NMEA
    0x14,0x00,  // Length = 20d (little endian)
    
    // PAYLOAD
    0x00,                   // Offset 00: filter = no filters
    0x41,                   // Offset 01: nmeaVersion = NMEA version 4.10
    0x00,                   // Offset 02: numSV = unlimited SVs per TalkerId
    0x02,                   // Offset 03: flags = enable considering mode
    0x00,0x00,0x00,0x00,    // Offset 04: gnssToFilter = no disabled sats
    0x00,                   // Offset 08: svNumbering = Do not show sats without NMEA id
    0x00,                   // Offset 09: mainTalkerId = no Main talkerId override
    0x00,                   // Offset 10: gsvTalkerId = use GNSS-specific talkerId
    0x01,                   // Offset 11: version = always 0x01
    0x00,0x00,              // Offset 12: bdsTalkerId = use default BeiDou Talker Id
    0x00,0x00,0x00,0x00,0x00,0x00,  // Offset 14: Reserved = always all 0x00
    
    // CHECKSUM
    0x75,0x57
};
```