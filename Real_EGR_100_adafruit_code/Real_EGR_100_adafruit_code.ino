// NeoPixel test program showing use of the WHITE channel for RGBW
// pixels only (won't look correct on regular RGB NeoPixel strips).

#include "led_functions.h"

//#include <Adafruit_NeoPixel.h>
//#ifdef __AVR__
// #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
//#endif

//// Which pin on the Arduino is connected to the NeoPixels?
//// On a Trinket or Gemma we suggest changing this to 1:
//#define LED_PIN     0
//
//// How many NeoPixels are attached to the Arduino?
//#define LED_COUNT  16
//
//// NeoPixel brightness, 0 (min) to 255 (max)
//#define BRIGHTNESS 50 // Set BRIGHTNESS to about 1/5 (max = 255)
//
//// Declare our NeoPixel strip object:
//Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);


//#ifdef __AVR__
// #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
//#endif

void setup() {
  strip.begin();           
  strip.show();            
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  //colorWipe(strip.Color(255,   0,   0)     , 50); // Red
  loading(strip.Color(0,0,255)    ,50);
}
