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




//                      RX    TX
HardwareSerial SerialUSB(PA10, PA9);
HardwareSerial SerialGPS(PA3, PA2);

// LED timing variables
unsigned long greenLastms = 0;
unsigned long redLastms = 0;
unsigned long yellowLastms = 0;

const long greenInterval = 500;
const long redInterval = 1000;
const long yellowInterval = 2000;

// LED state variables
bool greenState = false;
bool redState = false;
bool yellowState = false;

// Serial debug messages
const bool debugLedMsgs = false;

bool executeonce = false;

void setup() {
  // Setup LED pins
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  // Setup Si4063 pins
  pinMode(siSDN, OUTPUT);
  pinMode(spiCS, OUTPUT);
  //pinMode(spiMOSI, OUTPUT);
  //pinMode(spiSCLK, OUTPUT);
  //pinMode(spiMOSI, OUTPUT);

  //SPI.setMISO(spiMISO);
  //SPI.setMOSI(spiMOSI);
  //SPI.setSCLK(spiSCLK);
  //SPI.setBitOrder(MSBFIRST);
  //SPI.setSSEL(spiCS);
  

  //SPI.begin();
  SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));

  // Setup USB UART
  SerialUSB.begin(9600);
  SerialUSB.println("Hello World!");

  digitalWrite(siSDN, HIGH);
  digitalWrite(spiCS, HIGH);

  //delay(100);
}




void loop() {
  ledInterval();

  //for testing SPI just execute once
  if (!executeonce && (millis() >= 2000)) {
    executeonce = true;
    //sendSPITest();
    //testPins();
    testSPIbasic();
  }
}

// true is good, 
bool waitForCTS() {
  for(int x = 0; x < 100; x++ ) {
    digitalWrite(spiCS, LOW);

    SPI.transfer( 0x44);

    byte resp = 0x00;
    resp = SPI.transfer( 0xFF);
    

    digitalWrite(spiCS, HIGH);
        
    if(resp == 0xFF) {
      return true;
    }
    delayMicroseconds(50);
  }

  // error
  return false;
}

void testSPIbasic() {
  digitalWrite(siSDN, LOW);
  delayMicroseconds(10);

  for(int x = 0; x < 100; x++ ) {
    digitalWrite(spiCS, LOW);

    SPI.transfer( 0x44);

    byte resp = 0x00;
    resp = SPI.transfer( 0xFF);
    

    digitalWrite(spiCS, HIGH);
    
    SerialUSB.print("Response from 1st 0x44: \t");
    SerialUSB.println(resp,HEX);
    
    if(resp == 0xFF) {
      break;
    }
    delayMicroseconds(50);
  }

  digitalWrite(spiCS, LOW);
  SPI.transfer( 0x33);
  digitalWrite(spiCS, HIGH);

  for(int x = 0; x < 100; x++ ) {
    digitalWrite(spiCS, LOW);

    SPI.transfer( 0x44);

    byte resp = 0x00;
    byte resp1 = 0x00;
    byte resp2 = 0x00;

    resp = SPI.transfer( 0xFF);
    
        
    if(resp == 0xFF) {
      
      resp1 = SPI.transfer( 0xFF);
      resp2 = SPI.transfer( 0xFF);
      digitalWrite(spiCS, HIGH);

      SerialUSB.print("Response from 0x44: \t");
      SerialUSB.println(resp,HEX);
      SerialUSB.print("Response1 from 0x33: \t");
      SerialUSB.println(resp1,HEX);
      SerialUSB.print("Response2 from 0x33: \t");
      SerialUSB.println(resp2,HEX);
      break;
    }
    digitalWrite(spiCS, HIGH);

    //SerialUSB.print("Response from 0x44: \t");
    //SerialUSB.println(resp,HEX);

    delayMicroseconds(50);
  }
  
  
  

  delayMicroseconds(10);
  digitalWrite(siSDN, HIGH);
}


// toggle led per the interval
void ledInterval() {
  unsigned long currentms = millis();

  if ((currentms - greenLastms) >= greenInterval) {
    greenLastms = currentms;
    toggleLED(LED_GREEN, greenState);
    
    if(debugLedMsgs) {
      SerialUSB.println("Green Toggle!");
    }
  }

  if ((currentms - redLastms) >= redInterval) {
    redLastms = currentms;
    toggleLED(LED_RED, redState);

    if(debugLedMsgs) {
      SerialUSB.println("Red Toggle!");
    }
  }

  if ((currentms - yellowLastms) >= yellowInterval) {
    yellowLastms = currentms;
    toggleLED(LED_YELLOW, yellowState);
    
    if(debugLedMsgs) {
      SerialUSB.println("Yellow Toggle!");
    }
  }
}


void toggleLED(int led, bool& state) {
  digitalWrite(led, !state);
  state = !state;
}

