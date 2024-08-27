#define PHOTORESISTOR_PIN A0
#define LED_1_PIN 12
#define LED_2_PIN 11

#define LUMINOSITY_NIGHT_TRESHOLD 330

#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  int luminosity = analogRead(PHOTORESISTOR_PIN);

  if (luminosity < LUMINOSITY_NIGHT_TRESHOLD) {
    digitalWrite(LED_1_PIN, HIGH);
  }
  else {
    digitalWrite(LED_1_PIN, LOW);
  }

  int brightness = 255 - luminosity / 4;
  lcd.clear();
  lcd.print("luminosity: ");
  lcd.setCursor(12, 0);
  lcd.print(luminosity);
  lcd.setCursor(0, 1);
  lcd.print("Brightness: ");
  lcd.setCursor(12, 1);
  lcd.print(brightness);

  analogWrite(LED_2_PIN, brightness);
  delay(500);
}
