#define DUST_LED A2
#define DUST_OUT A3
#define SPP_Packet_length 4

#include <SPP.h>
#include <SPI.h>
#include <stdlib.h>

USB Usb;
BTD Btd(&Usb);
SPP SerialBT(&Btd, "CHOIS-BT", "2475");

unsigned char SPP_data[SPP_Packet_length] = {'@', 'D', 0xff, '\n' };
unsigned char dustDensity_[5];

int DustADC = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(115200);
  
  if (Usb.Init( ) == -1) {
    Serial.println(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.println(F("\r\nSPP Bluetooth Library Started"));
  
  pinMode(DUST_LED, OUTPUT);
  pinMode(DUST_OUT, INPUT);
  digitalWrite(DUST_LED, HIGH);
}

void loop() {
  Usb.Task();
  
  DustADC = SensorRead();
  dustDensity = DustDensity_ugPm3(DustADC);
  //Serial.println((int)dustDensity);
  if (SerialBT.connected) {
    SPP_data[2] = itoa((int)dustDensity, dustDensity_, 10);
    SerialBT.write(SPP_data, SPP_Packet_length);
    Serial.print("Dust[ug/m3]: ");
    Serial.println(dustDensity);
  }
  delay(200);
}

unsigned int SensorRead(void){
  unsigned int Sensor_data;
  
  digitalWrite(DUST_LED, LOW);
  delayMicroseconds(280);
  
  Sensor_data = analogRead(DUST_OUT);
  delayMicroseconds(40);
  
  digitalWrite(DUST_LED, HIGH);
  delayMicroseconds(9680);
  
  return Sensor_data;
}

float DustDensity_ugPm3(int Vin) { 
  float Density = (float)Vin/5.8-0.1;
  return Density;
}
