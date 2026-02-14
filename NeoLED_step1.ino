/* Written by - Rahul Sharma 
for - Yolabs - 14th Feb 2026
Note - Neopixle LED has taken a centerstage all projects that need lighting, including fountaion to battlebots to EV Scooters 

Here is the simple code that gives you five different colors. you can change the colors as well as their switching time by changing the parameters 

Connections 
  Neopixel            ESP 

  5V                  Vin ( note you can connect to 3v3 also but power will be super dim)
  GND                 GND
  DI                  D4
  DO                  open or next neo-rings's DI pin)
*/

#include <Adafruit_NeoPixel.h>

#define PIN        4 // pin number you can change it if you are using some other pin 
#define NUMPIXELS  16 // no of LED's on a ring 

int BRIGHTNESS = 100;   // 0–255
int waittime   = 5000; // 10 sec as 1000 ms = 1 sec 


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void showColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();
  delay(waittime); // 10 seconds
}

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS); // 0-255
  pixels.clear();
  pixels.show();
}
// change the color code of your choice below 
void loop() {
  showColor(255, 0, 0);     // Red
  showColor(0, 255, 0);     // Green
  showColor(0, 0, 255);     // Blue
  showColor(255, 255, 0);   // Yellow
  showColor(255, 0, 255);   // Purple (Magenta)
}
