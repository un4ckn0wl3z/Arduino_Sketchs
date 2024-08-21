// C++ code
//
#define DELAY 100

int LED_PIN = 12;
int LED_OUT = 13;


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED_OUT, HIGH);
  delay(DELAY); // Wait for 1000 millisecond(s)
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_OUT, LOW);
  delay(DELAY); // Wait for 1000 millisecond(s)
}