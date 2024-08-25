unsigned long redLedPreviousBlink = millis();
unsigned long redLedBlinktimeIntervalSerial = 30;

unsigned long greenLedPreviousBlink = millis();
unsigned long greenLedBlinktimeIntervalSerial = 50;

unsigned long yellowLedPreviousBlink = millis();
unsigned long yellowBlinktimeIntervalSerial = 90;

#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11

bool RED_SWITCH = false;
bool GREEN_SWITCH = false;
bool YELLOW_SWITCH = false;


void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);

  pinMode(GREEN_LED_PIN, OUTPUT);
  digitalWrite(GREEN_LED_PIN, LOW);

  pinMode(YELLOW_LED_PIN, OUTPUT);
  digitalWrite(YELLOW_LED_PIN, LOW);

}

void loop() {
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


  if (timeNow - greenLedPreviousBlink > greenLedBlinktimeIntervalSerial) {
     if(GREEN_SWITCH == false){
        digitalWrite(GREEN_LED_PIN, HIGH);
        GREEN_SWITCH = true;
     }else if(GREEN_SWITCH == true){
        digitalWrite(GREEN_LED_PIN, LOW);
        GREEN_SWITCH = false;
     }
    greenLedPreviousBlink += greenLedBlinktimeIntervalSerial;
  }


  if (timeNow - yellowLedPreviousBlink > yellowBlinktimeIntervalSerial) {
     if(YELLOW_SWITCH == false){
        digitalWrite(YELLOW_LED_PIN, HIGH);
        YELLOW_SWITCH = true;
     }else if(YELLOW_SWITCH == true){
        digitalWrite(YELLOW_LED_PIN, LOW);
        YELLOW_SWITCH = false;
     }
    yellowLedPreviousBlink += yellowBlinktimeIntervalSerial;
  }
}
