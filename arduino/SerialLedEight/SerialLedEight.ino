unsigned char LED[8] = {9, 8, 7, 6, 5, 4, 3, 2};

unsigned char Mask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
                       // 128,   64,   32,   16,    8,    4,     2,    1
             //    10000000   1000000  100000  10000  1000  0100  0010  0001
             
             // 1<<inByte: 1을 입력값(0~7) 만큼 왼쪽으로 밀어냄
             //               -> inByte
             // 밀어낸 값과 마스크 값(1~128) 비교
unsigned char LED_Buff = 0x00;


void setup( ) {
  for (int k = 0; k < 8; k++)
    pinMode(LED[k], OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available( )){
    unsigned char inByte = Serial.parseInt( );
    if (inByte>7){
      Serial.print(inByte);
      Serial.println(" LED failed");
    }
      else {
      LED_Buff = 1<<inByte;
      for (int k = 0; k < 8; k++) 
        digitalWrite(LED[k], LED_Buff & Mask[k]);
        Serial.print(inByte);
        Serial.println(" LED ok!");
    }
  }
}
