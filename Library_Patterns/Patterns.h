/*
  Adafruit-LED.Patterns_h - libary for LED patterns created for EGR 100 Adafruit LED project.
  Created by Tyler John S. Burt, September 13, 2023
  Realsed into the public domain.
 */

#ifndef Patterns_h
#define Patterns_h

#include "Arduino.h"

class Patterns{
  public:
    Patterns(int wait);
    Patterns(int NUM_LED);
    void loading_color(uint32_t color, int wait);
    void clap(uint32_t color, int wait);
    void running(uint32_t color);
    void test0(uint32_t color);
    private:
    int _wait;
    int _NUM_LED;
};

#endif