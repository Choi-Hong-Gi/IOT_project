#define HC_SR06_ECHO 3
#define HC_SR06_TRIG 4
#define buzzer 7

void setup() {
  Serial.begin(9600);
  pinMode( HC_SR06_ECHO, INPUT );
  pinMode( HC_SR06_TRIG, OUTPUT );
  pinMode( buzzer, OUTPUT );

  // pinMode( 2, OUTPUT );
  // pinMode( 5, OUTPUT );
}

void loop() {

  if( Dist_cm() < 20 ){
    digitalWrite(buzzer, HIGH);
  }
  else if(Dist_cm() < 40){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else if(Dist_cm() < 70){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
  else{
    digitalWrite(buzzer, LOW);
  }

  //  if((dist != 0) && (dist < 100)){
  //  tone(buzzer, 392, 100);
  //  delay(dist*3);
  //  noTone(buzzer);
  //  delay(dist*3);
  // }else{
  //   noTone(buzzer);
  // }

  //다이렉트로 연결 가능~
  // digitalWrite(2, LOW);
  // digitalWrite(5, HIGH);

  Serial.print( "Distance : " );
  Serial.print( Dist_cm( ) );
  Serial.println( "[cm]" );
  delay(100);
}

unsigned int Dist_cm() {
  unsigned long timer = 0;
  unsigned int dist = 0;

  digitalWrite( HC_SR06_TRIG, LOW );
  delayMicroseconds( 2 );
  digitalWrite( HC_SR06_TRIG, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( HC_SR06_TRIG, LOW );
  timer = pulseIn( HC_SR06_ECHO, HIGH, 24000);

  if ( timer == 0 )
    dist = 400;
  else
    dist = timer * 0.034 / 2;

  return dist;
}