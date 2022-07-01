#define Yaxis A1
#define Xaxis A0
int SW_pin = 2;
int swState = 0;
int swState1 = 0;
#include "sound.h"

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(Xaxis);
  int yValue = analogRead(Yaxis);
  Serial.print(" X = ");
  Serial.print(xValue);
  Serial.print(" Y = ");
  Serial.print(yValue);

  swState = digitalRead(SW_pin);

  if(xValue>=1000){
      digitalWrite(10, HIGH);
    }else{
        digitalWrite(10, LOW);
      }

  if(xValue<25){
      digitalWrite(11, HIGH);
    }else{
        digitalWrite(11, LOW);
      }

  if(yValue>=1000){
      digitalWrite(9, HIGH);
    }else{
        digitalWrite(9, LOW);
      }

   if(yValue<25){
      digitalWrite(8, HIGH);
    }else{
        digitalWrite(8, LOW);
      }

   if(swState == LOW){
      Serial.print(" Switch = High ");
      digitalWrite(7,HIGH);
      buzz();
    }else{
        digitalWrite(7,LOW);
      }

    swState1 = digitalRead(7);
    Serial.print(" ");
    Serial.println(swState1);
    delay(50);
}
