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

  for(int delayus = 0; delayus <= 1500; delayus += 50) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);

    SerialUSB.print("delay: " );
    SerialUSB.println(delayus);

    // Boot radio
    deassertRadioShutdown();
    delayMicroseconds(delayus);

    // Check for boot CTS
    int lcount = -100;
    if(!waitForCTS(lcount)) {
      digitalWrite(LED_GREEN, HIGH);
    } else {
      digitalWrite(LED_RED, HIGH);
    }

    assertRadioShutdown();

    SerialUSB.print("loop: " );
    SerialUSB.println(lcount);
    delay(100);
  }
  

}






void loop() {
  
}

// true is good, 
bool waitForCTS(int& loopcount) {
  for(int x = 0; x < 100; x++ ) {

    assertCS();    
    SPI.transfer( 0x44);
    byte resp = 0x00;
    resp = SPI.transfer( 0xFF);
    deassertCS();
        
    if(resp == 0xFF) {
      loopcount = x;
      return true;
    }
    delayMicroseconds(50);
  }

  loopcount=-1;
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





