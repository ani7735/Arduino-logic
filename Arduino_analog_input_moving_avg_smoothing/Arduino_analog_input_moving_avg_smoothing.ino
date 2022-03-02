//Analog input from the photoresotor decides analog output to the led controlling its brightness.
//Serial plotter provides clear view of the stored signal and the mean after noise cancellation through moving average.

#define led_pin 3
#define analog_input A0
#define MA 25 //Number of data points required for average.

float measurements[MA];

void setup() {
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {

 float known_resistor = 10.00;
 float unknown_resistor;
 float V_junction = analogRead(analog_input);
 
 unknown_resistor= (50/V_junction)-10;
 
 analogWrite(led_pin, map(unknown_resistor,40,0, 0 , 255));

  
 for (int i=0;i<MA-1;i++){
  measurements[i]=measurements[i+1];
 }

measurements[MA-1]= analogRead(analog_input);

long mean = 0;
for(int i =0; i<MA ; i++){
mean=mean+measurements[i];
}

mean=mean/MA;
Serial.print("Analog_input is ");
Serial.print(measurements[MA-1]);
Serial.print(" and mean is ");
Serial.println(mean);

}
