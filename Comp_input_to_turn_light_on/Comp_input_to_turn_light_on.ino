#define pin 9

void setup() {
  pinMode(pin, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0){
  int input = Serial.read();
  if(input==1){
  digitalWrite(pin,HIGH);
  Serial.print("input=1");}
  else if (input==0)
  digitalWrite(pin,LOW);
  }
  }
