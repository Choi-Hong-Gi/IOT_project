int Tilt = 2;
int sound = 3;
int TiltState =0;

void setup() {
  Serial.begin(9600);
  pinMode(Tilt, INPUT);
  attachInterrupt(digitalPinToInterrupt(Tilt), Tilt_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(Tilt), Sound_ISR, RISING);
  pinMode(7,OUTPUT);
  pinMode(sound,OUTPUT);

}

void loop() {
  if (TiltState) {
    Serial.println("Tilt on");
  TiltState=0;
  digitalWrite(7,LOW);
  digitalWrite(sound,LOW);
  } 
delay(300);
}

void Tilt_ISR(){
  TiltState=1;
  digitalWrite(7,HIGH);
}
void Sound_ISR(){
  digitalWrite(sound,HIGH);
}
