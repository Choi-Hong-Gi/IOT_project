#include <DS1302.h>

DS1302 rtc(8, 7, 6); // RTC, DS1302(CE,IO,SCLK)

void setup() {
  rtc.halt(false);
  rtc.writeProtect(false);
//  rtc.setDOW(MONDAY);
//  rtc.setTime(10, 49, 0); // 12:00:00 (24hr format)
//  rtc.setDate(9, 5, 2022); // 2022-05-09
  Serial.begin(9600);
}

void loop() {
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  Serial.println(rtc.getTimeStr());
  delay (1000);
}
