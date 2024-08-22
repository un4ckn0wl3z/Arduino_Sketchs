// C++ code
#define BUTTON_PIN 2
#define LED_PIN 11

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  Serial.println(digitalRead(BUTTON_PIN));
  if(digitalRead(BUTTON_PIN)) {
    analogWrite(LED_PIN, 255);
  }else {
    analogWrite(LED_PIN, 0);
  }
  delay(100);
}