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

  for (int i = 0; i < 255; i++) {
      delay(5);
      analogWrite(LED_PIN, i);
  }

  for (int i = 255; i > 0; i--) {
      delay(5);
      analogWrite(LED_PIN, i);
  }
 
}