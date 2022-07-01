#define TILT A0

void setup() {
  Serial.begin(9600);
  pinMode(TILT , INPUT_PULLUP);
}

void loop() {
  if ( !digitalRead( TILT ) ){
    Serial.println( "Sensor was Tilted" );
  }
  else {
    Serial.println( "*" );
  }
  delay(1000);
}