unsigned char Number_1, Number_2;
unsigned long Value;
unsigned char Count=0;

void setup( ) {
Serial.begin(9600);
Serial.println("첫번째 숫자를 입력하시오");
}

void loop( ) {
  if (Serial.available( )){
      unsigned char inNumber = Serial.parseInt( );
        if (Count==0){
          Number_1=inNumber;
          Count+=1;
          Serial.println("두번째 숫자를 입력하시오");
          }
        else {
          Number_2=inNumber;
          Value=Number_1+Number_2;
          Serial.print("결과 : ");
          Serial.print(Number_1); Serial.print(" + "); Serial.print(Number_2);
          Serial.print(" = "); Serial.print(Value); Serial.println(" 입니다");
          Serial.println("첫번째 숫자를 입력하시오");
          Count=0;
        }
    }
}
