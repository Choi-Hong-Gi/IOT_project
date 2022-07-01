#define CdS A5
int ledA = 5;
int adValue;
int brightness = 0;

void setup()
{
  Serial.begin(9600);
//  pinMode(ledA,OUTPUT);
}

void loop()
{
  adValue = analogRead(CdS);
  
  Serial.print("CdS = ");
  Serial.println(adValue);
  brightness = (int) adValue-345; //200~600
  if(brightness>255){
      brightness = 255;
    }
   else if(brightness<0){
      brightness = 0;
    }
  analogWrite(ledA, brightness);
//  delay(10);
  Serial.println(brightness);
//  if(adValue > 500){
//    digitalWrite(7,HIGH);
//  }
//  else{
//    digitalWrite(7,LOW);
//  }
//  delay(10);
}
