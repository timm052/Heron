#include <Arduino.h>
#include <ledmap.h>
#include <Adafruit_NeoPixel.h>
#define PIN 25
#define NUMPIXELS 40

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
  pixels.begin();
  pixels.show(); // set leds default state on start to off
  pixels.setBrightness(50);
}

void loop() {
  pixels.clear();

  // cycle through each led displaying a colour
  for (int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0,150,0));
    pixels.show();
    delay(DELAYVAL);
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(150,0,0));
    pixels.show();
    delay(DELAYVAL);
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(0,0,150));
    pixels.show();
  }
}