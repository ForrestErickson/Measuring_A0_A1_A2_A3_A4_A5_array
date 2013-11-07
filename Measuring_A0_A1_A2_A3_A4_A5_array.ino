/*
Sampling with the Arduino analog inputs.
Lee Erickson Nov 1, 2013.
Commited Nov 5, 2013.
Commited Nov 6, 2013. Remove some magic numbers by making constants.


Write to serial port with - 9600 baud
Inspired from http://sites.goggle.com/site/MeasuringStuff
https://sites.google.com/site/measuringstuff/the-arduino
*/

//Conversion constants for the Analog to Digital converters.
const float AREF=5.0;
const int A2D_SAMPLESIZE = 1023;

// time will be in millis (milliseconds)
unsigned long time;

// the raw temp data ranging from 0 to 1023
int a2d[5];                              //array to hold a2d converstions
int LED = 13;                            //The built in LED

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
//Get all the analog inputs.  
  for (int i = 0; i<5; i++){
    delay(10);
    a2d[i]=analogRead(i);
  }

//Write out the results
  Serial.print("Time= ");
  Serial.print(time); 
  
  for (int i = 0; i<5 ;i++) {
  Serial.print(", ");   
  Serial.print((AREF*a2d[i])/A2D_SAMPLESIZE, 3);  //Formate data with 3 places after decimal.
  }
  Serial.println(".");
  toggleLED();
  delay(500);                        //Just so that we can see the data slowly
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
 
