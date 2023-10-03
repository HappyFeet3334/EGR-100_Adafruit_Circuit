#include "led_functions.h"

void loading(uint32_t color, int wait) 
{
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
  for(int i=0;i<strip.numPixels();i++){
    strip.setPixelColor(i,strip.Color(  0,   0,   0));
    strip.show();
    delay(wait);
  }
}

void colorwipe(uint32_t color)
{
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
  }
  strip.show();
}

void clap(uint32_t color, int wait)
{
  for(int i=0;i<strip.numPixels()/2;i++){
    strip.setPixelColor(i,color);
    strip.setPixelColor(12-i,color);
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(6,color);
  strip.show();
  delay(wait);
  for(int i=0;i<strip.numPixels()/2;i++){
    strip.setPixelColor(6-i,strip.Color(0,0,0));
    strip.setPixelColor(6+i,strip.Color(0,0,0));
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(0,strip.Color(0,0,0));
  strip.show();
}

void run2(uint32_t color)
{
  for(int i=0;i<strip.numPixels();i++){
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
