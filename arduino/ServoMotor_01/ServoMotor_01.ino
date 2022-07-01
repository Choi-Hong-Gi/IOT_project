#include <Servo.h>

#define ServoPin 3 // PWM: ~ port

Servo myServo; // 12개 까지 선언 가능

int Angle = 0; //Servo Position in Degrees

void setup(){
  myServo.attach(ServoPin); // attach: servo pin mode
}

void loop() {

}
