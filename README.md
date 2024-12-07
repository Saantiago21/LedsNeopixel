#include <Adafruit_NeoPixel.h>


#define LED_PIN 6        
#define NUM_LEDS 87     
#define TRANSITION_DELAY 100 


Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);


const int violet[3] = {138, 43, 226};  
const int iphoneBlue[3] = {52, 120, 147}; 

void setup() {
  strip.begin();  
  strip.show();   
void loop() {
  
  gradualChange(violet[0], violet[1], violet[2]);
  delay(480000); 

  
  gradualChange(iphoneBlue[0], iphoneBlue[1], iphoneBlue[2]);
  delay(480000); 


void gradualChange(int red, int green, int blue) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue)); 
    strip.show();  
    delay(TRANSITION_DELAY); 
  }
