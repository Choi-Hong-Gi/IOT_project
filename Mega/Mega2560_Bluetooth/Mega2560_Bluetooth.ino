#include <SPP.h>
#include <SPI.h>

USB Usb;
BTD Btd(&Usb);
SPP SerialBT(&Btd, "CHOIS-BT", "2475");

bool firstMessage = true;

void setup() {
  Serial.begin(115200);

  if (Usb.Init() == -1) {
    Serial.println(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.println(F("\r\nSPP Bluetooth Library Started"));
              //F = 문자열로 형변환 하지 않고 대입
}

void loop() {
  Usb.Task();

  if (SerialBT.connected) {

    if (firstMessage) {
      firstMessage = false;
      SerialBT.println(F("Hello from Arduino")); // Send welcome message
    }

    if (Serial.available())
      SerialBT.write(Serial.read());

    if (SerialBT.available())
      Serial.write(SerialBT.read());

  }
  
  else {
    firstMessage = true;
  }

}
