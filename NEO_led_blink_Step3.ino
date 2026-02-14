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

// Easy settings
#define BRIGHTNESS 80
#define BLINK_DELAY_MS 500   // 500ms = 0.5 sec

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixels.clear();
  pixels.show();
}

void loop() {
  // Turn ON all LEDs (Blue)
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
  }
  pixels.show();
  delay(BLINK_DELAY_MS);

  // Turn OFF all LEDs
  pixels.clear();
  pixels.show();
  delay(BLINK_DELAY_MS);
}
