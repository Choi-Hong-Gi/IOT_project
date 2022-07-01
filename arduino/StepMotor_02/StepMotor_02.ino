#include <Stepper.h>

const int stepsPerRevolution = 2048; 

Stepper step28BYJ48(stepsPerRevolution, 8,10,9,11);

int anglePerSecond = 2048 / 60;
long StartTime;

void setup( ) {
  step28BYJ48.setSpeed(18);
  Serial.begin(9600);
  StartTime = millis();
}

void loop( ) {
  if ((millis() - StartTime) > 999){ //1초 후
    Serial.println(millis() - StartTime);
    StartTime = millis();
    step28BYJ48.step(-anglePerSecond); 
  }
}
