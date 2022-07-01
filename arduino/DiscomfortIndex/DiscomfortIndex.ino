#include "DHT11.h"
#include <LiquidCrystal_I2C.h>
#define DHT11_pin 7
DHT11 dht11(DHT11_pin);
float temp, humi, dIndex;
int err;
LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

}
float DIndex(float t, float h) {
return (1.8f*t)-(0.55*(1-h/100.0f)*(1.8f*t-26))+32;
}
void loop( ){
  err=dht11.read(humi, temp);
  if(err) {
    Serial.print("Error");
  }
  else {
    dIndex=DIndex(temp,humi);
    Serial.print(temp);
    Serial.print(",");
    Serial.print(humi);
    Serial.print(",");
    Serial.println(dIndex);
  }
  if(dIndex<68){
    lcd.print("Comfortable");
    delay(1000);
    }
  else if(dIndex<75){
    lcd.setCursor(0,0);
    lcd.print("Little bit");
    lcd.setCursor(0,1);
    lcd.print("Uncomfortable");
    delay(1000);
    }
  else if(dIndex<80){
    lcd.print("Uncomfortable");
    delay(1000);
    }
  else{
    lcd.print("Annoying");
    delay(1000);
    }
    lcd.clear();
    delay(1000);
    
}
