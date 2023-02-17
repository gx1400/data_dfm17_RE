#define LED_GREEN PC_6
#define LED_RED PB12
#define LED_YELLOW PC_7

// NFC Tag Library - https://github.com/Seeed-Studio/NFC_Tag_M24LR6E

//                      RX    TX
HardwareSerial SerialUSB(PA10, PA9);
HardwareSerial SerialGPS(PA3, PA2);

int loopNum = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  SerialUSB.begin(9600);
  SerialUSB.println("Hello World!");

}

void l_on(){
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
}

void l_off(){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
}

void loop() {
  l_on();
  delay(40);
  l_off();
  delay(40);

  l_on();
  delay(40);
  l_off();
  delay(40);

  l_on();
  delay(40);
  l_off();
  delay(40);

  l_on();
  delay(200);
  l_off();
  delay(100);

  SerialUSB.print("Loop count: ");
  SerialUSB.println(loopNum);
  loopNum++;

}