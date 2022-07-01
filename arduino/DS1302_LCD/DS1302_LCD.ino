#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SCK_PIN 6
#define IO_PIN 7
#define RST_PIN 8

DS1302 rtc(RST_PIN, IO_PIN, SCK_PIN);

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
//  rtc.halt(false);
//  rtc.writeProtect(false);
//  rtc.setDOW(MONDAY);
//  rtc.setTime(11,36,0);
//  rtc.setDate(02,05,2022);
}

void loop() {
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  Serial.println(rtc.getTimeStr());

  lcd.clear();
  printDate();
  printTime();
  
  delay(1000);
}

void printDate(){
  lcd.setCursor(0,0);
  lcd.print(rtc.getDOWStr()); // 요일
  
  lcd.setCursor(3,1);
  lcd.print(rtc.getDateStr()); // 날짜
}

void printTime(){
  lcd.setCursor(8,0);
  lcd.print(rtc.getTimeStr()); // 시간
}
