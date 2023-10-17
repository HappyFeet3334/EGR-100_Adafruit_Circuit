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
  delay(320); // waits 320 milliseconds 
  clap(strip.Color(0,255,0)   ,50);     //Calls the clap LED pattern from led_functions.ino
  delay(320);
  run2(strip.Color(255,0,0));       //Calls the run2 LED pattern from led_functions.ino
  delay(320);
  Random_RGB_Val();
  delay(320);
  old_flim(strip.Color(0,255,0));
  delay(320);
  fire_alarm();
  delay(500);
}
