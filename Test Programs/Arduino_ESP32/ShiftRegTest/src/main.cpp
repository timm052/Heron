#include <Arduino.h>

int SerialClock = 18; //Serial Clock
int RCK = 5; //Register Clock
int SOT = 23; //Serial Out
unsigned int val = 65535;


void setup() {
  pinMode(SerialClock, OUTPUT); //Set all pins to output
  pinMode(RCK, OUTPUT);
  pinMode(SOT, OUTPUT);
  digitalWrite(RCK,LOW);
}

void loop() {
  shiftOut(SOT, SerialClock, MSBFIRST,0b11111111);
  shiftOut(SOT, SerialClock, MSBFIRST,0b00000000);
  digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  delay(1000);
  shiftOut(SOT, SerialClock, MSBFIRST,0b00000000);
  shiftOut(SOT, SerialClock, MSBFIRST,0b11111111);
  digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  delay(1000);
}