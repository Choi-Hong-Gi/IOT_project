#include <IRremote.h>
#define TSOP38x 11

IRrecv IR(TSOP38x); // 적외선 센서가 연결된 디지털 핀 번호 매핑
decode_results result; // 수신된 적외선 신호를 저장할 변수

void setup() {
  IR.enableIRIn(); // 적외선 센서 활성화
  Serial.begin(9600);
  Serial.println("IR Ready!");
}

void loop() {
  if (IR.decode(&result)){
    Serial.println(result.value,HEX);
    IR.resume();
  }
  delay(250);
}
