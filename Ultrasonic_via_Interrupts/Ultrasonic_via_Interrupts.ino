#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define BUZZER_PIN 13

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 100;
volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile bool newDistanceAvailable = false;


void triggerUltrasonicSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance() {
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0;
  return distance;
}

void echoPinInterrupt() {
  if (digitalRead(ECHO_PIN) == HIGH) {
    // rising
    pulseInTimeBegin = micros();
  } else {
    // falling
    pulseInTimeEnd = micros();
    newDistanceAvailable = true;
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO_PIN), echoPinInterrupt, CHANGE);

}

void loop() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay) {
    lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
    // trigger sensor
    triggerUltrasonicSensor();    
  }

  if (newDistanceAvailable) {
    newDistanceAvailable = false;
        // read echo
    double distance = getUltrasonicDistance();
    Serial.println(distance);
    // if(distance < 10.0) {
    //   digitalWrite(BUZZER_PIN, HIGH);
    // }else {
    //   digitalWrite(BUZZER_PIN, LOW);
    // }
  }


}
