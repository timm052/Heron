// Should contain sequencer code
#include <Arduino.h>
#include "heronDefs.h"
#include "sharedFuncs.h"

//Global variables
hw_timer_t * timer = NULL; // Used for ESP32 interrupt
int stepSize = 2; // Current max steps of sequencer - will be changed by user. NOTE: size is this +1 (includes 0)
int step = 0; // Current step - will update automatically - Will likely need to be included in other files 'extern int step;'

// Function prototypes
void IRAM_ATTR seqTimer(); // Interrupt vector for timer
void changeBPM(int val); // Function to change BPM by changing sequencer timer
void changeStepSize(int val); // Set a new amount of steps

void seqSetup()
{
  timer = timerBegin(0, 80, true); // Timer no. (0) - Prescaler Value (1MHz (80Mhz clock / 80)) - Count UP (true). Will fire every uS
  timerAttachInterrupt(timer, &seqTimer, true); // Attaches 'onTimer' vector to timer interrupt. 'True' is edge, 'False' is level.
  timerAlarmWrite(timer, 500000, true); // 500k value, given prescaler above, will fire every 0.5s. True reloads value after done.
                                        // NOTE - this function will be used when user changes the BPM.
  timerAlarmEnable(timer); // Enable alarm
}

void IRAM_ATTR seqTimer()
{
 if(step >= stepSize) // If current step is at or over limit
 {step = 0;} // Reset it to first step
 else
 {step++;} // Else increment it
}

void changeBPM(int val)
{
 timerAlarmWrite(timer, val, true); // Reloads input value ('val') as new timer
                                    // NOTE - need to calculate conversion from BPM to this. Probably just a big table.
}

void changeStepSize(int val)
{
    stepSize = val;
}