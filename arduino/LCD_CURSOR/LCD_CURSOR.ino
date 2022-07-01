#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

long Count = 0;

void setup( ){
lcd.init( );
lcd.backlight( );
lcd.setCursor(2,0);
lcd.print("IoT Smart SW");
lcd.setCursor(0,1);
lcd.print(" Count = ");
Serial.begin(9600);
}

void loop( ){
  lcd.setCursor(9, 1);
  lcd.print(Count);
  delay(100);
  if (++Count>999999)
    Count=0;
}
