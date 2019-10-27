/* 
Title:    minika_kollision.ino
Author:   Lawrence Gabriel Castillo
Date:     2019-Feb-17
Desc:     Output light sequences to LED strips.
Purpose:  Lighting patterns developed for artist Vanessa Sun. Vanessa is 
          augmenting an outfit in support of Minika Ko fashion and tech show, 
          "Kollision."
Build:    Arduino 1.8.6; Arduino AVR Boards 1.6.22 (LilyPad); 
          AdaFruit AVR Boards 1.4.13 (Flora); AdaFruit NeoPixel 1.1.8
Deploy:   LilyPad Arduino, Processor ATmega328P, Port Dev/ttyUSB1
          AdaFruit Flora, Port Dev/ttyACM0 (AdaFruit Flora)
          AdaFruit NeoPixel LED Strand
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
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    strip.begin();
    strip.setBrightness( 50 );
    strip.show(); // Initialize all pixels to 'off'
}

void loop() 
{
    TwinklePattern();
}

/*
Section: Twinkle Pattern
*/

// Color setup for twinkle pattern. This pattern pallette
// only displays: white
// @post    calls helper function to both set and reset LED output
// @return  four LED outputs (two on, two off)
void TwinklePattern()
{
    int r = 200;  // red valid 0-255
    int g = 200;    // green valid 0-90: affects white tone/ brightness
    int b = 200;    // blue valid 0-100: affects white tone/ brightness
    int waitSet = 4;    // sets delay after LED on (ms)
    int waitReset = 1;  // sets delay after LED off (ms)

    // Turn all LEDs on
    // white is constant
    for( int i = 0; i < strip.numPixels(); i++ ) { 
        strip.setPixelColor(i, r, g, b );
        strip.show();
    }

    for( int i = 200; i < 256; i++ ) {
        int pixel = random(0, strip.numPixels());
        strip.setPixelColor(pixel, i, i, i);
        strip.show();
        delay(1000);
    }
}
