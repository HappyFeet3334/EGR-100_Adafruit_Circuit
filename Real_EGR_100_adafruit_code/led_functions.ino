#include "global.h"    //Includes global varaibles and functions

//LED pattern that does the windows loading dots 
void loading(uint32_t color, int wait) 
{
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);         
    strip.show();                          
    delay(wait);                           
  }
  for(int i=0;i<strip.numPixels();i++){
    strip.setPixelColor(i,strip.Color(  0,   0,   0));
    strip.show();
    delay(wait);
  }
}
//LED patern that changes all the LEDs to a uniform color by circling around
void colorwipe(uint32_t color)
{
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
  }
  strip.show();
}
//turns on LEDs while and meets half way and then turn off
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
//Turns on two LEDs and goes in a cricle around the Neo Pixel
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