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


void setup() {
  // configure leds
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
}