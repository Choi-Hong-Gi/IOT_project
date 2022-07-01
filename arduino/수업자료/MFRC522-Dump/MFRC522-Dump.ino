#include <SPI.h>
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup( ) { 
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("MFRC522 Ready");
}

void loop( ) {
  if ( !mfrc522.PICC_IsNewCardPresent( ) ) { return; }
  if ( !mfrc522.PICC_ReadCardSerial( ) ) { return; }
  mfrc522.PICC_DumpToSerial( &( mfrc522.uid));
}
