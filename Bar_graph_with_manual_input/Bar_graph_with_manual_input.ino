//SIMPLE PROGRAM: Here the brightness sensor is activated
                  //when you input l or L  

#define led1 2
#define led8 9
#define led_on 2
#define analog_in A0

void setup() {
  Serial.begin(9600);
  for(int i=led1;i<=led8;i++)
  pinMode (i, OUTPUT);  
}

void loop() { 
 float known_resistor = 10.00;
 float unknown_resistor;
 float V_junction = analogRead(analog_in);
 
 unknown_resistor= (50/V_junction)-10;
 
 int lastLed = map(unknown_resistor,20,9, 2 , 9);

 if (Serial.available()>0){
 char input_mode = Serial.read(); 
 if (input_mode == 'l' || input_mode == 'L'){
 Serial.print("Brightness:");
 Serial.print("\t");
 Serial.println(unknown_resistor);
    
 }
 }
 
 
 for(int i=led1;i<=lastLed;i++){
    digitalWrite(i,HIGH);
    delay(led_on);
    digitalWrite(i,LOW);
    }
 //Serial.print("Photoresisitor detects ");
 //Serial.print(unknown_resistor);
 //Serial.print(" Ohm");
 //Serial.print(" and LastLed is ");
 //Serial.println(lastLed);
 
 
 }


 
 
