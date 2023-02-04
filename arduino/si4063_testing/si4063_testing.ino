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


SPIClass siSPI(spiMOSI, spiMISO, spiSCLK);
//SPIClass siSPI();
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

  //siSPI.begin();
  //siSPI.setClockDivider(SPI_CLOCK_DIV16);
  siSPI.beginTransaction(SPISettings(500000,MSBFIRST,SPI_MODE0, SPI_TRANSMITRECEIVE));

  // Setup USB UART
  SerialUSB.begin(9600);
  SerialUSB.println("Hello World!");

  digitalWrite(siSDN, HIGH);    //assert shutdown on Si4063

  delay(100);
}




void loop() {
  ledInterval();

  //for testing SPI just execute once
  if (!executeonce && (millis() >= 2000)) {
    executeonce = true;
    sendSPITest();
  }
}

void sendSPITest() {
  SerialUSB.println("Start SPI");

  // deassert shutdown
  digitalWrite(siSDN, LOW);
  delayMicroseconds(10);

  sendCmd(0x44);
  waitForCTS();

  //sendCmd(0x33);
  //waitForCTS();

  //byte mainstate = readSPIoneByte();
  //byte currchan = readSPIoneByte();
  
  

  delay(50);
  digitalWrite(siSDN, LOW);
  SerialUSB.println("End SPI");

  //SerialUSB.print("Main state: ");
  //SerialUSB.println(mainstate, HEX);
  //SerialUSB.print("Current channel: ");
  //SerialUSB.println(currchan, HEX);
} 

void sendCmd(byte cmd) {
  siSPI.transfer(spiCS, cmd);
}

void waitForCTS() {
  for(int x = 0; x < 100; x++ ) {
    byte resp = 0x00;
    resp = readSPIoneByte();
    SerialUSB.print("Response: \t");
    SerialUSB.println(resp,HEX);

    if(resp == 0xFF) {
      return;
    }
    delayMicroseconds(50);
  }
}

byte readSPIoneByte() {
  return siSPI.transfer(spiCS, 0xFF);
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

