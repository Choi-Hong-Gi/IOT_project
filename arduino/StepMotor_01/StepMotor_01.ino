#include <Stepper.h>

const int stepsPerRevolution = 2048; 
long StartTime;

Stepper step28BYJ48(stepsPerRevolution, 8, 10, 9, 11);

void setup( ) {
  step28BYJ48.setSpeed(18);
  Serial.begin(9600);
}

void loop( ) {
  Serial.println("Clockwise");
  StartTime = millis();
  step28BYJ48.step(stepsPerRevolution);
  Serial.println(millis() - StartTime);
  delay(500);
  
  Serial.println("counterClockwise");
  StartTime = millis();
  step28BYJ48.step(-stepsPerRevolution);
  Serial.println(millis() - StartTime);
  delay(500);
}
