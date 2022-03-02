//Rotates a dc motor 

#define EN1 4
#define IN1 8
#define IN2 9


void setup() {
pinMode(EN1, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
Serial.begin(9600);
}

void loop() {

 //turns motor in forward direction
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  for(int velocity=1;velocity<=200;velocity+=2){
  analogWrite(EN1, velocity);
  Serial.print("Speed is ");
  Serial.print(velocity);
  Serial.println(" forward.");
  delay(1000);
  }
  
//turns in opposite direction now
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  for(int velocity=255;velocity>=1;velocity-=2){
  analogWrite(EN1, velocity);
  Serial.print("Speed is ");
  Serial.print(velocity);
  Serial.println(" backward.");
  delay(50);
  }

}
