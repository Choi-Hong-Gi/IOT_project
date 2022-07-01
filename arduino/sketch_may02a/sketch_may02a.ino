#include "pitches.h"
//int buzzer = 7;
//int piezo = 6;
int piezo = 8;
int song[] = {2093,2349,2637,2793,3136,3520,3951,4186};
            //도 , 레  , 미  , 파,  솔,  라,  시 , 도
//float sinVal;
//int toneVal;
            
void setup() {
  pinMode(piezo, OUTPUT);

}

void loop() {
//  unsigned char i, j;

//  while(1){
//      for(i = 0; i <80; i++){
//        digitalWrite(buzzer, HIGH);
//        delay(1);
//        digitalWrite(buzzer, LOW);
//        delay(1);
//      }
//      for(i = 0; i <100; i++){
//        digitalWrite(buzzer, HIGH);
//        delay(2);
//        digitalWrite(buzzer, LOW);
//        delay(2);
//      }
//  }

//  analogWrite(piezo, 64);
//  delay(500);
//  analogWrite(piezo, 0);
//  delay(500);
//
//  analogWrite(piezo, 128);
//  delay(500);
//  analogWrite(piezo, 0);
//  delay(500);
//
//  analogWrite(piezo, 250);
//  delay(500);
//  analogWrite(piezo, 0);
//  delay(500);

//tone(piezo, 500, 1000);
//delay(2000);

//      for(int k = 0; k<8; k++){
//        tone(piezo,song[k],500);
//        delay(500);
//        }

// for(int freq = 150; freq<= 150; freq +=2){
//  tone(piezo,freq, 10);
//  }
//  for(int freq = 1800; freq<= 150; freq -=2){
//  tone(piezo,freq, 10);
//  delay(10);
//  }

//  for(int k = 0; k < 180; k++){
//      sinVal = sin(k*PI/180);
//      toneVal = (int)(100+1000*sinVal);
//      tone(piezo, toneVal);
//      delay(30);
//    }

}
