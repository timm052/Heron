// For functions shared across multiple .cpp files
// Not sure about best practices for this stuff - may change


// Functions from sequencer.cpp
// Do the ifndef/define/endif to ensure this stuff is only done once
#ifndef _sequencer_cpp_
#define _sequencer_cpp_

void seqSetup(); // Setup function for the sequencer
void changeBPM(int val); // Function to change BPM by changing sequencer timer
void changeStepSize(int val); // Set a new amount of steps

#endif

// Functions from IO.cpp
// Do the ifndef/define/endif to ensure this stuff is only done once
#ifndef _IO_cpp_
#define _IO_cpp_

void IOsetup(); // IO Setup function


#endif