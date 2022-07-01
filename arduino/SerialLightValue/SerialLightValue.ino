int analogValue = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  analogValue = analogRead(A5);
  Serial.println(analogValue);
  int mapValue = map(analogValue, 190, 650, 0, 255);
  
  analogWrite(5,analogValue);
  delay(10);
}
