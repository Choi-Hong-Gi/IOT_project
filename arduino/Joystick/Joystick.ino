//#define SERIAL_MONITOR
#define SERIAL_PLOTTER

#define Yaxis A0
#define Xaxis A1
#define Button A2

int xValue,yValue,btn;

#include "SerialPlot.h"

void setup( ) {
  Serial.begin(9600);
  pinMode(Button,INPUT_PULLUP);
}

void loop() {
//  xValue =analogRead(Xaxis);
//  yValue =analogRead(Yaxis);
//  btn=digitalRead(Button);
//  //Serial.print(" X = ");
//  Serial.print(xValue);
//  Serial.print(",");
//  //Serial.print(" Y = ");
//  Serial.print(yValue);
//  Serial.print(",");
//  //Serial.print(" Button = ");
//  Serial.println(btn*500);

  xValue =analogRead(Xaxis);
  xValue = map(xValue,0,1023,-100,100);
  yValue =analogRead(Yaxis);
  yValue = map(yValue,0,1023,-100,100);
  btn=digitalRead(Button);
  
  serialPrint( );
}
