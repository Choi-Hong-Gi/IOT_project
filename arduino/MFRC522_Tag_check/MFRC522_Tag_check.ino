#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define buzzer 6

MFRC522 mfrc522(SS_PIN, RST_PIN);

//int LED_Y = 3;
//int LED_R = 4;

//RING UID: 0x13, 0xCC, 0x39, 0x18
//Card UID: 0xA2, 0xF4, 0x4E, 0x1B

byte SetID[8]={0x13, 0xCC, 0x39, 0x18};

void setup(){
  Serial.begin(9600);
  SPI.begin();
//  pinMode(LED_Y,OUTPUT);
//  pinMode(LED_Y,OUTPUT);
  pinMode(buzzer,OUTPUT);
  mfrc522.PCD_Init();
  Serial.println("MFRC522 Ready");
}

void loop(){
  if ( !mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial() ){
    delay(500);
    return;
  }
  if(mfrc522.uid.uidByte[0] == SetID[0] && 
    mfrc522.uid.uidByte[1] == SetID[1] && 
    mfrc522.uid.uidByte[2] == SetID[2] && 
    mfrc522.uid.uidByte[3] == SetID[3]){
//    digitalWrite(LED_Y,HIGH);
//    digitalWrite(LED_R,LOW);
    Serial.println("Hello, arduino~");
    tone(6,423,100);
    delay(100);
    tone(6,473,100);
    delay(100);
    tone(6,523,100);
    delay(500);
  }
  else{
//    digitalWrite(LED_R,HIGH);
//    digitalWrite(LED_Y,LOW);
    Serial.println("Who are you?");
    tone(buzzer,423,100);
    delay(300);
    tone(buzzer,423,100);
    delay(500); 
  }
}
