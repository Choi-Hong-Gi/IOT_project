#define WaterSensor A1

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
}

void loop() {
  int WaterValue=analogRead(WaterSensor);
  Serial.println(WaterValue);
   if(WaterValue>450 && WaterValue<500){
    digitalWrite(9, HIGH);
    delay(10);
    digitalWrite(9, LOW);
   }
   else if(WaterValue >= 500){
      for(int i=0; i<3;i++){
           digitalWrite(9, HIGH);
           delay(10);
           digitalWrite(9, LOW);
        }
    }
    else
      digitalWrite(9, LOW);

    delay(1000);

}
