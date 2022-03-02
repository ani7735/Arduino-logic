//Analog input from the photoresotor decides analog output to the led controlling its brightness.
//Serial plotter provides clear view of the stored signal and the mean after noise cancellation through moving average.

#define led_pin 3
#define analog_input A0
#define MA 25 //Number of data points required for average.

struct data_and_mean{
  int data;
  int mean;
  };

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
 struct pom = func();
 Serial.print("Analog_input is ");
 Serial.print(pom.data);
 Serial.print(" and mean is ");
 Serial.println(pom.mean);
}

struct func(){
 static int measurements[MA]; 
 for (int i=0;i<MA-1;i++){
  measurements[i]=measurements[i+1];
 }

measurements[MA-1]= analogRead(analog_input);

data_and_mean.data = measurements[MA-1];

long mean = 0;

for(int i =0; i<MA ; i++){
mean=mean+measurements[i];
}

mean=mean/MA;

data_and_mean.mean=mean;

return data_and_mean;

}
