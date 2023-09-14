/*
  Patterns.cpp Library for LED pattern for EGR project Adafruit LEDs.
  Created by Tyler John S. Burt, September 13, 2023.
  edited by Tyler John S. Burt, September 14, 2023.
  Released into the public domain.
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket

#include "Arduino.h"
#include "Patterns.h"

Patterns::Patterns(int wait; int NUM_LED){
  _wait = wait;
  _NUM_LED = NUM_LED;
}

void Patterns::begin(){
  //strip.begin(); 
}

void Patterns::loading_color(uint32_t color,_wait){
    for(int i=0;i<_NUM_LED;i++){
    strip.setPixelColor(i,color);
    strip.show();
    delay(wait);
  }
  for(int i=0;i<_NUM_LED;i++){
    strip.setPixelColor(i,strip.Color(  0,   0,   0));
    strip.show();
    delay(wait);
  }
}

void Patterns::clap(uint32_t color,_wait){
  for(int i=0;i<_NUM_LED/2;i++){
    strip.setPixelColor(i,color);
    strip.setPixelColor(12-i,color);
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(6,color);
  strip.show();
  delay(wait);
  for(int i=0;i<_NUM_LED/2;i++){
    strip.setPixelColor(6-i,strip.Color(0,0,0));
    strip.setPixelColor(6+i,strip.Color(0,0,0));
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(0,strip.Color(0,0,0));
  strip.show();
}

void Patterns::running(uint32_t color){
  for(int i=0;i<_NUM_LED;i++){
    strip.setPixelColor(i,color);
    strip.show();
    delay(50);
    strip.setPixelColor(i+1,color);
    strip.setPixelColor(i-1,strip.Color(0,0,0));
    strip.show();
  }
  strip.setPixelColor(11,strip.Color(0,0,0));
  strip.show();
}

void Patterns::test0(uint32_t color){
  for(int i=0;i<_NUM_LED;i++){
    strip.setPixelColor(i,color);
    strip.show();
  }
}