#define ButtonPin 5
#define LED_PIN 9

int led_state = LOW;
int pre_button_state = HIGH;

void setup() {
pinMode(LED_PIN, OUTPUT);
pinMode(ButtonPin, INPUT);  
}

void loop() {
  int button_state = digitalRead(ButtonPin);

  if(button_state != pre_button_state){
    if(button_state == HIGH && pre_button_state == LOW){
      if(led_state == LOW)
        led_state = HIGH;
      else
        led_state = LOW;
      }
      pre_button_state = button_state;
    }
    digitalWrite(LED_PIN,led_state);
}
