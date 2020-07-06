#include <Arduino.h>

hw_timer_t * timer = NULL;
int stepSize = 2; // Current max steps of sequencer - will be changed by user. NOTE: size is this +1 (includes 0)
int step = 0; // Current step - will update automatically
#define TRACKS 2 // Max number of tracks - NOT USED ATM
#define MAXSTEPS 3 // Max number of steps

//Testing pins
#define LED_PIN1 18 // LED for testing
#define LED_PIN2 5
#define LED_PIN3 17
#define BUT_PIN1 0  // Buttons for testing
#define BUT_PIN2 2
#define BUT_PIN3 15



// Each step of a track is one of these objects
class stepNote
{
  public:
  bool onOff; //Note on/off - 1 on, 0 off
  int8_t velocity;
  int8_t aftertouch;
  int8_t pitch;

};

// Each track is an array of 'stepnote' objects - one object per step.
volatile stepNote Track1[MAXSTEPS]; // Not sure where these should go, just global variables atm.
volatile stepNote Track2[MAXSTEPS];

// Array of connected LEDs
int LED[3] = {LED_PIN1, LED_PIN2, LED_PIN3}; 

// Interrupt for timer - is called when timer reaches set interval
void IRAM_ATTR onTimer()
{
  if(step > stepSize) //If step has reached the end of sequence
  {step = 0;} //Reset step back to start

  // Perform step activities here



  step++; //Increment the step
}

// Interrupts for button presses
void IRAM_ATTR intB1()
{    
  if(Track1[0].onOff) // If step is on
    {
      Track1[0].onOff = 0; // Then turn step off
      digitalWrite(LED[0], LOW); // And turn off LED
    } 
  else
    {
      Track1[0].onOff = 1; // Else turn step on
      digitalWrite(LED[0], HIGH); // And turn on LED
    }
}
void IRAM_ATTR intB2() // As above for button 2
{
  if(Track1[1].onOff) // If step is on
    {
      Track1[1].onOff = 0; // Then turn step off
      digitalWrite(LED[1], LOW); // And turn off LED
    } 
  else
    {
      Track1[1].onOff = 1; // Else turn step on
      digitalWrite(LED[1], HIGH); // And turn on LED
    }
}
void IRAM_ATTR intB3() // As above for button 3
{    
   if(Track1[2].onOff) // If step is on
    {
      Track1[2].onOff = 0; // Then turn step off
      digitalWrite(LED[2], LOW); // And turn off LED
    } 
  else
    {
      Track1[2].onOff = 1; // Else turn step on
      digitalWrite(LED[2], HIGH); // And turn on LED
    }
}

void setup() 
{
  timer = timerBegin(0, 80, true); // Timer no. (0) - Prescaler Value (1MHz (80Mhz clock / 80)) - Count UP (true). Will fire every uS
  timerAttachInterrupt(timer, &onTimer, true); // Attaches 'onTimer' vector to timer interrupt. 'True' is edge, 'False' is level.
  timerAlarmWrite(timer, 500000, true); // 500k value, given prescaler above, will fire every 0.5s. True reloads value after done.
  timerAlarmEnable(timer);

  attachInterrupt(BUT_PIN1, intB1, RISING); // Will call 'intB1' when button 1 pin rises from low to high
  attachInterrupt(BUT_PIN1, intB2, RISING); // As above for button 2
  attachInterrupt(BUT_PIN1, intB3, RISING); // As above for button 3

  //Setup LED and button pins
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(BUT_PIN1, INPUT);
  pinMode(BUT_PIN2, INPUT);
  pinMode(BUT_PIN3, INPUT);
}

void loop()
{}




