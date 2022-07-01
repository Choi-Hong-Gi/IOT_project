int randNumber;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(5));
}

void loop() {
  for(int i = 0; i<6; i++){
  randNumber = random(45)+1;
  Serial.println(randNumber);

  delay(50);
  }
    Serial.println();
    Serial.println();
      Serial.println();
}
