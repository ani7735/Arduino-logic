//Water level sensor , test

int input = 0;
void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  Serial.println(analogRead(input));

  delay(50);
}
