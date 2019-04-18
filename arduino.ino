#define sensor  A0
#define led 13
#define heater 10
#define fan 9


int sensorValue = 0;
int treshold = 300;
int count = 0;
int minNumberOfEqualReadings = 5;
int equalReadings = 0;




void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode (led,OUTPUT);
  digitalWrite (led, LOW);
}


void loop() {

  // read the input on analog pin 0:
  sensorValue = analogRead(sensor);

  if (sensorValue < treshold){
      equalReadings++;
  } else {
      equalReadings=0;
  }

  if (equalReadings >= minNumberOfEqualReadings){
      Serial.write(1);
      digitalWrite (led, HIGH);
      equalReadings = 0;
  } else {
      digitalWrite (led, LOW);  
  }
  
  delay(50);        // delay in between reads for stability
}
