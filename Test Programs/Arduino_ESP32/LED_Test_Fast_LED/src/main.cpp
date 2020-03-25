#include <Arduino.h>
#include <ledmap.h>
#include <FastLED.h>
#define DATA_PIN 25
#define NUM_LEDS 40
CRGB leds[NUM_LEDS]; //create array to store LED buffer



//FastLED Docs https://github.com/FastLED/FastLED/wiki/Controlling-leds
void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); //Initalize LED type and number of leds  
}

void loop() {
  // cycle through each led displaying a colour
  for (int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::PowderBlue;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(30);
  }
}