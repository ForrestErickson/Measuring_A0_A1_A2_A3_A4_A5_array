/*
Sampling with the Arduino analog inputs.
Lee Erickson Nov 1, 2013.
Commited Nov 5, 2013.

Write to serial port with - 9600 baud
Inspired from http://sites.goggle.com/site/MeasuringStuff
https://sites.google.com/site/measuringstuff/the-arduino
*/

// time will be in millis (milliseconds)
unsigned long time;

// the raw temp data ranging from 0 to 1023
int a2d[5];
int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
  toggleLED();
  // initialize serial port:
  Serial.begin(9600);
  toggleLED();
  Serial.println("Starting Analog to Digital conversion."); 
  toggleLED();
}


void loop() {

  time=millis();
  for (int i = 0; i<5; i++){
    delay(10);
    a2d[i]=analogRead(i);
  }

  Serial.print("Time= ");
  Serial.print(time); 
  
  for (int i = 0; i<5 ;i++) {
  Serial.print(", ");   
  Serial.print(5*a2d[i]/1023.0);
  }
  Serial.println(".");
  toggleLED();
  delay(500);
}

//Functions go here.

//const int LED  = 13;  //Build in LED.
int valLED = LOW;  // variable to store LED state

void toggleLED()  {
  if (valLED == HIGH){
    digitalWrite(LED, LOW);
    valLED = LOW;
  } else {
    digitalWrite(LED, HIGH);
    valLED = HIGH;
  }  
}
 
