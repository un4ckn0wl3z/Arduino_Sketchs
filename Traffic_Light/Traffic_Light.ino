#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11
#define BEEP_PIN 1



void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BEEP_PIN, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BEEP_PIN, HIGH);
  delay(50);
  digitalWrite(BEEP_PIN, LOW);


  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BEEP_PIN, HIGH);
  delay(50);
  digitalWrite(BEEP_PIN, LOW);

  digitalWrite(YELLOW_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(BEEP_PIN, HIGH);
  delay(50);
  digitalWrite(BEEP_PIN, LOW);
}
