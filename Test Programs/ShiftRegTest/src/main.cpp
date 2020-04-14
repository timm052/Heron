#include <Arduino.h>

int SCK = 18; //Serial Clock
int RCK = 5; //Register Clock
int SOT = 23; //Serial Out


void setup() {
  pinMode(SCK, OUTPUT);
  pinMode(RCK, OUTPUT);
  pinMode(SOT, OUTPUT);
}

void loop() {
  shiftOut(SOT, SCK, MSBFIRST,10101010);
  digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  delay(1000);
  shiftOut(SOT, SCK, MSBFIRST,01010101);
  digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  delay(1000);
}