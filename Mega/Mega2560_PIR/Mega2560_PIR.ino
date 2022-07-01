#define PIR A0

void setup() {
  Serial.begin(9600);
  pinMode(PIR , INPUT_PULLUP);
}

void loop() {
  Serial.println( analogRead( PIR ) );
  delay(100);
}