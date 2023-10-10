#include "global.h"

//Runs onces before void loop
void setup() {
  strip.begin();     //Intailizes the Neo pixel      
  strip.show();            //Needed to display LEDs 
  strip.setBrightness(BRIGHTNESS);      //sets the brightness from 1-255
}
//loops code inside 
void loop() {
  //colorWipe(strip.Color(255,   0,   0)     , 50); 
  loading(strip.Color(0,0,255)    ,50);     //Calls the loading LED pattern from led_functions.ino
  delay(320);
  clap(strip.Color(0,255,0)   ,50);
  delay(320);
  run2(strip.Color(255,0,0));
  delay(320);
  IDK();
  delay(320);
  old_flim(strip.Color(0,255,0));
  delay(320);
  fire_alarm();
  delay(500);
}
