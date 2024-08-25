#include "EEPROM.h"

void setup() {
  // put your setup code here, to run once:
  // EEPROM.write(0, 44);
  // EEPROM.write(200, 150);

  Serial.begin(115200);
  Serial.println(EEPROM.read(0));
  Serial.println(EEPROM.read(200));

}

void loop() {
  // put your main code here, to run repeatedly:

}
