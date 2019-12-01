/* 
Title:    twinkle.ino
Author:   Lawrence Gabriel Castillo
Date:     2019-Nov-9
Desc:     Output light sequences to LED strips.
Purpose:  Modification to add "twinkle" pattern
Build:    Arduino 1.8.6; AdaFruit AVR Boards 1.4.13 (Flora); AdaFruit NeoPixel 1.1.8
Deploy:   AdaFruit Flora; AdaFruit NeoPixel LED Strand
*/

#include <Adafruit_NeoPixel.h>
#define PIN 6

// @param number of pixels in strip
// @param Arduino pin number (most are valid)
// @param pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    strip.begin();
    strip.setBrightness( 64 );
    strip.show(); // Initialize all pixels to 'off'
}

void loop() 
{
    Pop();
}

void Pop()
{
    // favored 255, 115, 25
    int r = 255;  // red valid 0-255
    int g = 115;    // green valid 0-90: affects white tone/ brightness
    int b = 25;    // blue valid 0-100: affects white tone/ brightness
    float delay_time = 2;

    int pxl = random(0, strip.numPixels());
    strip.setPixelColor(pxl, r, g, b );
    strip.show();
    delay(delay_time);
    strip.setPixelColor(pxl, 0, 0, 0 );
    strip.show();
    delay(delay_time);
}

