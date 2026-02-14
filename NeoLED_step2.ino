/* Written by - Rahul Sharma 
for - Yolabs - 14th Feb 2026
Note - Neopixel LED has taken a centerstage all projects that need lighting, including fountaion to battlebots to EV Scooters 

Here is the simple code that gives you a light moving effect. In actual it is turinning on one led at a time for 60 mili second and than make on next one and place the current led off 

Connections 
  Neopixel            ESP 

  5V                  Vin ( note you can connect to 3v3 also but power will be super dim)
  GND                 GND
  DI                  D4
  DO                  open or next neo-rings's DI pin)
*/

#include <Adafruit_NeoPixel.h>

#define PIN 4
#define NUMPIXELS 16

// Easy settings (students can change these)
#define BRIGHTNESS 80
#define SPEED   60   // smaller = faster chase

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();                 // start NeoPixel
  pixels.setBrightness(BRIGHTNESS);
  pixels.clear();                 // turn OFF all LEDs
  pixels.show();
}

void loop() {
  // CHASE EFFECT: one LED moves around the ring
  for (int pos = 0; pos < NUMPIXELS; pos++) {

    pixels.clear(); // turn off all LEDs

    // turn ON only one LED (the moving one)
    pixels.setPixelColor(pos, pixels.Color(0, 255, 0)); // Green color

    pixels.show();  // update the LEDs
    delay(SPEED);
  }
}
