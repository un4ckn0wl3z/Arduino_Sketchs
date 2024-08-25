#define RED_LED_PIN 12
#define BUTTON_PIN 2

volatile unsigned long lastTimeButtonReleased = millis();
unsigned long debounceDelay = 50;


byte LEDState = LOW;
volatile bool buttonReleased = false;

void toggleLED() {
  if (LEDState == LOW) {
    LEDState = HIGH;
  } else {
    LEDState = LOW;
  }
  digitalWrite(RED_LED_PIN, LEDState);
}

void buttonReleasedInterrupt() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeButtonReleased > debounceDelay) {

    lastTimeButtonReleased = timeNow;
    buttonReleased = true;

  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), 
    buttonReleasedInterrupt, FALLING);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonReleased) {
    buttonReleased = false;
    toggleLED();
  }

}
