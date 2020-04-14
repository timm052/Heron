#include <Arduino.h>

int SerialClock = 18; //Serial Clock
int RCK = 5; //Register Clock
int SOT = 23; //Serial Out


void setup() {
  pinMode(SerialClock, OUTPUT); //Set all pins to output
  pinMode(RCK, OUTPUT);
  pinMode(SOT, OUTPUT);
  digitalWrite(RCK,LOW);
}

void loop() {
  shiftOut(SOT, SerialClock, MSBFIRST,0b10101010);
  digitalWrite(RCK,HIGH);
  //delayMicroseconds(2);
  digitalWrite(RCK,LOW);
  delay(1000);
  shiftOut(SOT, SerialClock, MSBFIRST,0b01010101);
  digitalWrite(RCK,HIGH);
  //delayMicroseconds(2);
  digitalWrite(RCK,LOW);
  delay(1000);
}