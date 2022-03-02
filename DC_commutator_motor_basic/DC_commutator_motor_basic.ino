//Rotates dc motor in one direction then opposite using L2930 transistor

#define EN1 4
#define IN1 8
#define IN2 9


void setup() {
pinMode(EN1, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
}

void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 255);

  delay(2000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, 255);

  delay(2000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 255);

  delay(2000);
}
