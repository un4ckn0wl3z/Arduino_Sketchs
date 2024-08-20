void setup() {
  // put your setup code here, to run once:
  // init serial
  Serial.begin(9600);
  Serial.println("Hello Arduino");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Arduino");
  delay(1500);

}
