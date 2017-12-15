/* ----------------------------------------------------------------------------------------------------
 * LITTLE BITS to OPENBCI, 2017
 * Update: 15/12/17
 *
 * V0
 * Written by Bastien DIDIER
 * more info : http://mentalista.fr
 *
 * ----------------------------------------------------------------------------------------------------
 */

const int out1 = 1; // digital output 1 pin 1
const int out2 = 5; // digital output 2 pin 5
const int out3 = 9; // digital output 3 pin 9
int incomingByte;

void setup(void) {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(out1, OUTPUT); // initialize pin 1 as output
  pinMode(out2, OUTPUT); // initialize pin 5 as output
  pinMode(out3, OUTPUT); // initialize pin 9 as output
}

void loop() {
  int rx = Serial.available();
  Serial.println(rx);
  if (rx > 0){
    Serial.readString();
    switch (rx) {
     case 1:
       //do something
       break;
     case 2:
       allPinOn();
       break;
     case 3:
       allPinOff();
       break;
     case 4:
       allPinOnOff(500);
       break; 
    }
  }
  delay(10);
}

void allPinOn(){
  digitalWrite(out1, HIGH);
  digitalWrite(out2, HIGH);
  digitalWrite(out3, HIGH);  
}

void allPinOff(){
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);  
}

void allPinOnOff(int delay_ms){
  digitalWrite(out1, HIGH);
  digitalWrite(out2, HIGH);
  digitalWrite(out3, HIGH);
  delay(delay_ms);
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);  
}

