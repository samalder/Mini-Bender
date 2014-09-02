extern const int opCodeLen;
extern int opCode[];
extern int errorCode;

//Some text for the 
void loadScreen() {
  Serial.println("OPTIONS:");
}

//Process incoming serial data
void rcvSerial () {
  int i = 0;
  errorCode = 0;
  bool msgRcved = false;
  while (Serial.available() > 0) {
    opCode[i] = Serial.read();
    i++;
  }
  //Error detection
 /* if (i != opCodeLen - 1) {   //If the message was too short or too long
    errorCode = 10;
  }
  if (opCode[0] < 65 || opCode[0] > 90) {  //if the msg does not start with a command letter
   errorCode = 11; 
  }
  if (opCode[2] != 32) {     //If the msg does not correctly delimit the command and the value
   errorCode = 12;           //(looks for a space in the third array position i.e "W2 019.1" is correct)
  }
  if (opCode[6] != 46) {     //If the msg does not contain a well formatted value
   errorCode = 13; 
  }
*/  
  /*if (errorCode != 0) {      //If there are any detected formatting issues, discard the data and escape the function
     for (int i = 0; i < opCodeLen; i++) {
      opCode[i] = 0;
     }
     return;
  }
  */
  msgRcved = true;
  
  //Translate the msg to usable variables
  char letterCode = opCode[0];
  int  numberCode = opCode[1] - 48;
  float  msgValue = (opCode[3] - 48)*100 + (opCode[4] - 48)*10 + (opCode[5] - 48) + (opCode[7] - 48)*0.1;
  
  switch (letterCode) {
   case 'W':
      switch (numberCode) {
       case 1:
         //wirefeed.feedLength = msgValue;
         wirefeed.on();
         break;
       default:
         break;
      }
      break;
   default:
     errorCode = 14;
     break;
  }
  Serial.println(numberCode);
}
