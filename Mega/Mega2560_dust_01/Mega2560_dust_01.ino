float dustDensity = 0;

void setup( ) {
  Serial.begin(9600);
  for (int k=0; k<500;k++){
    dustDensity=DustDensity_ugPm3(k);
    Serial.println(dustDensity);
    }
}

void loop( ) {
}

float DustDensity_ugPm3(int Vin) { 
  float Density=(float)Vin/5.8-0.1;
  return Density;
}
