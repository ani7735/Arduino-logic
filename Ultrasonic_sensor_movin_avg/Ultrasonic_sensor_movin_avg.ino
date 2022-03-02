//Here things are in microseconds not milliseconds
//Applied a moving average filter on the ultrasonic data read
//This is also a prerequisite for the radar project 

#define ECHO_PIN 8
#define TRIG_PIN 7
#define MA 25 //Number of data points required for average.

float measurements[MA];

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);

  int distance = movin_avg(pulseIn(ECHO_PIN,HIGH,15000)/50); //timeout value set at 15000 for 3 metres
  
  Serial.println(constrain (distance, 1,300));
}

int movin_avg(int dist){
  for (int i=0;i<MA-1;i++){
  measurements[i]=measurements[i+1];
 }

measurements[MA-1]= dist;

long mean = 0;
for(int i =0; i<MA ; i++){
mean=mean+measurements[i];
}

mean=mean/MA;

return mean;

//Serial.print("Analog_input is ");
//Serial.print(measurements[MA-1]);
//Serial.print(" and mean is ");
//Serial.println(mean);
}
