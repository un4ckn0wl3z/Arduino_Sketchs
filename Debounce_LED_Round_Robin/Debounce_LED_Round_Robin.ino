#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11
#define RED_LED_PIN 12

#define BUTTON_PIN 2

byte buttonState = LOW;
unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDelay = 50;

unsigned long redLedLastTimeBlink =  millis();
unsigned long redLedLastBlinkInterval =  200;

bool RED_SWITCH = false;

unsigned LED_State = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();

  if (timeNow - lastTimeButtonChanged > debounceDelay) {
      byte newButtonState = digitalRead(BUTTON_PIN);
      if (newButtonState != buttonState) { 
        lastTimeButtonChanged = timeNow;
        buttonState = newButtonState;
        if(buttonState == HIGH){
          if(LED_State == 0) {
            LED_State = 1;
          } else if (LED_State == 1) {
            LED_State = 2;
          } else {
            LED_State = 1;
          }
          Serial.println("Button Pressed");
        } else {
          Serial.println("Button released");
        }
      }
  }


  switch (LED_State) {
  case 1: {
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(YELLOW_LED_PIN, LOW);
        break;
  }
  case 2: {
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, HIGH);
        break;
  }
  default: {
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, LOW);
    break;
  }
  }

  
  if(timeNow - redLedLastTimeBlink > redLedLastBlinkInterval){
    if(RED_SWITCH) {
      RED_SWITCH = false;
      digitalWrite(RED_LED_PIN, LOW);
    }else {
      RED_SWITCH = true;
      digitalWrite(RED_LED_PIN, HIGH);
    }
      redLedLastTimeBlink += redLedLastBlinkInterval;
  }


}
