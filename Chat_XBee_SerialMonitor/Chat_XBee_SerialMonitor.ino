// Serial Monitor configuration: Newline, 9600 baud

#include <SoftwareSerial.h>

SoftwareSerial xbee(8, 9); // Rx, Tx

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  xbee.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(xbee.available()>0) {
    Serial.print("Bera: ");
    char c = xbee.read();
    while(c != 0x0a) {
      if(xbee.available()>0) {
        Serial.write(c);
        c = xbee.read();
      }
    }
    Serial.write(c);
  }

  if(Serial.available()>0) {
    Serial.print("Ni: ");
    char c = Serial.read();
    while(c != 0x0a) {
      xbee.write(c);
      Serial.write(c);
      c = Serial.read();
    }
    xbee.write(c);
    Serial.write(c);
  }
}
