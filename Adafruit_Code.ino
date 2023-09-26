#include <Adafruit_NeoPixel.h>
#include<Adafruit_Code.ino>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define LED_PIN 0
#define NUM_LED 12

Adafruit_NeoPixel strip(NUM_LED, LED_PIN);

void setup(){
  strip.begin();
}

void loop(){
  
}