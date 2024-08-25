void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  unsigned long timeNow = millis();
  Serial.println(timeNow);


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println(micros());  

}
