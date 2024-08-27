#include "IRremote.h"
#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

#define IR_RECEIVE_PIN 5

#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71
#define IR_BUTTON_4 68
#define IR_BUTTON_5 64
#define IR_BUTTON_6 67
#define IR_BUTTON_7 7
#define IR_BUTTON_8 21
#define IR_BUTTON_9 9
#define IR_BUTTON_0 25
#define IR_BUTTON_ASTERISK 22
#define IR_BUTTON_HASH 13

#define IR_BUTTON_UP 24
#define IR_BUTTON_LEFT 8
#define IR_BUTTON_RIGHT 90
#define IR_BUTTON_DOWN 82

#define IR_BUTTON_OK 28

#define RED_LED_PIN 12
#define GREEN_LED_PIN 10
#define YELLOW_LED_PIN 11

#define BUZZER_PIN 13

bool RED_STATE = false;
bool GREEN_STATE = false;
bool YELLOW_STATE = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  IrReceiver.begin(IR_RECEIVE_PIN);
  lcd.begin();
  lcd.backlight();
  lcd.print("IR REMOTE RECVER");

}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    IrReceiver.resume();
    // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    // Serial.println(IrReceiver.decodedIRData.command);
    // Serial.println("---");

    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);

    lcd.clear();
    lcd.print("IR Data: ");
    lcd.setCursor(9, 0);
    lcd.print(IrReceiver.decodedIRData.command);

    lcd.setCursor(0, 1);
    switch (IrReceiver.decodedIRData.command) {
    case IR_BUTTON_1: {
      Serial.println("1");
      if(!RED_STATE) {
         RED_STATE = true;
         digitalWrite(RED_LED_PIN, HIGH);
         lcd.print("Toggle RED LED");
      }else {
        RED_STATE = false;
         digitalWrite(RED_LED_PIN, LOW);
         lcd.print("Disable RED LED");
      }
      
      break;
    }
    case IR_BUTTON_2: {
      Serial.println("2");
      if(!YELLOW_STATE) {
         YELLOW_STATE = true;
         digitalWrite(YELLOW_LED_PIN, HIGH);
         lcd.print("Toggle YELW LED");
      }else {
        YELLOW_STATE = false;
         digitalWrite(YELLOW_LED_PIN, LOW);
         lcd.print("Disable YELW LED");
      }
      
      break;
    }
    case IR_BUTTON_3: {
      Serial.println("3");
      if(!GREEN_STATE) {
         GREEN_STATE = true;
         digitalWrite(GREEN_LED_PIN, HIGH);
         lcd.print("Toggle GRN LED");
      }else {
        GREEN_STATE = false;
         digitalWrite(GREEN_LED_PIN, LOW);
         lcd.print("Disable GRN LED");
      }
      
      break;
    }
    case IR_BUTTON_4: {
      Serial.println("4");
      break;
    }
    case IR_BUTTON_5: {
      Serial.println("5");
      break;
    }
    case IR_BUTTON_6: {
      Serial.println("6");
      break;
    }
    case IR_BUTTON_7: {
      Serial.println("7");
      break;
    }
    case IR_BUTTON_8: {
      Serial.println("8");
      break;
    }
    case IR_BUTTON_9: {
      Serial.println("9");
      break;
    }
    case IR_BUTTON_0: {
      Serial.println("0");
      lcd.clear();
      lcd.print("Clear!");
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);


      break;
    }
    case IR_BUTTON_UP: {
      Serial.println("UP");
      break;
    }
    case IR_BUTTON_LEFT: {
      Serial.println("LEFT");
      break;
    }
    case IR_BUTTON_RIGHT: {
      Serial.println("RIGHT");
      break;
    }
    case IR_BUTTON_DOWN: {
      Serial.println("DOWN");
      break;
    }
    case IR_BUTTON_OK: {
      Serial.println("OK");
      break;
    }
    case IR_BUTTON_ASTERISK: {
      Serial.println("*");
      break;
    }
    case IR_BUTTON_HASH: {
      Serial.println("#");
      break;
    }
    default: {
      Serial.println("Unk");
    }
    }

  }
}
