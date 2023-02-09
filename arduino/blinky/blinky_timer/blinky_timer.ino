#define LED_GREEN PC_6
#define LED_RED PB12
#define LED_YELLOW PC_7

// NFC Tag Library - https://github.com/Seeed-Studio/NFC_Tag_M24LR6E

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
const bool debugLedMsgs = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  SerialUSB.begin(9600);
  SerialUSB.println("Hello World!");

}



void loop() {
  ledInterval();

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