#include <SPI.h>

// LED pins
#define LED_GREEN PC_6
#define LED_RED PB12
#define LED_YELLOW PC_7

// Si4063 pins
#define siCS PB2
#define siSDN PC_3
#define siSDI PA7
#define siSDO PA6
#define siSCLK PA5

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
  pinMode(siCS, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  // Setup USB UART
  SerialUSB.begin(9600);
  SerialUSB.println("Hello World!");


  digitalWrite(siCS, HIGH);
  digitalWrite(siSDN, HIGH);

  delay(100);

}




void loop() {
  ledInterval();

  if (!executeonce && (millis() >= 2000)) {
    executeonce = true;

    sendSPITest();
  }

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

void sendSPITest() {
  SerialUSB.println("Start SPI");
  digitalWrite(siSDN, LOW);
  digitalWrite(siCS, LOW);


  for(int x = 0; x < 10; x++ ) {
    SerialUSB.print("SPI Packet #" );
    SerialUSB.print(x,DEC);
    SerialUSB.println(":");

    SPI.transfer(0x44);

    byte resp = SPI.transfer(0xFF);
    SerialUSB.print("Response: \t");
    SerialUSB.println(resp,BIN);

    delay(10);
  }

  digitalWrite(siCS, HIGH);
  delay(100);
  digitalWrite(siSDN, HIGH);
  SerialUSB.println("End SPI");
} 