//Count in binary and display on 8 LEDs
//Define connections to 74HC595
//ST_CP pin 12
const int latchPin=10; //delays ouput till the latch is high, acts like a gate till the register loads data
const int clockPin=11; //clock for the shift register itself
const int dataPin=12;
void setup() {
  // put your setup code here, to run once:
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin, OUTPUT);
}

void loop() {
  for(int num=0;num<256;num++){
    digitalWrite(latchPin, LOW);
    
    shiftOut(dataPin, clockPin, MSBFIRST, num);
   
    digitalWrite(latchPin,HIGH);

    delay(50);
  }
 }
