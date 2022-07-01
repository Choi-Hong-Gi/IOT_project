#include <DHT.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

#define DHT_pin 7
#define DHTTYPE DHT11

DHT dht11(DHT_pin,DHTTYPE);

int analogValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

}

void loop() {
    float temp = dht11.readTemperature();
    float humi = dht11.readHumidity();
    analogValue = analogRead(A0);
    Serial.print("analogValue = ");
    Serial.println(analogValue);
    if(analogValue > 600){
      Serial.print("temp :");
      Serial.print(temp);
      Serial.print(" humi :");
      Serial.println(humi);

      lcd.setCursor(0,0);
      lcd.print("Dark");
      
      lcd.setCursor(7,0);
      lcd.print("HUM:");
      lcd.setCursor(11,0);
      lcd.print(humi);
      
      lcd.setCursor(0,1);
      lcd.print("TMP:");
      lcd.setCursor(4,1);
      lcd.print(temp);
      }
     else{
      Serial.print("temp :");
      Serial.print(temp);
      Serial.print(" humi :");
      Serial.println(humi);
      
      lcd.setCursor(0,0);
      lcd.print("Bright");
      
      lcd.setCursor(7,0);
      lcd.print("HUM:");
      lcd.setCursor(11,0);
      lcd.print(humi);
      
      lcd.setCursor(0,1);
      lcd.print("TMP:");
      lcd.setCursor(4,1);
      lcd.print(temp);
      }
      
      delay(1000);
      lcd.clear();
  }
