/* HERON PROVISIONAL PROGRAM
 * First version of Heron software - will begin to integrate various parts in this program.
 * Should eventually include all first-version features in working state.
 * Intended to be a functional proof of concept, but not a proper release.
 * User experience probably won't be ideal.
 */ 

#include <Arduino.h>
#include "heronDefs.h"
#include "sharedFuncs.h"

void setup() {
  seqSetup(); // Sequencer Setup
  IOsetup(); // IO Setup
}

void loop() {
  // put your main code here, to run repeatedly:
}