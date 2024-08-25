#include "EEPROM.h"
#define LED_PIN 11

byte ledBrightness;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  ledBrightness = EEPROM.read(3);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    byte tmpLedBrightness = Serial.parseInt();
    if(tmpLedBrightness > 255){
       return;
    }
    ledBrightness = tmpLedBrightness;
    EEPROM.write(3, ledBrightness);
  }

  analogWrite(LED_PIN, ledBrightness);

}