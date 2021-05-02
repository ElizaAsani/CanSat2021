/*Not sure if you need these includes*/
#include <Arduino.h>   // required before wiring_private.h
#include "wiring_private.h" // pinPeripheral() function
#include "init.h"

#define cameraPin 14 //pa02, pin 3

void setup() {

  pinMode(cameraPin, OUTPUT);

  digitalWrite(cameraPin, HIGH); 

}

void loop() {
  digitalWrite(cameraPin, LOW);   
  
  delay(50);               
 
  digitalWrite(cameraPin, HIGH);      
 
  //Delay between pictures
  delay(5000); 
  
}
