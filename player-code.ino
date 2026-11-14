#include <FastLED.h>
#define LED_PIN   6  
#define NUM_LEDS   11
#define LED_TYPE    SK6812
#define COLOR_ORDER     GRB

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
}

void fadeLEDs() {
    static uint8_t brightness = 0;
    static uint8_t direction = 1;

    brightness += direction;
    if (brightness == 0 || brightness == 200) {
        direction = -direction;
    }
    fill_solid(leds, NUM_LEDS, CRGB::Green);
    FastLED.setBrightness(brightness);
    FastLed.show();
}

void loop() {
    EVERY_N_MILLISECONDS(30) {
        fadeLEDs();
    }
}