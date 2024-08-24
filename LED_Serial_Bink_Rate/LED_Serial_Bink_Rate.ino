#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11

int default_blink_rate;


void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(10);
  default_blink_rate = 500;

}

void loop() {

  if(Serial.available()) {
    default_blink_rate = Serial.parseInt();
  }
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED_PIN, HIGH);
  delay(default_blink_rate);
  digitalWrite(RED_LED_PIN, LOW);


  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(default_blink_rate);
  digitalWrite(GREEN_LED_PIN, LOW);

  digitalWrite(YELLOW_LED_PIN, HIGH);
  delay(default_blink_rate);
  digitalWrite(YELLOW_LED_PIN, LOW);
}