void setup( ) {
  Serial.begin(9600);
}
void loop( ) {
  
  if (Serial.available( )){
    
     unsigned char inByte = Serial.read( );
     Serial.write(inByte);
     Serial.print(" (");
     Serial.print(inByte);
     Serial.println(") Received");
     
  }
}
