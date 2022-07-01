#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
//byte SetID[8]={0xD4,0xDF,0x06,0x85};
byte SetID[8]={0x13,0xCC,0x39,0x18};
//고리: 13 CC 39 18
//카드: A2 F4 4E 1B

void setup( ) { 
  Serial.begin(9600);
  SPI.begin( );
  mfrc522.PCD_Init( );
  Serial.println("MFRC522 Ready");
}

void loop( ) {
  if ( !mfrc522.PICC_IsNewCardPresent( ) ) { return; }
  if ( !mfrc522.PICC_ReadCardSerial( ) ) { return; }
  Serial.print("Card Chaeck:");
  for (byte k = 0; k < mfrc522.uid.size; k++) {
    if (SetID[k] != mfrc522.uid.uidByte[k]) {
      Serial.println("Failue");
      return;
    }
  } 
  Serial.println("Ok");
  delay(1000);
}
