#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11
#define POTENTIOMETER_PIN A2
#define BUTTON_PIN 2


unsigned long redLedPreviousBlink = millis();
unsigned long redLedBlinktimeIntervalSerial = 100;

bool RED_SWITCH = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(BUTTON_PIN)){
    digitalWrite(YELLOW_LED_PIN, HIGH);
  }else {
    digitalWrite(YELLOW_LED_PIN, LOW);
  }

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int LEDBrightness = potentiometerValue / 4;
  analogWrite(GREEN_LED_PIN, LEDBrightness);


  unsigned long timeNow = millis();

  if (timeNow - redLedPreviousBlink > redLedBlinktimeIntervalSerial) {
     if(RED_SWITCH == false){
        digitalWrite(RED_LED_PIN, HIGH);
        RED_SWITCH = true;
     }else if(RED_SWITCH == true){
        digitalWrite(RED_LED_PIN, LOW);
        RED_SWITCH = false;
     }
    redLedPreviousBlink += redLedBlinktimeIntervalSerial;
  }

}
