#include <Servo.h>
#define ServoPin 3
#define VolumePin A0

Servo servo;

int Angle = 0; //Servo Position in Degrees

void setup() {
  Serial.begin(9600);
  servo.attach(ServoPin);
}

void loop( ) {
  int Volume = analogRead(VolumePin);
  Angle = map ( Volume, 0, 1023, 0, 180 ); 
  servo.write (Angle);
  Serial.print ("Angle = ");
  Serial.println (Angle);
  delay(100);
}
