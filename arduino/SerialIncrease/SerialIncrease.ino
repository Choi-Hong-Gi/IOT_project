int a = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  a++;
  Serial.print(a);
  Serial.println(" sec");
  delay(500);
}
