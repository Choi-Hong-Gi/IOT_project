//
//const int sensorMin = 0;
//const int sensorMax = 1024;
//
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(9, OUTPUT);
//}
//
//void loop() {
//  int sensorReading = analogRead(A0);
//  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
////  Serial.println(sensorReading);
//  switch(range){
//      case 0:
//        Serial.println("**Close Fire**");
//        
//        break;
//      case 1:
//        Serial.println("**Distant Fire**");
//        digitalWrite(9, HIGH);
//        break;
//      case 2:
//        Serial.println("**No Fire**");
//        break;
//    }
//    delay(100);
//}

// lowest and highest sensor readings:
const int sensorMin = 0; // sensor minimum
const int sensorMax = 1024; // sensor maximum
void setup() { 
// initialize serial communication @ 9600 baud:
Serial.begin(9600); 
pinMode(9, OUTPUT);
} 
void loop() { 
// read the sensor on analog A0:
int sensorReading = analogRead(A0); 
// map the sensor range (four options):
// ex: 'long int map(long int, long int, long int, long int, long int)'
//int range = map(sensorReading, sensorMin, sensorMax, 0, 3); 
// range value:
digitalWrite(9, LOW);
//switch (range) 
//{ 
//case 0: // A fire closer than 1.5 feet away.
//Serial.println("** Close Fire **"); 
//break; 
//case 1: // A fire between 1-3 feet away.
//Serial.println("** Distant Fire **"); 
//digitalWrite(9, HIGH);
//break; 
//case 2: // No fire detected.
//Serial.println("No Fire"); 
//break; 
//} 
if(sensorReading<900)
  digitalWrite(9, HIGH);
Serial.println(sensorReading);
delay(100); // delay between reads
}
