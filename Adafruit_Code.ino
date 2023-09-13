#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN 0
#define NUM_LED 12

Adafruit_NeoPixel strip(NUM_LED, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  strip.begin();
  strip.show();
}

void loop(){
  
}

void loading_color(uint32_t color, int wait){
  for(int i=0;i<NUM_LED;i++){
    strip.setPixelColor(i,color);
    strip.show();
    delay(wait);
  }
  for(int i=0;i<NUM_LED;i++){
    strip.setPixelColor(i,strip.Color(  0,   0,   0));
    strip.show();
    delay(wait);
  }
}

void clap(uint32_t color, int wait){
  for(int i=0;i<NUM_LED/2;i++){
    strip.setPixelColor(i,color);
    strip.setPixelColor(12-i,color);
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(6,color);
  strip.show();
  delay(wait);
  for(int i=0;i<NUM_LED/2;i++){
    strip.setPixelColor(6-i,strip.Color(0,0,0));
    strip.setPixelColor(6+i,strip.Color(0,0,0));
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(0,strip.Color(0,0,0));
  strip.show();
}

void running(uint32_t color){
  for(int i=0;i<NUM_LED;i++){
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

