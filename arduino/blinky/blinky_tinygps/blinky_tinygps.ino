#include <TinyGPS++.h>  //http://arduiniana.org/libraries/tinygpsplus/
#include <TinyGPSPlus.h>

#define LED_GREEN PC_6
#define LED_RED PB12
#define LED_YELLOW PC_7


//                      RX    TX
HardwareSerial SerialUSB(PA10, PA9);
HardwareSerial SerialGPS(PA3, PA2);

// LED timing variables
unsigned long greenLastms = 0;
unsigned long redLastms = 0;
unsigned long yellowLastms = 0;
unsigned long gpsLastms = 0;

const long greenInterval = 500;
const long redInterval = 1000;
const long yellowInterval = 2000;
const long gpsInterval = 30000;

// LED state variables
bool greenState = false;
bool redState = false;
bool yellowState = false;

// Serial debug messages
const bool debugLedMsgs = false;
const bool debugGpsMsgs = false;

// GPS variable
TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  SerialUSB.begin(9600);
  //SerialUSB.println("Hello World!");

  SerialGPS.begin(9600);

  SerialUSB.print("TinyGPS Version: ");
  SerialUSB.println(TinyGPSPlus::libraryVersion());

}



void loop() {
  ledInterval();

  feedGPS();
}

// get GPS characters
void feedGPS() {
  while(SerialGPS.available()) {
    gps.encode(SerialGPS.read());
  }

  
  if(gps.location.isUpdated()) {
    unsigned long currentms = millis();
    if( ((currentms - gpsLastms) > gpsInterval) || (debugGpsMsgs) ) {
      gpsLastms = currentms;

      char buf[10];
      sprintf(buf, "%02d:%02d:%02d", gps.time.hour(), gps.time.minute(), gps.time.second());

      SerialUSB.print("Time="); SerialUSB.print(buf); 
      SerialUSB.print(", LAT="); SerialUSB.print(gps.location.lat(), 6);
      SerialUSB.print(", LNG="); SerialUSB.print(gps.location.lng(), 6);
      SerialUSB.print(", ALT="); SerialUSB.print(gps.altitude.meters());
      SerialUSB.print(", SATS="); SerialUSB.println(gps.satellites.value());
    }
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