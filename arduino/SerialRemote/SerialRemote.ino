#define _Header '@'
#define _CR 0x0d //줄바꿈?

unsigned char LED[8] = {9, 8, 7, 6, 5, 4, 3, 2};
unsigned char ReceiveString[10];
unsigned char ReceivePoint = 0;
bool stringComplete = false;

void setup( ) {
  Serial.begin(9600);
  for (int k = 0; k < 8; k++)
    pinMode(LED[k], OUTPUT);
}
void loop( ) {
  
if (stringComplete){
  Rx_Processing();
  }
}

void serialEvent( ) {
    while (Serial.available()) {
      char inChar = (char)Serial.read();
      ReceiveString[ReceivePoint]=inChar;
      ReceivePoint++;
      if (inChar == _CR) {
        stringComplete = true;
        ReceivePoint=0;
    }
  }
}
void Rx_Processing( ){
  int LED_No=ReceiveString[1] & 0x0f;
  int LED_Status;
  
  if (ReceiveString[2]=='o')
      LED_Status = 1;
  else
      LED_Status = 0;
  
  digitalWrite(LED[LED_No], LED_Status);
  Serial.print("LED ");
  Serial.print(LED_No);
  Serial.print(" = ");
  if (LED_Status)
      Serial.println(" on");
  else
      Serial.println(" off");
  stringComplete=false;
}
