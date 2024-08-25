#define BUTTON_PIN 2

byte buttonState = LOW;
unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDelay = 50;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
          Serial.println("Button Pressed");
        } else {
          Serial.println("Button released");
        }
      }
  }


}
