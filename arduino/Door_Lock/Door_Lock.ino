#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define Password_Length 5 // 공백문자 포함

LiquidCrystal_I2C lcd(0x27, 16, 2); 

char Master[Password_Length] = "1111"; //초기화가 0이므로 "0000"으로 하지 말 것
char Data[Password_Length];
byte data_count = 0, master_count = 0;
int signalPin = 12;
bool Pass_is_good;
const int BUZZER_PIN = 3;
const byte ROWS = 4;
const byte COLS = 4;
unsigned int tryNum = 0;
//byte KeyRow[ROWS] = { 4, 5, 6, 7 };
//byte KeyCol[COLS] = { 11, 10, 9, 8 };
byte KeyRow[ROWS] = { A1, A0, 2, 4 };
byte KeyCol[COLS] = { A2, A3, A4, A5 };

char KeyCode[ROWS][COLS] = {{ '1', '2', '3', 'A' }, { '4', '5', '6', 'B' },
                            { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }};

int tones[]={ 262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 987, 1046, 1174 };
int melody[] = {  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7  };

Keypad keypads = Keypad( makeKeymap(KeyCode), KeyRow, KeyCol, ROWS, COLS );

// 셋업     
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(signalPin, OUTPUT);
}

//메인 루프
void loop() {
  char key = keypads.getKey();
  lcd.setCursor(0,0);
  lcd.print("Enter Password: ");
  if (key){
    Serial.println(key);
    Data[data_count] = key;
    lcd.setCursor(data_count,1);
    lcd.print(Data[data_count]);
    data_count++;
    PiezoTones(7);
  }
   if(data_count == Password_Length-1){ // 7자리 입력 시
      lcd.clear(); 
      if(!strcmp(Data, Master)){  // 일치
        lcd.print("Correct");
        tryNum = 0;
        for(int j = 0; j < 9; j++){
           tone(BUZZER_PIN, melody[j]);
           delay(200);
          }
        noTone(BUZZER_PIN);
        //digitalWrite(signalPin, HIGH); 
        delay(5000); 
        //digitalWrite(signalPin, LOW);
      } 
      else{ // 불일치
        lcd.print("Incorrect");
        tryNum ++;
        lcd.setCursor(10,0);
        lcd.print("(");
        lcd.setCursor(11,0);
        lcd.print(tryNum);
        lcd.setCursor(12,0);
        lcd.print("/5)");
        for(int i  = 0; i < 2; i++){
            PiezoTones(9);
          }
        if(tryNum == 5){
          lcd.setCursor(0,0);
          lcd.print("Incorrect!");
          lcd.setCursor(0,1);
          lcd.print("Incorrect!");
          for(int k = 0; k < 20; k++){
              PiezoTones(9);
              PiezoTones(6);
          }
          tryNum = 0;
        }
        delay(1000);
      } 
      lcd.clear();
      clearData();
   }
}

void PiezoTones(int t){
  tone(BUZZER_PIN,tones[t]+1000);
  Serial.println(tones[t]); 
  delay(300);
  noTone(BUZZER_PIN);
}

void clearData( ){ 
while(data_count != 0){
  Data[data_count--] = 0;
  }
  return;
}
