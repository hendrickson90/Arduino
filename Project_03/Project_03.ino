
const int sensorPin = A0;
const float baselineTemp = 20.0;
int sensorVal = 0;
float voltage = 0;
float temperatureC = 0;
float temperatureF = 0;
bool flip = 1;


//int test[10][10] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//open serial port 

  for(int pinNumber = 2; pinNumber<5; pinNumber++ ){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

if(flip == 1){
  digitalWrite(LED_BUILTIN, HIGH);  
  flip = 0; 
}else{ 
  digitalWrite(LED_BUILTIN, LOW);
  flip = 1;
}

  sensorVal = analogRead(sensorPin);
  voltage = (sensorVal/1024.0)* 5.0;
  temperatureC = (voltage - .5) * 100;
  temperatureF = ((temperatureC * 9.0)/ 5.0) + 32.0;
  
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
  
  delay(5000);

 
}
