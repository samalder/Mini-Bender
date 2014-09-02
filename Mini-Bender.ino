//Libraries
#include <Wirefeed.h>

//Pin Map
#include "pinmap.h"

//Instantiations
Wirefeed wirefeed(feedStep, feedDir);

//Operational Variables
//---IO
int const opCodeLen = 8;
int opCode[opCodeLen];

//---Error detection
int errorCode = 0;

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
  
  //Initialize the Input buffer
for (int i = 0; i < opCodeLen; i++) {
  opCode[i] = 0;
}
  
  //Serial Comms Initialization
  Serial.begin(9600);
  Serial.println("Mini-Bender Online");
  loadScreen();
}

void loop() {
  rcvSerial();
  wirefeed.update();
}
