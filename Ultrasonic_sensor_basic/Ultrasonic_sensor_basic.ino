//Here things are in microseconds not milliseconds

#define ECHO_PIN 8
#define TRIG_PIN 7

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);

  int distance = pulseIn(ECHO_PIN,HIGH,15000)/50; //timeout value set at 15000 for 3 metres
  
  Serial.println(constrain (distance, 1,300));
}
