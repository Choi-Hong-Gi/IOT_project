#include "DHT11.h"
//#include <LiquidCrystal_I2C.h>
#define DHT11_pin 7

DHT11 dht11(DHT11_pin);
float temp, humi;
int err;
//LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
//  lcd.init();
//  lcd.backlight();
  Serial.begin(9600);

}

void loop() {
  if((err=dht11.read(humi, temp))==0){
//     lcd.setCursor(0,0);
//     lcd.print("HUM:");
//     lcd.setCursor(4,0);
//     lcd.print(humi);
//     lcd.setCursor(0,1);
//     lcd.print("TMP:");
//     lcd.setCursor(4,1);
//     lcd.print(temp);

      
    Serial.print("temp: ");
    Serial.println(temp);
    //Serial.print(',');
    Serial.print("humi: ");
    Serial.print(humi);
    Serial.println();
    }
  else{
    Serial.println();
    Serial.print("Error No: ");
    Serial.print(err);
    Serial.println();
    }
delay(1000);
}
