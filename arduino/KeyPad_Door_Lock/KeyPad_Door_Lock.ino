#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


#define ServoPin 3
#define SS_PIN 10
#define RST_PIN 9
#define buzzer 6

LiquidCrystal_I2C lcd(0x27, 16, 2);

MFRC522 mfrc522(SS_PIN, RST_PIN);

Servo servo;

//RING UID: 0x13, 0xCC, 0x39, 0x18
//Card UID: 0xA2, 0xF4, 0x4E, 0x1B
//BusCard UID: 0xA4, 0x29, 0x76, 0x8A

byte SetID[8]={0xA2, 0xF4, 0x4E, 0x1B};

unsigned int cnt = 0;

const byte ROWS = 4;
const byte COLS = 4;
byte KeyRow[ROWS] = { A1, A0, 2, 4 };
byte KeyCol[COLS] = { A2, A3, A4, A5 };
char KeyCode[ROWS][COLS] = {{ '1', '2', '3', 'A' }, { '4', '5', '6', 'B' },
                            { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }};

Keypad keypads = Keypad( makeKeymap(KeyCode),
                        KeyRow, KeyCol, ROWS, COLS );

//byte PWD[4]={'1', '2', '3', '4'};

void setup(){ 
  Serial.begin(9600);
  lcd.init( );
  lcd.backlight( );

//  servo.attach(ServoPin);
//  servo.write(0);
//    
//  SPI.begin();
//  pinMode(buzzer,OUTPUT);
//  
//  mfrc522.PCD_Init();
  
  
  Serial.println("Door Ready");
}

void loop(){
  char key = keypads.getKey();
  if (key){
    Serial.println(key);
  }

//  lcd.clear();
//  lcd.setCursor(1, 0);
//  lcd.print("Please tap the");
//  lcd.setCursor(1, 1);
//  lcd.print("card to open!");
//  delay(100);
//  if ( !mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial() ){
//    delay(500);
//    return;
//  }
//  if(mfrc522.uid.uidByte[0] == SetID[0] && 
//    mfrc522.uid.uidByte[1] == SetID[1] && 
//    mfrc522.uid.uidByte[2] == SetID[2] && 
//    mfrc522.uid.uidByte[3] == SetID[3]){
//      cnt = 0;
//      servo.write(180);
////    digitalWrite(LED_Y,HIGH);
////    digitalWrite(LED_R,LOW);
//    Serial.println("Hello, arduino~");
//    lcd.clear();
//    lcd.setCursor(1, 0);
//    lcd.print("Hello, arduino!");
//    lcd.setCursor(1, 1);
//    lcd.print("Door is open!");    
//    tone(6,2093,500);
//    delay(300);
//    tone(6,2637,500);
//    delay(300);
//    tone(6,3136,500);
//    delay(500);
//    
//    delay(10000);
//    servo.write(-180);
//    tone(6,3136,500);
//    delay(300);
//    tone(6,2637,500);
//    delay(300);
//    tone(6,2093,500);
//    delay(500);
//  }
//  else{
//    cnt++;
////    digitalWrite(LED_R,HIGH);
////    digitalWrite(LED_Y,LOW);
//    Serial.println("Who are you?");
//    lcd.clear();
//    lcd.setCursor(2, 0);
//    lcd.print("Who are you?");
//    lcd.setCursor(2, 1);
//    lcd.print("try (");
//    lcd.print(cnt);
//    lcd.print("/5)");
//    tone(buzzer,423,100);
//    delay(300);
//    tone(buzzer,423,100);
//    delay(500);
//
//    if(cnt == 5){
//      for(int i = 0; i <30; i++){
//        lcd.clear();
//        lcd.setCursor(3, 0);
//        lcd.print("Step back!");
//        tone(buzzer,423,100);
//        delay(100);
//        tone(buzzer,623,100);
//        delay(100);
//        cnt = 0;
//      }
//      
//    }
//   //delay(1000);
//  }
  
}
