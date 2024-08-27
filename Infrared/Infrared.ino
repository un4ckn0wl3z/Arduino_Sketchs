#include "IRremote.h"
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


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    IrReceiver.resume();
    // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    // Serial.println(IrReceiver.decodedIRData.command);
    // Serial.println("---");

    switch (IrReceiver.decodedIRData.command) {
    case IR_BUTTON_1: {
      Serial.println("1");
      break;
    }
    case IR_BUTTON_2: {
      Serial.println("2");
      break;
    }
    case IR_BUTTON_3: {
      Serial.println("3");
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
