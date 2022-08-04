#include <LiquidCrystal.h> 
//#include <time.h>

LiquidCrystal lcd(12, 11, 5,4, 3, 2);
const int switchPin = 6;
int prevSwitchState = 0;
int rely; 

const int sensorPin = A0;
int sensorVal = 0;
float voltage = 0;
float temperatureC = 0;
float temperatureF = 0;

//time_t t;

//alternating LED
bool flip = 1;

void setup() {

   //open serial port 
  Serial.begin(9600);//open serial port 

   // initialize digital pin LED_BUILTIN on board LED "L" as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(switchPin, INPUT);
  lcd.print("Hello");
  lcd.setCursor(0,1);
  lcd.print("Braedin");

  delay(3000);
  


}

void loop() {
  // put your main code here, to run repeatedly:

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

  lcd.clear();
  
  lcd.setCursor(0,0);
//  setTime(t);
//  lcd.print(t);


  
  lcd.setCursor(0,1);
  lcd.print("C:");
  lcd.print(temperatureC);

  
  lcd.print(" F:");
  lcd.print(temperatureF);
  
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
