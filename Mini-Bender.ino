//Libraries
#include <Wirefeed.h>

//Pin Map
#include "pinmap.h"

//Instantiations
Wirefeed wirefeed(feedStep, feedDir);

//Operational Variables

void setup() {
  //Pin Initialization
  pinMode(bendStep,OUTPUT);
  pinMode(bendDir,OUTPUT);
  pinMode(feedStep,OUTPUT);
  pinMode(feedDir,OUTPUT);
  pinMode(sol,OUTPUT);
  
  digitalWrite(bendStep, LOW);
  digitalWrite(bendDir, HIGH);
  digitalWrite(feedStep, LOW);
  digitalWrite(feedDir, HIGH);
  digitalWrite(sol, LOW);
  //note: solenoid rises when sol is HIGH
  
  //Serial Comms Initialization
  Serial.begin(9600);
  Serial.println("Mini-Bender Online");
  loadScreen();
}

void loop() {
  wirefeed.update();
}

void serialEvent() {
  if (Serial.available()) {
   int code = Serial.read() - 48;
   switch (code) {
    case 1:
      wirefeed.on();
      break;
    case 2:
      wirefeed.off();
      break;
    case 3:
      wirefeed.setTimeStep(10);
      break;
    case 4:
      wirefeed.setTimeStep(20);
      break;
    case 5:
      wirefeed.setDirection(1);
      break;
    case 6:
      wirefeed.setDirection(0);
      break;
    case 7:
      wirefeed.setFeedLength(1000);
      wirefeed.on();
      break;
    default:
      Serial.println("what?");
      break;
   } 
  }
}
