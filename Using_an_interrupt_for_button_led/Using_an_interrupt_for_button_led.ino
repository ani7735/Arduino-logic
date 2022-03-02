//pins 
const uint8_t btn_pin = 2;
const uint8_t led_pin = 5;

//globals
uint8_t led_state = LOW;


void setup() {
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(btn_pin), toggle, FALLING);
}
void loop() {
  
    delay(500);
}
void toggle(){
  
  led_state =! led_state; // converts led state to opposite 
  digitalWrite(led_pin, led_state);
  
  }
