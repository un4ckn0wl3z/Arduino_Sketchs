// C++ code
#define LED_PIN 11
int PWM = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, PWM);
}

void loop()
{
  delay(1);
  PWM++;
  analogWrite(LED_PIN, PWM);
  if (PWM == 255) {
    PWM = 0;
  }
}