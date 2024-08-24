#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11
#define SWITCH_PIN 2

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(SWITCH_PIN)){
    digitalWrite(YELLOW_LED_PIN, HIGH);
    return;
  } 
  digitalWrite(RED_LED_PIN, HIGH);
  delay(50);
  digitalWrite(RED_LED_PIN, LOW);

  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(50);
  digitalWrite(GREEN_LED_PIN, LOW);

  digitalWrite(YELLOW_LED_PIN, HIGH);
  delay(50);
  digitalWrite(YELLOW_LED_PIN, LOW);


}
