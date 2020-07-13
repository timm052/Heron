// Should contain IO code
// Ie, buttons, encoders, etc
#include <Arduino.h>
#include "heronDefs.h"
#include "sharedFuncs.h"

#define ioExpPin1 1 // Example - interrupt pin for IO expander 1
int state; // Example variable used below

void IRAM_ATTR IO1()
{
// Prior to switch we first need some process to figure out which button is pressed.
// Need IO expanders to develop this    
  switch(state) // Buttons may have multiple functions. Should monitor this with states.
  { // Once a button is pressed, we check which state we're in to see what it does.
    // Some buttons may be the same across multiple states
    case 1:
    {;}
    case 2:
    {;}
    case 3:
    {;}
    case 4:
    {;}
  }
  // Will need a switch statement for each button and encoder under this scheme
}

void IOsetup()
{
      attachInterrupt(ioExpPin1, IO1, HIGH); // Will call 'intB1' when button 1 is high
}