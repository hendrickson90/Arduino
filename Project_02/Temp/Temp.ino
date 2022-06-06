
/*
 *  Temp reading in C and in F with searial print to baud 9600 
 *  based on project 2 temp sensor. with LED blink
 *  
 *  
 *  --Temp sensor wiring--
 *    left leg: Bread Board pos - 5v+
 *    center leg: A0
 *    right leg: Bread Board Neg - GND
 * 
 */

const int sensorPin = A0;
int sensorVal = 0;
float voltage = 0;
float temperatureC = 0;
float temperatureF = 0;

//alternating LED
bool flip = 1;



void setup() {

  //open serial port 
  Serial.begin(9600);//open serial port 


  // initialize digital pin LED_BUILTIN on board LED "L" as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {

  //alternate led "L" every other cycle
  if(flip == 1){
    digitalWrite(LED_BUILTIN, HIGH);  
    flip = 0; 
  }else{ 
    digitalWrite(LED_BUILTIN, LOW);
    flip = 1;
  }

  //read pin
  sensorVal = analogRead(sensorPin);

  //do math for each
  voltage = (sensorVal/1024.0)* 5.0; //from project 2 
  temperatureC = (voltage - .5) * 100; //from project 2
  temperatureF = ((temperatureC * 9.0)/ 5.0) + 32.0; //from the googles
  
  
  //print to serial
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print("\n");

  Serial.print("Volts: ");
  Serial.print(voltage);
  Serial.print("\n");

  Serial.print("Degrees C: ");
  Serial.print(temperatureC);
  Serial.print("\n");

  Serial.print("Degrees F: ");
  Serial.print(temperatureF);
  Serial.print("\n");
  
  Serial.print("\n");

  //wait cycle set time 1000 = 1 sec
  delay(5000);

 
}
