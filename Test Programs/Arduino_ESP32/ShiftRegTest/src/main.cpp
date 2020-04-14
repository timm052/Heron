#include <Arduino.h>

int SerialClock = 18; //Serial Clock
int RCK = 5; //Register Clock
int SOT = 23; //Serial Out
unsigned int val = 0b1010101010101010;


void setup() {
  pinMode(SerialClock, OUTPUT); //Set all pins to output
  pinMode(RCK, OUTPUT);
  pinMode(SOT, OUTPUT);
  digitalWrite(RCK,LOW);
}

void loop() {
  shiftOut(SOT, SerialClock, MSBFIRST,0b1010101010101010);
  digitalWrite(RCK,HIGH);
  //delayMicroseconds(2);
  digitalWrite(RCK,LOW);
  delay(1000);
  shiftOut(SOT, SerialClock, MSBFIRST,0b1010101010101010);
  digitalWrite(RCK,HIGH);
  //delayMicroseconds(2);
  digitalWrite(RCK,LOW);
  delay(1000);
}