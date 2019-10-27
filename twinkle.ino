/* 
Title:    twinkle.ino
Author:   Lawrence Gabriel Castillo
Date:     2019-Oct-27
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
    int r = 140;  // red valid 0-255
    int g = 140;    // green valid 0-90: affects white tone/ brightness
    int b = 140;    // blue valid 0-100: affects white tone/ brightness
    float step_up_time = 0.2;
    float step_down_time = 0.2;

    // Turn all LEDs on
    // white is constant
    for( int i = 0; i < strip.numPixels(); i++ ) { 
        strip.setPixelColor(i, r, g, b );
        strip.show();
    }

    int pxl1 = random(0, strip.numPixels());
    int pxl2 = random(0, strip.numPixels());   
    int pxl3 = random(0, strip.numPixels());
    int pxl4 = random(0, strip.numPixels());   
    int pxl5 = random(0, strip.numPixels()); 
    
    LightUp(pxl1, step_up_time);
    LightUp(pxl2, step_up_time);
    LightUp(pxl3, step_up_time);
    LightDown(pxl1, step_down_time);
    LightDown(pxl2, step_down_time);
    LightUp(pxl4, step_up_time);
    LightUp(pxl5, step_up_time);
    LightDown(pxl3, step_down_time);
    LightDown(pxl4, step_down_time);
    LightDown(pxl5, step_down_time);
}

void LightUp(int pxl, float step_up_time){

    for( int i = 140; i < 256; i++ ) {
        strip.setPixelColor(pxl, i, i, i);
        strip.show();
        delay(step_up_time);
    }
}

void LightDown(int pxl, float step_down_time){
  
    for( int i = 255; i > 139; i-- ) {
        strip.setPixelColor(pxl, i, i, i);
        strip.show();
        delay(step_down_time);
    }
}
