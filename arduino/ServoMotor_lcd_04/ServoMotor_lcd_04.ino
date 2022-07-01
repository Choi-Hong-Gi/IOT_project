#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define ServoPin 3
#define VolumePin A0 // joystick도 가능

Servo servo;
LiquidCrystal_I2C lcd(0x27,16,2);

int Angle = 0; //Servo Position in Degrees

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Servo Motor");
  Serial.begin(9600);
  servo.attach(ServoPin);
}

void loop( ) {
  int Volume = analogRead(VolumePin);
  Angle = map ( Volume, 0, 1023, 0, 180 ); 
  servo.write (Angle);
  Serial.print ("Angle = ");
  Serial.println (Angle);
  delay(15);
  SelcdDisplay(Angle);
}

void SelcdDisplay(int Angle){
  Serial.print ( "Angle = " );
  Serial.println ( Angle );
  lcd.setCursor(2,0);
  lcd.print("Servo Motor"); 
  lcd.setCursor(2,1);
  lcd.print("Angle = "); 
  lcd.print(String(Angle) + char(0xdf)); // n'
  delay(100);
  lcd.clear();
}
