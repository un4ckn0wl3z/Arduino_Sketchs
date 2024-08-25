#define BUTTON_PIN 2

volatile unsigned long lastTimeButtonPressed = millis();
unsigned long debounceDelay = 50;

volatile bool buttonPressed = false;
volatile unsigned long buttonPressedCounter = 0;

void buttonPressedInterrupt() {
  unsigned long timeNow = millis();
  if(timeNow - lastTimeButtonPressed > debounceDelay) {
    buttonPressedCounter++;
    lastTimeButtonPressed = timeNow;
    buttonPressed = true;

  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressedInterrupt, RISING);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonPressed) {
    buttonPressed = false;
    Serial.println(buttonPressedCounter);
  }

}
