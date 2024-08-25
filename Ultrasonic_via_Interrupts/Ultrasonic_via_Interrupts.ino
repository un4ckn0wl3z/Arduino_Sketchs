#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define BUZZER_PIN 13

#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11

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

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);


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

    if (distance >= 100) {
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);
      //digitalWrite(BUZZER_PIN, LOW);
    }else if (distance >= 20) {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      //digitalWrite(BUZZER_PIN, LOW);
    } else {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      //digitalWrite(BUZZER_PIN, HIGH);
    }
  }


}
