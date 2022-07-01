void serialPrint(){
  #ifdef SERIAL_MONITOR 
    Serial.print(" xValue = "); 
  #endif
    Serial.print(xValue);
    Serial.print(",");
  #ifdef SERIAL_MONITOR 
    Serial.print(" yValue = "); 
  #endif
    Serial.print(yValue);
    Serial.print(",");
  #ifdef SERIAL_MONITOR 
    Serial.print(" Button = ");
    Serial.println(btn);
  #else 
    Serial.println(btn*100); 
  #endif
}
