#include <LCDI2C_Multilingual.h>

LCDI2C_Generic lcd(0x27, 16, 2);       // I2C address = 0x27; LCD1602A (16 columns, 2 rows)

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.println("สวัสดี");
}
void loop() {}