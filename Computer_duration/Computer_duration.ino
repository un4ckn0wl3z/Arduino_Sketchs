  unsigned long g_timeBegin;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  unsigned long timeBegin = millis();
  delay(500);
  unsigned long timeEnd = millis();
  unsigned long duration = timeEnd - timeBegin;
  Serial.print("The duration is: ");
  Serial.println(duration);


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  unsigned long now = millis();
  Serial.println(now - g_timeBegin);

}
