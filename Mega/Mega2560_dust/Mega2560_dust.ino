#define DUST_LED A2
#define DUST_OUT A3

int DustADC = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(DUST_LED, OUTPUT);
  pinMode(DUST_OUT, INPUT);
  digitalWrite(DUST_LED, HIGH);
}

void loop() {
  DustADC = SensorRead();
  Serial.print("Dust: ");
  Serial.print(SensorRead());
  Serial.print("    ");
  Serial.print("Dust[ug/m3] : ");
  dustDensity = DustDensity_ugPm3(DustADC);
  Serial.println(dustDensity);
  delay(100);
}

unsigned int SensorRead(void){
  unsigned int Sensor_data;
  
  digitalWrite(DUST_LED, LOW);
  delayMicroseconds(280);
  
  Sensor_data = analogRead(DUST_OUT);
  delayMicroseconds(40);
  
  digitalWrite(DUST_LED, HIGH);
  delayMicroseconds(9680);
  
  return Sensor_data;
}

float DustDensity_ugPm3(int Vin) { 
  float Density = (float)Vin/5.8-0.1;
  
  return Density;
}
