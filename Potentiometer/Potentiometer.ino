#define POTEN_ANALOG_READ_PIN A2
#define PWM_LED_PIN 11

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_LED_PIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potentiometerValue = analogRead(POTEN_ANALOG_READ_PIN);
  int LEDBrightness = potentiometerValue / 4;
  analogWrite(PWM_LED_PIN, LEDBrightness);
  Serial.println(LEDBrightness);
}
