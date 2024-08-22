// C++ code
#define BUTTON_PIN 2
#define LED_PIN 12

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  Serial.println(digitalRead(BUTTON_PIN));
  if(digitalRead(BUTTON_PIN)) {
    digitalWrite(LED_PIN, HIGH);
  }else {
        digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}