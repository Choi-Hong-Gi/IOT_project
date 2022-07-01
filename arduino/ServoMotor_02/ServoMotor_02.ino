#include <Servo.h>
#define ServoPin 3
Servo servo;

int Angle = 0; //Servo Position in Degrees

void setup() {
  Serial.begin(9600);
  servo.attach( ServoPin );
}
void loop() {
  if ( Serial.available() > 0 ) {
    Angle = Serial.parseInt();
    servo.write ( Angle );
    Serial.print ( "Angle = " );
    Serial.println ( Angle );
  }
}
