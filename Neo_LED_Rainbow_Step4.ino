/* Written by - Rahul Sharma 
for - Yolabs - 14th Feb 2026
Note - Neopixel LED has taken a centerstage all projects that need lighting, including fountaion to battlebots to EV Scooters 

Here is the simple code that gives you a rainbow effect.  
  Neopixel            ESP 

  5V                  Vin ( note you can connect to 3v3 also but power will be super dim)
  GND                 GND
  DI                  D4
  DO                  open or next neo-rings's DI pin)
*/

#include <Adafruit_NeoPixel.h>

#define PIN 4
#define NUMPIXELS 16

// Easy settings
#define BRIGHTNESS 80
#define SPEED_MS 20     // smaller = faster rainbow

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixels.clear();
  pixels.show();
}

void loop() {
  // Rainbow loop
  for (long hue = 0; hue < 65536; hue += 256) {  // go through many colors
    for (int i = 0; i < NUMPIXELS; i++) {
      // each LED gets a slightly different hue
      long pixelHue = hue + (i * 65536L / NUMPIXELS);
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    delay(SPEED_MS);
  }
}
