#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include "pitches.h"

#define Buzz1 4
#define Buzz2 5

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
int currentMelody = 0;

const byte ROWS = 4;
const byte COLS = 4;

byte KeyRow[ROWS] = { 6, 7, 8, 9 };
byte KeyCol[COLS] = { 13, 12, 11, 10 };
byte PW[4] = { '1', '2', '3', '4' };
byte KeyBuff[4];
byte BuffPoint=0;

char KeyCode[ROWS][COLS]={
{'0', '1' ,'2' ,'3'},
{'4', '5', '6', '7'},
{'8', '9', ':', ';'},
{'<', '=', '>', '?'} };

Keypad keypads = Keypad( makeKeymap(KeyCode),KeyRow,KeyCol,ROWS,COLS);

int melodySize = 75;
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, 
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0
};

int tempo[] = {
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 
  9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

void sing() {
    if(millis() < prevPlayTime + playDuration) {
        // music is playing. do nothing
        return;
    }
    noTone(8);
    
    if(currentMelody >= melodySize)
        currentMelody = 0;
    int noteDuration = 1000/tempo[currentMelody];

    tone(Buzz1, melody[currentMelody], noteDuration);
    prevPlayTime = millis();
    playDuration = noteDuration * 1.30;
    
    currentMelody++;
}

void buttonSound(){
    tone(Buzz2,391, 47.619047619);
    delay(70);
    noTone(Buzz2);
}

void setup() {
  Serial.begin(9600);
   lcd.init( );    
   lcd.backlight();
   lcd.setCursor(0,1);
   
   pinMode(Buzz1,OUTPUT); 
   pinMode(Buzz2,OUTPUT); 
}

void loop() {
  char key=keypads.getKey( );
  int keyx = key & 0x0f;
  sing();
  //Serial.print("+");
  if (key){
    buttonSound();
    Serial.print("@");
    Serial.println(keyx); 
  }
}
