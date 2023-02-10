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


}






void loop() {

  if(bootFail) {
    return;
  }

  digitalWrite(LED_YELLOW, HIGH);
  delay(500);
  digitalWrite(LED_YELLOW, LOW);
  delay(500);
}

void setSetupError() {
  digitalWrite(LED_RED, HIGH);
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





