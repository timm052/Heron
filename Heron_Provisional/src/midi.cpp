// Should contain MIDI code
// Ie, structure for storing, sending, receiving midi notes

#include <MIDI.h>
#include "heronDefs.h"
#include "sharedFuncs.h"

#define MAXSTEPS 128 // Max number of steps

MIDI_CREATE_DEFAULT_INSTANCE(); //Will be used globally

class stepNote // Each step of each track is one of these objects
{
  public:
  bool onOff; //Note on/off - 1 on, 0 off
  int8_t velocity; // Most (All?) MIDI variables are max 8-bits
  int8_t aftertouch;
  int8_t pitch;
  // Not complete list of variables
};

// Each track is an array of 'stepnote' objects - one object per step.
volatile stepNote Track1[MAXSTEPS];
volatile stepNote Track2[MAXSTEPS];
volatile stepNote Track3[MAXSTEPS];
volatile stepNote Track4[MAXSTEPS];