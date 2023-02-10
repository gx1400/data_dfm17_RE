#include <SPI.h>

// LED pins
#define LED_GREEN PC_6
#define LED_RED PB12
#define LED_YELLOW PC_7

// Si4063 pins
#define spiCS PB2     // Chip select - LOW to enable target
#define siSDN PC_3    // Shutdown - HIGH for low power mode
#define spiMOSI PA7   // Data input for Si4063, MOSI
#define spiMISO PA6   // Data output for Si4063, MISO
#define spiSCLK PA5   // SPI Clock
#define spiGPIO3 PA4

// Battery Management PON
#define battPON PC_0

bool bootFail = false;


//                      RX    TX
HardwareSerial SerialUSB(PA10, PA9);
HardwareSerial SerialGPS(PA3, PA2);


void setup() {
  //Setup BMS PON pin
  pinMode(battPON, OUTPUT);
  digitalWrite(battPON, HIGH);

  // Setup LED pins
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);

  // Setup Si4063 pins
  pinMode(siSDN, OUTPUT);
  pinMode(spiCS, OUTPUT);
  pinMode(spiGPIO3, OUTPUT);
  
  //reset radio on startup
  deassertRadioShutdown();
  delay(10);
  assertRadioShutdown();
  delay(10);

  SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));

  // Setup USB UART
  SerialUSB.begin(9600);
  SerialUSB.println("Starting UART...");

  // Boot radio
  deassertRadioShutdown();
  delayMicroseconds(200);

  // wait for CTS, if no CTS then abort
  if(!waitForCTS()) {
    setSetupError();
    return;
  } 

  sendPatches();

  powerUp();

  // Set configs
  // Pin CFG
  xmitCmd(0x13, 0x10, 0x0F, 0x07, 0x04, 0x00, 0x0B, 0x00);
  // SET_PROPERTY - Group 00: GLOBAL
  xmitCmd(0x11, 0x00, 0x02, 0x00, 0x62, 0x60);
  xmitCmd(0x11, 0x00, 0x01, 0x03, 0x20);
  // SET_PROPERTY - Group 01: INT_CTL
  xmitCmd(0x11, 0x01, 0x01, 0x00, 0x00);
  // SET_PROPERTY - Group 02: FRR_CTL
  xmitCmd(0x11, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00);
  // SET_PROPERTY - Group 10: PREAMBLE
  xmitCmd(0x11, 0x10, 0x01, 0x04, 0x21);
  // SET_PROPERTY - Group 20: MODEM
  xmitCmd(0x11, 0x20, 0x0C, 0x00, 0x6B, 0x00, 0x07, 0x01, 0x86, 0xA0, 0x05, 0x86, 0xA0, 0x00, 0x00, 0x01);
  xmitCmd(0x11, 0x20, 0x01, 0x0C, 0x33);
  xmitCmd(0x11, 0x20, 0x0C, 0x18, 0x01, 0x80, 0x08, 0x03, 0x60, 0x00, 0x70, 0x20, 0x0C, 0xE8, 0x01, 0x40);
  xmitCmd(0x11, 0x20, 0x0C, 0x24, 0x01, 0x99, 0x9A, 0x00, 0xCD, 0x00, 0xC2, 0x00, 0x54, 0x62, 0x80, 0x6B);
  xmitCmd(0x11, 0x20, 0x03, 0x30, 0x01, 0xE5, 0x80);
  xmitCmd(0x11, 0x20, 0x01, 0x35, 0xE0);
  xmitCmd(0x11, 0x20, 0x0C, 0x38, 0x11, 0x46, 0x46, 0x80, 0x1A, 0x99, 0x9A, 0x00, 0x2A, 0x0C, 0x84, 0x23);
  xmitCmd(0x11, 0x20, 0x03, 0x45, 0x8F, 0x00, 0x9C);
  xmitCmd(0x11, 0x20, 0x02, 0x50, 0x94, 0x09);
  xmitCmd(0x11, 0x20, 0x01, 0x54, 0x03);
  // SET_PROPERTY - Group 22: PA
  xmitCmd(0x11, 0x22, 0x04, 0x00, 0x08, 0x7F, 0x00, 0x1F);
  // SET_PROPERTY - Group 23: SYNTH
  xmitCmd(0x11, 0x23, 0x07, 0x00, 0x2C, 0x0E, 0x0B, 0x04, 0x0C, 0x73, 0x03);
  // SET_PROPERTY - Group 40: FREQ_CONTROL
  xmitCmd(0x11, 0x40, 0x07, 0x00, 0x4D, 0x09, 0x00, 0x00, 0x04, 0x00, 0x20);
  delay(20);
  waitForCTS();

  // Set device into TX mode
  // CHANGE_STATE to READY
  xmitCmd(0x34, 0x03);
  // SET_PROPERTY FREQ_CONTROL_CHANNEL_STEP_SIZE
  xmitCmd(0x11, 0x40, 0x04, 0x00, 0x4D, 0x05, 0xB4, 0x00, 0x04, 0x00, 0x20);
  // SET_PROPERTY MODEM_DSM_CTRL
  xmitCmd(0x11, 0x20, 0x02, 0x0D, 0x00, 0x00);
  // SET_PROPERTY MODEM_DSM_CTRL_RDY
  xmitCmd(0x11, 0x20, 0x02, 0x0B, 0x01, 0x33);
  // CHANGE_STATE to TX
  xmitCmd(0x34, 0x07);
  // CHANGE_STATE to READY
  delayMicroseconds(50);
  xmitCmd(0x34, 0x03);
  // SET_PROPERTY FREQ_CONTROL_CHANNEL_STEP_SIZE
  xmitCmd(0x11, 0x40, 0x04, 0x00, 0x4D, 0x05, 0xB4, 0x00, 0x04, 0x00, 0x20);
  // CHANGE_STATE to TX
  xmitCmd(0x34, 0x07);
  // SET_PROPERTY FREQ_CONTROL_CHANNEL_STEP_SIZE
  xmitCmd(0x11, 0x40, 0x04, 0x00, 0x4D, 0x05, 0xB4, 0x00, 0x04, 0x00, 0x20);

  digitalWrite(LED_GREEN, HIGH);


}






void loop() {

  if(bootFail) {
    return;
  }

  digitalWrite(spiGPIO3, HIGH);
  delayMicroseconds(400);
  digitalWrite(spiGPIO3, LOW);
  delayMicroseconds(400);
  //digitalWrite(LED_YELLOW, HIGH);
  //delay(500);
  //digitalWrite(LED_YELLOW, LOW);
  //delay(500);
}

void setSetupError() {
  digitalWrite(LED_RED, HIGH);
  assertRadioShutdown();
  bootFail = true;
}

// true is good, 
bool waitForCTS() {
  for(int x = 0; x < 100; x++ ) {

    assertCS();    
    SPI.transfer( 0x44);
    byte resp = 0x00;
    resp = SPI.transfer( 0xFF);
    deassertCS();
        
    if(resp == 0xFF) {
      return true;
    }
    delayMicroseconds(50);
  }

  // error
  return false;
}

void resetRadio() {
  assertRadioShutdown();
  delayMicroseconds(50);
  deassertRadioShutdown();
}

void assertRadioShutdown() {
  digitalWrite(siSDN, HIGH);
}

void deassertRadioShutdown() {
  digitalWrite(siSDN, LOW);
}

void assertCS() {
  digitalWrite(spiCS, LOW);
}

void deassertCS() {
  digitalWrite(spiCS, HIGH);
}

void sendPatches(){
  // PATCH_IMAGE, Verify CRC, Use TRX Image, CRC 0x714B, Key 0xBA9E  
  xmitCmd(0x04, 0x21, 0x71, 0x4B, 0x00, 0x00, 0xBA, 0x9E);
  // PATCH_ARGS/PATCH_DATA
  xmitCmd(0x05, 0x48, 0x23, 0x2E, 0x2B, 0x90, 0xB1, 0x4E);
  xmitCmd(0xEA, 0x3F, 0xB9, 0xE8, 0x8B, 0xA9, 0xCA, 0xD6);
  xmitCmd(0x05, 0xD2, 0xE5, 0xBE, 0xD1, 0x27, 0x55, 0x82);
  xmitCmd(0xE5, 0x56, 0x2A, 0x3B, 0x76, 0x76, 0x96, 0x48);
  xmitCmd(0x05, 0x8E, 0x26, 0xD8, 0x5D, 0x01, 0xA7, 0x88);
  xmitCmd(0xE2, 0x89, 0xCC, 0x63, 0x79, 0x95, 0x00, 0x4B);
  xmitCmd(0x05, 0xE0, 0x75, 0xCD, 0xA4, 0xB9, 0x46, 0xBC);
  xmitCmd(0xEA, 0xD3, 0x37, 0xD2, 0x9A, 0x89, 0x82, 0xEA);
  xmitCmd(0x05, 0x0C, 0xAE, 0x4C, 0xF5, 0xF6, 0x3C, 0xB3);
  xmitCmd(0xE9, 0xA7, 0x70, 0xDF, 0xF1, 0x14, 0x4F, 0x04);
  xmitCmd(0x05, 0xFE, 0x5B, 0xDF, 0x47, 0x0A, 0x7C, 0x5B);
  xmitCmd(0xE2, 0xFB, 0x3E, 0x21, 0xA2, 0x1B, 0xAA, 0x93);
  xmitCmd(0x05, 0xBF, 0xFD, 0xAB, 0x69, 0x6C, 0xA8, 0x5A);
  xmitCmd(0xE2, 0x66, 0xB7, 0x2E, 0x2C, 0x45, 0x2D, 0xFB);
  xmitCmd(0x05, 0x0D, 0x55, 0xBD, 0xC2, 0x37, 0x00, 0x72);
  xmitCmd(0xE2, 0xFF, 0x57, 0x4D, 0x7C, 0x6C, 0x00, 0x2C);
  xmitCmd(0x05, 0x9E, 0xF2, 0x46, 0xFD, 0xD3, 0x16, 0x1B);
  xmitCmd(0xEA, 0x16, 0x7F, 0x67, 0x4D, 0xE5, 0xE2, 0xC8);
  xmitCmd(0x05, 0x37, 0x33, 0x1C, 0xFA, 0xBB, 0xEE, 0xEF);
  xmitCmd(0xEA, 0x00, 0x5F, 0xBE, 0xA4, 0xFC, 0xBF, 0xC1);
  xmitCmd(0x05, 0x95, 0x12, 0x2F, 0x0A, 0xCF, 0x55, 0x8C);
  xmitCmd(0xE7, 0x70, 0xC2, 0xD4, 0xF0, 0x81, 0x95, 0xC8);
  xmitCmd(0xE7, 0x72, 0x00, 0xF9, 0x8D, 0x15, 0x01, 0xA3);
  xmitCmd(0xE7, 0x18, 0xE5, 0x6C, 0x51, 0x1F, 0x86, 0x9F);
  xmitCmd(0xE7, 0xDD, 0x37, 0x59, 0x4B, 0xAD, 0xB0, 0x9C);
  xmitCmd(0xE7, 0xC8, 0xE8, 0x84, 0xCD, 0x55, 0x41, 0x83);
  xmitCmd(0xEF, 0x4F, 0x8E, 0x38, 0xCB, 0x37, 0x02, 0x87);
  xmitCmd(0xE7, 0xF5, 0x00, 0x88, 0x4C, 0x09, 0x65, 0xCE);
  xmitCmd(0xEF, 0xDD, 0xBC, 0x65, 0x62, 0xAC, 0x75, 0x62);
  xmitCmd(0xE7, 0xC0, 0xF1, 0x5D, 0x98, 0xB0, 0xDD, 0x43);
  xmitCmd(0xE7, 0x19, 0xB4, 0xF8, 0x9F, 0x6D, 0x8C, 0xCB);
  xmitCmd(0xE1, 0xDE, 0x63, 0xC2, 0x32, 0xC6, 0xE4, 0x2F);
  xmitCmd(0x05, 0xF4, 0x33, 0xB7, 0x2E, 0x72, 0x9A, 0xF9);
  xmitCmd(0xE7, 0x65, 0xD9, 0x38, 0xB8, 0xFE, 0x31, 0x16);
  xmitCmd(0xE7, 0xF3, 0x06, 0x2D, 0xF5, 0xFE, 0x0C, 0x38);
  xmitCmd(0xE7, 0x70, 0x4F, 0xE7, 0x49, 0xB4, 0x58, 0x39);
  xmitCmd(0xEF, 0xF1, 0x46, 0xA9, 0x23, 0x38, 0x64, 0xC0);
  xmitCmd(0xE7, 0x09, 0x4E, 0x04, 0xD3, 0x46, 0x15, 0x02);
  xmitCmd(0xEF, 0x8D, 0xC7, 0x20, 0xC3, 0x90, 0x87, 0x4D);
  xmitCmd(0xEF, 0x00, 0xAB, 0x7F, 0x27, 0x02, 0xC6, 0xA0);
  xmitCmd(0xE7, 0x23, 0xA6, 0xA6, 0xA4, 0x27, 0x11, 0x7D);
  xmitCmd(0xEF, 0xB3, 0xF1, 0x9E, 0x6A, 0xB3, 0x19, 0xAF);
  xmitCmd(0xE7, 0xAB, 0xF5, 0x15, 0x78, 0x5E, 0x48, 0xF8);
  xmitCmd(0xEF, 0x5B, 0xB1, 0x2E, 0xAF, 0x2A, 0xFF, 0x16);
  xmitCmd(0xE7, 0x30, 0x62, 0x5C, 0x82, 0x7A, 0x3F, 0x83);
  xmitCmd(0xEF, 0x91, 0xA7, 0xD3, 0x1B, 0x64, 0x85, 0xBE);
  xmitCmd(0xE7, 0x4D, 0x81, 0x94, 0xE4, 0xAA, 0xE8, 0xDB);
  xmitCmd(0xEF, 0xA0, 0xCC, 0x4A, 0x23, 0xA5, 0x7E, 0x36);
  xmitCmd(0xEF, 0x0C, 0x72, 0x4C, 0xFB, 0x26, 0x5A, 0xEC);
  xmitCmd(0xEF, 0x0E, 0x42, 0xFA, 0xAF, 0x49, 0xA0, 0xA8);
  xmitCmd(0xE7, 0x6D, 0x12, 0xDF, 0x2B, 0x0C, 0x61, 0x58);
  xmitCmd(0xEA, 0xB6, 0x9B, 0xDE, 0x81, 0xB9, 0xFF, 0xFF);
  xmitCmd(0x05, 0x04, 0xEB, 0xD8, 0x12, 0xD6, 0x8D, 0xE0);
  xmitCmd(0xEC, 0x29, 0x66, 0x4B, 0xDE, 0xB7, 0xDE, 0x36);
  xmitCmd(0x05, 0x0D, 0x28, 0xB9, 0x0A, 0x89, 0x31, 0x1A);
}


void stallForCTS(){
  bool unstalled = false;
  while(!unstalled){
    unstalled = waitForCTS();
  }
}

// Transmit a 2-byte cmd and expect no return
void xmitCmd(byte a, byte b){
  
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

// Transmit a 5-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

// Transmit a 6-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e, byte f){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  SPI.transfer(f);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

// Transmit a 7-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e, byte f, byte g){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  SPI.transfer(f);
  SPI.transfer(g);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}


// Transmit a 8-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  SPI.transfer(f);
  SPI.transfer(g);
  SPI.transfer(h);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

// Transmit a 10-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h, byte i, byte j){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  SPI.transfer(f);
  SPI.transfer(g);
  SPI.transfer(h);
  SPI.transfer(i);
  SPI.transfer(j);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

// Transmit a 11-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  SPI.transfer(f);
  SPI.transfer(g);
  SPI.transfer(h);
  SPI.transfer(i);
  SPI.transfer(j);
  SPI.transfer(k);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

// Transmit a 16-byte cmd and expect no return
void xmitCmd(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k, byte l, byte m, byte n, byte o, byte p){
  stallForCTS();

  // Send cmd
  digitalWrite(LED_YELLOW, HIGH);
  assertCS();
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  SPI.transfer(d);
  SPI.transfer(e);
  SPI.transfer(f);
  SPI.transfer(g);
  SPI.transfer(h);
  SPI.transfer(i);
  SPI.transfer(j);
  SPI.transfer(k);
  deassertCS();
  digitalWrite(LED_YELLOW, LOW);
}

void powerUp(){
  assertCS();
  SPI.transfer(0x02);
  SPI.transfer(0x81);
  SPI.transfer(0x01);
  SPI.transfer(0x01);
  SPI.transfer(0x86);
  SPI.transfer(0xA0);
  SPI.transfer(0x00);
  deassertCS();
  digitalWrite(LED_YELLOW, HIGH);

  bool booted = false;
  while(!booted){
    booted = waitForCTS();
  }

  digitalWrite(LED_YELLOW, LOW);
}




