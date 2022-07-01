#include <SPP.h>
#include <SPI.h>

#define RAIN_STEAM 2
#define TX_Event_Packet_length 4
unsigned char TX_Event_data[TX_Event_Packet_length] = {'@', 'T', '0', '\n' };
unsigned char TX_Event_flag = 0;

USB Usb;
BTD Btd(&Usb);
SPP SerialBT(&Btd, "CHOIS-BT", "2475");

bool firstMessage = true;

uint8_t RAIN_STEAM_Value = 0, RAIN_STEAM_pre = 0;
uint32_t Time_check_RAIN_STEAM = 0;


void setup() {
  Serial.begin(115200);

  if (Usb.Init() == -1) {
    Serial.println(F("\r\nOSC did not start"));
    while (1); //HOLD
  }
  Serial.println(F("\r\nSPP Bluetooth Library Started"));
              //F = 문자열로 형변환 하지 않고 대입

  pinMode(RAIN_STEAM, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RAIN_STEAM), RAIN_STEAM_ISR, CHANGE);
}

void loop() {
  Usb.Task( );
  if (SerialBT.connected) {
    
    if(TX_Event_flag == 1) {
      
      SerialBT.write(TX_Event_data, TX_Event_Packet_length);
      Serial.print("\n\rTX Event Packet :");
      for (int k=0;k<TX_Event_Packet_length;k++){
        Serial.print(TX_Event_data[k],HEX); 
      }
      Serial.println( );
      TX_Event_flag = 0;
    }
    if (Serial.available())
      SerialBT.write(Serial.read( ));
    if (SerialBT.available())
      Serial.write(SerialBT.read( ));
  }
  if((Time_check_RAIN_STEAM + 250) < millis( )) {
    if(RAIN_STEAM_pre != RAIN_STEAM_Value) {
      RAIN_STEAM_pre = RAIN_STEAM_Value;
      TX_Event_data[2] = RAIN_STEAM_Value | 0x30;
      TX_Event_flag = 1;
      
    }
  }
}

void RAIN_STEAM_ISR(void) {
  RAIN_STEAM_Value = !digitalRead(RAIN_STEAM);
  Time_check_RAIN_STEAM = millis();
}
