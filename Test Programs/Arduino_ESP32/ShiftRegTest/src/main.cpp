#include <Arduino.h>

int SerialClock = 18; //Serial Clock
int RCK = 5; //Register Clock
int SOT = 23; //Serial Out
unsigned int val1 = 0b1010101010101010;
unsigned int val2 = 0b0101010101010101;


void setup() {
  pinMode(SerialClock, OUTPUT); //Set all pins to output
  pinMode(RCK, OUTPUT);
  pinMode(SOT, OUTPUT);
  digitalWrite(RCK,LOW);
}

void loop() {
  shiftOut(SOT, SerialClock, MSBFIRST,0b10101010);
   digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  shiftOut(SOT, SerialClock, MSBFIRST,0b01010101);
  digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  delay(1000);
  shiftOut(SOT, SerialClock, MSBFIRST,0b01010101);
   digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  shiftOut(SOT, SerialClock, MSBFIRST,0b10101010);
  digitalWrite(RCK,HIGH);
  digitalWrite(RCK,LOW);
  delay(1000);
}

/*
#include <Arduino.h>
#include <SPI.h>

int SerialClock = 18; //Serial Clock
int RCK = 5; //Register Clock
int SOT = 23; //Serial Out
unsigned int val1 = 0b1010101010101010;
unsigned int val2 = 0b0101010101010101;


void setup() {

  SPI.begin(SerialClock,20,SOT);
}


void loop()
{
  while(1)
  {
    digitalWrite(RCK,LOW);
    SPI.transfer(0b01010101);
    SPI.transfer(0b10101010);     
    digitalWrite(RCK,HIGH);

  
  delay(300);
  }

  return;
}*/