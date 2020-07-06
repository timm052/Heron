#include <Arduino.h>
#include <fastLED.h>
#include <Gradients.h>
#include <LED.h>

//Pin Assignments
#define LED_PIN 25

//Settings
#define NUM_LEDS 40


//Globals
CRGB leds[NUM_LEDS];
CRGBPalette16 myPal = gr59_hult_gp;
int bpm = 125;

// TODO determine final set of globals
// list of potential globals
// 6 * 4 MIDI CC values
// Array to track if any changes are made to LED's
// Array of LED colour states



void setup() {
  // configure leds
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
}