void setup() {
  // put your setup code here, to run once:

  // set LED pin to output
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // set state of pin 13 to HIGH
  digitalWrite(13, HIGH);
  // delay for blink
  delay(500);
  // set state of pin 13 to LOW
  digitalWrite(13, LOW);
  // delay for blink
  delay(500);


}
