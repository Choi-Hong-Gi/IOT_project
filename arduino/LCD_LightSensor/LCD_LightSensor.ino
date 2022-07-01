#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

int analogValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

}

void loop() {

  for(int i=0; i<10;i++){
    analogValue = analogRead(A0);
    Serial.print("analogValue = ");
    Serial.println(analogValue);
    if(analogValue > 600){
      lcd.setCursor(i,0);
      lcd.print("State:");
      lcd.setCursor(i,1);
      lcd.print("Dark");
      delay(1000);
      lcd.clear();
      }
     else{
      lcd.setCursor(i,0);
      lcd.print("State:");
      lcd.setCursor(i,1);
      lcd.print("Bright");
      lcd.scrollDisplayRight();
      delay(1000);
      lcd.clear();
      }
  }

  for(int i=9; i>0;i--){
    analogValue = analogRead(A0);
    Serial.print("analogValue = ");
    Serial.println(analogValue);
if(analogValue > 600){
      lcd.setCursor(i,0);
      lcd.print("State:");
      lcd.setCursor(i,1);
      lcd.print("Dark");
      lcd.scrollDisplayLeft();
      delay(1000);
      lcd.clear();
      }
     else{
      lcd.setCursor(i,0);
      lcd.print("State:");
      lcd.setCursor(i,1);
      lcd.print("Bright");
      lcd.scrollDisplayLeft();
      delay(1000);
      lcd.clear();
      }
   }
}
