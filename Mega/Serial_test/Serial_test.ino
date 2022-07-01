#include <SimpleDHT.h>

#define DHT_pin 7

SimpleDHT11 dht11(DHT_pin); 

byte temp = 0;
byte humi = 0;

void setup( ) {
  Serial.begin(9600);
}

void loop( ){
  
  int err = dht11.read(&temp, &humi, NULL);

  if (err != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); 
    Serial.println(err);
    delay(1000);
    return;
    }
  
  //Serial.print("temp: ");
  Serial.print("$");
  Serial.print(temp);
  Serial.print(",");
  //Serial.print(", humi: ");
  Serial.print(humi);
  Serial.print( "\r\n" );

  delay(1000);
}
