/* Written by - Rahul Sharma 
for - Yolabs - 14th Feb 2026
Note - Neopixel LED has taken a centerstage all projects that need lighting, including fountain to battlebots to EV Scooters 

Here is the simple code that gives you a very beautiful fading  effect.  
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
#define SPEED_MS 20    // smaller = faster color change

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixels.clear();
  pixels.show();
}

void loop() {
  // Smoothly change color for the whole ring
  for (long hue = 0; hue < 65536; hue += 128) {
    uint32_t c = pixels.gamma32(pixels.ColorHSV(hue)); // one nice color

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, c); // same color on all LEDs
    }

    pixels.show();
    delay(SPEED_MS);
  }
}
