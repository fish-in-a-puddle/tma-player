#include <FastLED.h>
#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
#define LED_PIN   6  
#define NUM_LEDS   11
#define LED_TYPE    SK6812
#define COLOR_ORDER     GRB

const int pausePlay = 3;

CRGB leds[NUM_LEDS];
DFPlayerMini_Fast myMP3;
SoftwareSerial mySerial(8, 7);

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
    mySerial.begin(9600);
    myMP3.begin(mySerial, true);
    pinMode(pausePlay, INPUT);

    while (digitalRead(pausePlay() == 0)) {
        delay(10);
    }
    myMP3.loop(1);
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
    if (digitalRead(pausePlay) == HIGH) {
        if (myMP3.isPlaying()) {
            myMP3.pause()

        }
        else {
            myMP3.resume();
        }
    }
}