int KeyRow[4] = { 4, 5, 6, 7 };
int KeyCol[4] = { 11, 10, 9, 8};

void setup() {
  Serial.begin(9600);
  
  for(int k=0; k<4; k++) {
    pinMode(KeyRow[k], OUTPUT);
    digitalWrite(KeyRow[k], HIGH);
    pinMode(KeyCol[k], INPUT_PULLUP);
  } 
}

void loop() {
  int nRow, nNumber;
  for(int k=0; k<4; k++) { 
    digitalWrite(KeyRow[k], LOW);
    nRow = k*4; 
    for(int m=0; m<4; m++) { 
      if ( !digitalRead(KeyCol[m])){
      nNumber = nRow + m;
      Serial.print("KEY [");
      Serial.print(nNumber, HEX);
      Serial.println("] PUSH");
      }
    }
    digitalWrite(KeyRow[k], HIGH);
    delay(100);
  }
}
