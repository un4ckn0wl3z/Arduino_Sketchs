#include <LCD_I2C.h>

LCD_I2C lcd(0x27);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  lcd.begin();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    lcd.clear();
    String text = Serial.readString();
    if(text.length() > 16) {
      lcd.print("Text too long");
      return;
    }

    lcd.print(text);
  }

}
