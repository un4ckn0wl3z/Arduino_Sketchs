void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    String var = Serial.readString();
    Serial.println(var);
  }

}
