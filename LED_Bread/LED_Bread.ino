// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(100); // Wait for 1000 millisecond(s)
}