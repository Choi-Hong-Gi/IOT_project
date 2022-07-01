#define RAIN_STEAM A0


void setup( ) {
  Serial.begin( 9600 );
  pinMode( RAIN_STEAM, INPUT );
}

void loop( ) {
  Serial.print( "Rain/Steam : " );
  Serial.println( analogRead( RAIN_STEAM ) );
  delay(200);
}

