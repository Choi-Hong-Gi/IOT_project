#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

#define piezo 5

LiquidCrystal_I2C lcd(0x27,16,2);

const int stepsPerRevolution = 64;
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);
int point = 0; 

void setup( ){
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
  stepper.setSpeed(220); // 속도 설정
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Stepper control");
  lcd.setCursor(0,1);
  lcd.print("Move Joystick");
  delay(2000);
  lcd.clear();
}

void loop(){
  int sensorReading = analogRead(A0); // 조이스틱 X축 A0에 연결
  Serial.println(sensorReading);
  if(point == 18){
    point=0;
  }
  if(sensorReading < 400) {
    lcd.setCursor(4,0);
    lcd.print("Step LEFT");
    lcd.setCursor(6-point%6,1);
    lcd.print(char(0x7F)); // 왼쪽 화살표
    stepper.step(15); // 시계방향으로 회전
    tone(piezo, 1000-sensorReading, 100);
    //delay(100);
    lcd.clear();
  }
  if((sensorReading >= 400)&&(sensorReading <= 600)){
    point = -1;
    lcd.setCursor(4,0); 
    lcd.print("NonMove");
    lcd.setCursor(7,1); 
    lcd.print(char(0x3D)); // =
    lcd.setCursor(8,1); 
    lcd.print(char(0x3D)); // =
    noTone(piezo);
  } 
  if(sensorReading > 600){
    lcd.setCursor(4,0);
    lcd.print("Step RIGHT");
    lcd.setCursor(9+point%6,1);
    lcd.print(char(0x7E)); // 오른쪽 화살표
    stepper.step(-15); // 반시계방향 회전
    tone(piezo, sensorReading, 100);
    //delay(100); 
    lcd.clear(); 
  }
  point++;
}
