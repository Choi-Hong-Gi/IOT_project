#include <Keypad.h>

const int BUZZER_PIN = 3;
const byte ROWS = 4;
const byte COLS = 4;

//byte KeyRow[ROWS] = { 4, 5, 6, 7 };
//byte KeyCol[COLS] = { 11, 10, 9, 8 };
byte KeyRow[ROWS] = { A1, A0, 2, 4 };
byte KeyCol[COLS] = { A2, A3, A4, A5 };
char KeyCode[ROWS][COLS] = {{ '1', '2', '3', 'A' }, { '4', '5', '6', 'B' },
                            { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }};

int tones[]={ 262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 987, 1046, 1174 };

Keypad keypads = Keypad( makeKeymap(KeyCode),
                        KeyRow, KeyCol, ROWS, COLS );
                        
void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypads.getKey();
  if (key){
    Serial.println(key);
    sound_loop(key);
  }
}

void sound_loop(char Key){
  //Serial.print(Key); 
  if(Key == '0'){PiezoTones(0);}
  if(Key == '1'){PiezoTones(1);}
  if(Key == '2'){PiezoTones(2);}
  if(Key == '3'){PiezoTones(3);}
  if(Key == '4'){PiezoTones(4);}
  if(Key == '5'){PiezoTones(5);}
  if(Key == '6'){PiezoTones(6);}
  if(Key == '7'){PiezoTones(7);}
  if(Key == '8'){PiezoTones(8);}
  if(Key == '9'){PiezoTones(9);}
  if(Key == 'A'){PiezoTones(10);}
  if(Key == 'B'){PiezoTones(11);}
  if(Key == 'C'){PiezoTones(12);}
  if(Key == 'D'){PiezoTones(13);}
  if(Key == '*'){PiezoTones(14);}
  if(Key == '#'){PiezoTones(15);}
}

void PiezoTones(int t){
  tone(BUZZER_PIN,tones[t]+1000);
  Serial.println(tones[t]); 
  delay(200);
  noTone(BUZZER_PIN);
}
