#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!


Adafruit_MCP23017 mcp;
  
volatile bool f1 = 0;

void setup() {  
  mcp.begin();      // use default address 0

  mcp.pinMode(5, OUTPUT);
  mcp.pinMode(7, INPUT);
  mcp.pullUp(7, HIGH);  // turn on a 100K pullup internally

}



void loop() 
{
  if(mcp.digitalRead(7))
  {f1 = 1;}
  else if(!mcp.digitalRead(7))
  {f1 = 0;}
  
  if(f1)
  {mcp.digitalWrite(5,HIGH); delay(400);}
  else if (!f1)
  {mcp.digitalWrite(5,LOW);}
}