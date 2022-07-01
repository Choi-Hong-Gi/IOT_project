#include <SimpleDHT.h>

int DHT_pin=7;

SimpleDHT11 dht11(DHT_pin); 

byte temp = 0;
byte humi = 0;


void setup( ) {
  //digitalRead(DHT_pin);
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
  //Serial.print("Sample OK: ");
  Serial.print((int)temp);
  //Serial.print(" *C, "); 
  Serial.print((int)humi);
  //Serial.println(" H");
  delay(2000);
}
