#include <Arduino.h>

hw_timer_t * timer = NULL;
int stepSize = 2; // Current max steps of sequencer - will be changed by user. NOTE: size is this +1 (includes 0)
int step = 0; // Current step - will update automatically
bool buttonFlag = 0; //Flag is set whenever a button is pressed - used for optimisation
#define TRACKS 2 // Max number of tracks - NOT USED ATM
#define MAXSTEPS 3 // Max number of steps

//Testing pins
#define LED_PIN1 18 // LED 1 of selected steps
#define LED_PIN2 5 // LED 2 """
#define LED_PIN3 17 // LED 3 """
#define LED_PIN4 23 // LED 1 of tracking cursor
#define LED_PIN5 22 // LED 2 """
#define LED_PIN6 21 // LED 3 """
#define LED_PIN7 4 // LED for when cursor meets selected step
#define BUT_PIN1 0  // Button 1 for selecting step
#define BUT_PIN2 2  // Button 2 """
#define BUT_PIN3 15 // Button 3 """




// Each step of a track is one of these objects
class stepNote
{
  public:
  bool onOff; //Note on/off - 1 on, 0 off
  int8_t velocity; //Rest are unused - just filling space here
  int8_t aftertouch;
  int8_t pitch;

};

// Each track is an array of 'stepnote' objects - one object per step.
volatile stepNote Track1[MAXSTEPS]; // Not sure where these should go, just global variables atm.
volatile stepNote Track2[MAXSTEPS]; // Track 2 not used yet

// Array of selectable LEDs
int LEDs[3] = {LED_PIN1, LED_PIN2, LED_PIN3}; 

// Array of tracking LEDs
int LEDt[3] = {LED_PIN4, LED_PIN5, LED_PIN6}; 

// Interrupt for timer - is called when timer reaches set interval
void IRAM_ATTR onTimer()
{
  digitalWrite(LEDt[step], LOW); // Turn the previous LED off
  if(step >= stepSize) // If step has reached the end of sequence
  {step = 0;} // Reset step back to start
  else
  {step++;} // Else increment to next step
  digitalWrite(LEDt[step], HIGH); // Turn current LED on

  if(Track1[step].onOff) // If the current step is selected
  {digitalWrite(LED_PIN7, HIGH);} // Then turn on indicator LED
  else
  {digitalWrite(LED_PIN7, LOW);} // Else turn it off
  // NOTE - this is where the main action of the sequencer (eg sending that step to MIDI) will occur. Currently just placeholder LED.

}

// Interrupts for button presses
void IRAM_ATTR intB1()
{    
  Track1[0].onOff = !Track1[0].onOff; // Invert current onOff state
    buttonFlag = 1; // Set flag so main loop knows to update button LEDs
}
void IRAM_ATTR intB2() // As above for button 2
{
  Track1[1].onOff = !Track1[1].onOff;
    buttonFlag = 1;
}
void IRAM_ATTR intB3() // As above for button 3
{    
   Track1[2].onOff = !Track1[02].onOff;
    buttonFlag = 1;
}

void setup() 
{
  timer = timerBegin(0, 80, true); // Timer no. (0) - Prescaler Value (1MHz (80Mhz clock / 80)) - Count UP (true). Will fire every uS
  timerAttachInterrupt(timer, &onTimer, true); // Attaches 'onTimer' vector to timer interrupt. 'True' is edge, 'False' is level.
  timerAlarmWrite(timer, 500000, true); // 500k value, given prescaler above, will fire every 0.5s. True reloads value after done.
  timerAlarmEnable(timer); // Enable alarm



  //Setup LED and button pins
  pinMode(LED_PIN1, OUTPUT); // LEDs all output
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
  pinMode(LED_PIN5, OUTPUT);
  pinMode(LED_PIN6, OUTPUT);
  pinMode(LED_PIN7, OUTPUT);
  pinMode(BUT_PIN1, INPUT); // Buttons all input
  pinMode(BUT_PIN2, INPUT);
  pinMode(BUT_PIN3, INPUT);

  attachInterrupt(BUT_PIN1, intB1, HIGH); // Will call 'intB1' when button 1 is high
  attachInterrupt(BUT_PIN2, intB2, HIGH); // As above for button 2
  attachInterrupt(BUT_PIN3, intB3, HIGH); // As above for button 3
}

void loop()
{
  if(buttonFlag) // If this flag is set, a button has been pressed since last loop
  {              // Will run through each step to see if LED should be turned on
    if(Track1[0].onOff) // If first step is on
    {digitalWrite(LED_PIN1, HIGH);} // Turn on its LED
    else
    {digitalWrite(LED_PIN1, LOW);} //Else turn it off
    
    if(Track1[1].onOff) // As above for step 2
    {digitalWrite(LED_PIN2, HIGH);}
    else
    {digitalWrite(LED_PIN2, LOW);}
    
    if(Track1[2].onOff) // As above for step 3
    {digitalWrite(LED_PIN3, HIGH);}
    else
    {digitalWrite(LED_PIN3, LOW);}
    
    buttonFlag = 0; // Reset the flag
  }
  /* NOTE - Probably better to have a flag for each individual button. One bool per button is minimal memory used, but much better performance.
            Currently whenever a single button is pressed, every step is scanned through and every LED is written to either on or off.          */
}




