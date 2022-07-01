#include "DHT11.h"
#include <LiquidCrystal_I2C.h>
#define DHT11_pin 7
DHT11 dht11(DHT11_pin);
float temp, humi;
int err;
LiquidCrystal_I2C lcd(0x27, 16,2);
int analogValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

}

void loop() {
  analogValue = analogRead(A0);
  if((err=dht11.read(humi, temp))==0){   //큰 if문
       if(analogValue > 600){   //작은 if 어두움
          lcd.setCursor(9,0);
          lcd.print("Dark");
          
          lcd.setCursor(0,0);
          lcd.print("HUM:");
          lcd.setCursor(4,0);
          lcd.print((int)humi);
          lcd.print("%");
          
          lcd.setCursor(0,1);
          lcd.print("TMP:");
          lcd.setCursor(4,1);
          lcd.print((int)temp);
          lcd.print("\337");
          lcd.print("C");
         }
       else{                     //작은 else 밝음
          lcd.setCursor(9,0);
          lcd.print("Bright");
          
          lcd.setCursor(0,0);
          lcd.print("HUM:");
          lcd.setCursor(4,0);
          lcd.print((int)humi);
          lcd.print("%");
          
          lcd.setCursor(0,1);
          lcd.print("TMP:");
          lcd.setCursor(4,1);
          lcd.print((int)temp);
          lcd.print("\337");
          lcd.print("C");
          }
          
          Serial.print("temp: ");  //시리얼 모니터 확인용
          Serial.println(temp);
          //Serial.print(',');
          Serial.print("humi: ");
          Serial.print(humi);
          Serial.println();
      }
    
  else{                            //큰 else문
    Serial.println();
    Serial.print("Error No: ");
    Serial.print(err);
    Serial.println();
    }
    
  lcd.setCursor(10,1);
  lcd.print("\"CHOI\"");  //서명
  delay(1000);
  lcd.clear();
}
