#include <DS1302.h>
#define SCK_PIN 6
#define IO_PIN 7
#define RST_PIN 8

DS1302 rtc(RST_PIN, IO_PIN, SCK_PIN);

Time thisTime;

void setup( ){
  rtc.halt(false);
  rtc.writeProtect(false);
//  rtc.setDOW(MONDAY); // Set Day-of-Week to MONDAY
//  rtc.setTime(11, 21, 30); // Set the time to 10:54:00 (24hr format)
//  rtc.setDate(9, 5, 2022); // Set the date to April 3th, 2019
  Serial.begin(9600);
}

void loop() {
  thisTime = rtc.getTime();
  Serial.print(thisTime.year, DEC);
  Serial.print("-");
  Serial.print(thisTime.mon, DEC);
  Serial.print("-");
  Serial.print(thisTime.date, DEC);
  Serial.print("   ");
  Serial.print(thisTime.hour, DEC);
  Serial.print(":");
  Serial.print(thisTime.min, DEC);
  Serial.print(":");
  Serial.println(thisTime.sec, DEC);
  delay (1000);
}
