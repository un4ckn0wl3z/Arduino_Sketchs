unsigned long previousTimeSerialPrint = millis();
unsigned long timeIntervalSerialPrint = 500;


void setup() {
  Serial.begin(115200);
  Serial.println("------------------------");
}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow - previousTimeSerialPrint > timeIntervalSerialPrint) {
     Serial.println("Hello");
     Serial.println(millis());
    previousTimeSerialPrint += timeIntervalSerialPrint;
  }
}
