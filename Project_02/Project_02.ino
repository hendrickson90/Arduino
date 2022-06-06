int switchState = 0;
int ledStater = 100;

void setup() {
  // put your setup code here, to run once:

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {



  
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if(switchState == LOW){

    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    
    //button is not pressed
    digitalWrite(3,HIGH); // green LED
    digitalWrite(4,LOW); // red LED
    digitalWrite(5,LOW); // red LED


    
    if (ledStater != 0){
      delay(75);
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      ledStater = ledStater -1;
      delay(75);
      }

    
    
  }
  else{ // the button is pressed


    ledStater = 3;

    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    
    digitalWrite(3,LOW); // green LED
    digitalWrite(4,LOW); // red LED
    digitalWrite(5,HIGH); // red LED

    delay(250); //wait quarter of a second
    //toggle LEDs

    digitalWrite(4,HIGH); // red LED
    digitalWrite(5,HIGH); // red LED
    delay(250); //wait quarter of a second

    
    }

}// loop
