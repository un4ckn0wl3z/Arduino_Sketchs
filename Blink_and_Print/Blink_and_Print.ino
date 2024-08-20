void setup() {
  // put your setup code here, to run once:

  // set LED pin to output
  pinMode(13, OUTPUT);

  // begin serial
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // set state of pin 13 to HIGH
  Serial.println("LED is ON");
  digitalWrite(13, HIGH);
  // delay for blink
  delay(2000);
  // set state of pin 13 to LOW
  Serial.println("LED is OFF");
  digitalWrite(13, LOW);
  // delay for blink
  delay(1000);


}
