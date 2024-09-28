#define PIN_A 7
#define PIN_B 6
#define PIN_C 4
#define PIN_D 3
#define PIN_F 8
#define PIN_E 2
#define PIN_G 9
#define PIN_DP 5

// Segment patterns for numbers 0-16
// Each number corresponds to the state of the 7 segments: A, B, C, D, E, F, G
const int segmentMap[17][7] = {
  // A, B, C, D, E, F, G
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW },   // 0
  { LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW },   // 1
  { HIGH, HIGH, LOW,  HIGH, HIGH, LOW,  HIGH },  // 2
  { HIGH, HIGH, HIGH, HIGH, LOW,  LOW,  HIGH },  // 3
  { LOW,  HIGH, HIGH, LOW,  LOW,  HIGH, HIGH },  // 4
  { HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, HIGH },  // 5
  { HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH },  // 6
  { HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW },   // 7
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH },  // 8
  { HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH },  // 9
  { HIGH, HIGH, HIGH, LOW,  HIGH, HIGH, HIGH },  // 10 (A)
  { LOW,  LOW,  HIGH, HIGH, HIGH, HIGH, HIGH },  // 11 (b)
  { HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, LOW },   // 12 (C)
  { LOW,  HIGH, HIGH, HIGH, HIGH, LOW,  HIGH },  // 13 (d)
  { HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, HIGH },  // 14 (E)
  { HIGH, LOW,  LOW,  LOW,  HIGH, HIGH, HIGH },  // 15 (F)
  { LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW }    // 16 (blank or invalid)
};

void setup() {
  // Initialize segment pins as outputs
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_DP, OUTPUT);
}

void sevenSegEncode(int num) {
  // Limit the input to 0-16
  if (num < 0 || num > 16) {
    num = 16;  // Invalid input displays blank (or choose to display 0)
  }
  
  // Set each segment according to the pattern for the number
  digitalWrite(PIN_A, segmentMap[num][0]);
  digitalWrite(PIN_B, segmentMap[num][1]);
  digitalWrite(PIN_C, segmentMap[num][2]);
  digitalWrite(PIN_D, segmentMap[num][3]);
  digitalWrite(PIN_E, segmentMap[num][4]);
  digitalWrite(PIN_F, segmentMap[num][5]);
  digitalWrite(PIN_G, segmentMap[num][6]);
}

void loop() {
  digitalWrite(PIN_DP, HIGH);
  for(int i = 0; i < 16; i++) {
    sevenSegEncode(i);
    delay(1000);
  }
}
