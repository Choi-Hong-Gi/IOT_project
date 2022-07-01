String rxString = "";

void setup( ) {
Serial.begin(9600);
Serial.println("이름을 입력하시오");
}

void loop( ) {
  if(Serial.available()){
   rxString = Serial.readStringUntil('\n');
  }
  if (rxString != ""){
    Serial.print(rxString);
    Serial.print(" 님 안녕하십니까?");
    Serial.print('\n');
    rxString = "";
  }
}
