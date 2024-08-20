// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(100); // Wait for 1000 millisecond(s)
}