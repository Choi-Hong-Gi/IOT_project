int Count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(++Count > 9600)
    Count = 0;

   Serial.print("Count = ");
   Serial.println(Count);
   delay(100);
}
