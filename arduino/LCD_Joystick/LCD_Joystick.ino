#include <LiquidCrystal_I2C.h>
#define Yaxis A1
#define Xaxis A0
int SW_pin = 2;
int swState = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup( ){
  lcd.init( );
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  Serial.begin(9600);
}

void loop( ){
  swState = digitalRead(SW_pin);
    
  lcd.setCursor(0,0);
  lcd.print("X: ");
  lcd.setCursor(0,1);
  lcd.print("Y: ");
  
  int xValue = analogRead(Xaxis);
  lcd.setCursor(2,0);
  xValue = map(xValue,0,1023,-100,100);
  lcd.print(xValue);

  moveCursor(xValue, 0);
  
  int yValue = analogRead(Yaxis);
  lcd.setCursor(2,1);
  yValue = map(yValue,0,1023,-100,100);
  lcd.print(yValue);

  moveCursor(yValue, 1);

  if(swState == LOW){
    lcd.noBacklight();
    delay(20);
    lcd.backlight( );
    delay(20);
    lcd.noBacklight();
  }else{
    lcd.backlight( );
  }
  
  delay(20);
  lcd.clear();
  
}

void moveCursor(int value, int line){
  if(value>-3 && value < 3){
    lcd.setCursor(11,line);
    lcd.print("|");
  }else if(value>=3 && value <=25){
    lcd.setCursor(12,line);
    lcd.print("|");
  }else if(value>25 && value <=50){
    lcd.setCursor(13,line);
    lcd.print("|");
  }else if(value>50 && value <=75){
    lcd.setCursor(14,line);
    lcd.print("|");
  }else if(value>75 && value <=100){
    lcd.setCursor(15,line);
    lcd.print("|");
  }else if(value<-3 && value>-25){
    lcd.setCursor(10,line);
    lcd.print("|");
  }else if(value<=-25 && value>-50){
    lcd.setCursor(9,line);
    lcd.print("|");
  }else if(value<=-50 && value>-75){
    lcd.setCursor(8,line);
    lcd.print("|");
  }else if(value<=-75 && value>=-100){
    lcd.setCursor(7,line);
    lcd.print("|");
    }
}
