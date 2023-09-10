#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN 11
#define NUM_LED 12
#define BUTTON_PIN 2

boolean oldState = HIGH;
boolean newState = LOW;

Adafruit_NeoPixel strip(NUM_LED, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

void loop(){
  newState = digitalRead(BUTTON_PIN);
  
  if((newState==LOW)&&(oldState==HIGH)){
    delay(10);
    newState=digitalRead(BUTTON_PIN);
    int random_num = random(0,3);
    if(random_num == 0){
      loading_color(strip.Color(0,0,255),50);
      Serial.print(random_num);
    }else if(random_num == 1){
      clap(strip.Color(0,255,0),50);
      Serial.print(random_num);
    }else{
      running(strip.Color(255,0,0));
      Serial.print(random_num);
    }
  }
  oldState=newState;
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

