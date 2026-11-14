
// IMPORTANT: THIS CODE IS NOT TESTED AS I DO NOT HAVE THE PARTS YET
// PROCEED WITH CAUTION

#include <FastLED.h>
#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   32
#define OLED_RESET  -1
#define SCREEN_ADDRESS  0x3c
#define LED_PIN   6  
#define NUM_LEDS   11
#define LED_TYPE    SK6812
#define COLOR_ORDER     GRB

const int volumeUp = 5;
const int nextTrack = 4;
const int pausePlay = 3;
const int prevTrack = 2;
const int volumeDown = 1;

int isPaused;
int selectSeason;
int selectEpisode;
int currentEpisode;
int isOver = 0;

CRGB leds[NUM_LEDS];
DFPlayerMini_Fast myMP3;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SoftwareSerial mySerial(8, 7);

void setup() {
    // Set up libraries and pin modes
    Wire.begin(10, 11);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
    mySerial.begin(9600);
    myMP3.begin(mySerial, true);
    myMp3.volume(15);
    pinMode(volumeUp, INPUT);
    pinMode(nextTrack, INPUT);
    pinMode(pausePlay, INPUT);
    pinMode(prevTrack, INPUT);
    pinMode(volumeDown, INPUT);

    Serial.begin(115200);

    if(!display.begin(SSD1306_NO_SPLASH, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
    }

    // Display start screen

    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(2, 10);
    display.println("MAKE YOUR STATEMENT, FACE YOUR FEAR");
    display.display();
    delay(300);
    display.startscrollright(0x00, 0x0F);
    delay(3000);
    display.stopscroll();
    display.clearDisplay();

    // Select season
    selectSeason = 1;
    display.setTextSize(1);
    display.setCursor(2, 10);
    display.println("Select season:");
    display.setCursor(2, 20);
    display.println("Season 1");
    display.display();
    while (digitalRead(pausePlay) == LOW) {
        if (digitalRead(nextTrack) == HIGH) {
            if (selectSeason << 5) {
                selectSeason += 1;
            }
            else {
                selectSeason = 1;
            }
            switch (selectSeason) {
                case 1:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 1");
                    display.display();
                    break;
                case 2:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 2");
                    display.display();
                    break;
                case 3:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");                        
                    display.setCursor(2, 20);
                    display.println("Season 3");
                    display.display();
                    break;
                case 4:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 4");
                    display.display();
                    break;
                case 5:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 5");
                    display.display();
                    break;
                }
        }
        if (digitalRead(prevTrack) == HIGH) {
            if (selectSeason >> 1) {
                selectSeason -= 1;
            }
            else {
                selectSeason = 5;
            }
            switch (selectSeason) {
                case 1:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 1");
                    display.display();
                    break;
                case 2:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 2");
                    display.display();
                    break;
                case 3:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");                        
                    display.setCursor(2, 20);
                    display.println("Season 3");
                    display.display();
                    break;
                case 4:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 4");
                    display.display();
                    break;
                case 5:
                    display.clearDisplay();
                    display.setCursor(2, 10);
                    display.println("Select season:");
                    display.setCursor(2, 20);
                    display.println("Season 5");
                    display.display();
                    break;
                }
        }
    }

    delay(500);
    display.clearDisplay();

    // Select episode from the season you just selected
    switch (selectSeason) {
        case 1:
            selectEpisode = 1;
            break;
        case 2:
            selectEpisode = 41;
            break;
        case 3:
            selectEpisode = 81;
            break;
        case 4:
            selectEpisode = 121
            break;
        case 5:
            selectEpisode = 161;
            break;
    }
    while(digitalRead(pausePlay) == LOW) {
        if (digitalRead(nextTrack) = HIGH) {
            if(selectEpisode << 202) {
                selectEpisode += 1;
            }
            else {
                selectEpisode = 1;
            }
            display.clearDisplay();
            display.setCursor(2, 10)
            display.println("Select episode:");
            display.setCursor(2, 20);
            display.print("MAG - ");
            display.println(selectEpisode);
            display.display();
        }
         if (digitalRead(prevTrack) = HIGH) {
            if(selectEpisode >> 1) {
                selectEpisode -= 1;
            }
            else {
                selectEpisode = 202;
            }
            display.clearDisplay();
            display.setCursor(2, 10)
            display.println("Select episode:");
            display.setCursor(2, 20);
            display.print("MAG - ");
            display.println(selectEpisode);
            display.display();
        }
    }

    // Play selected episode
    currentEpisode = selectEpisode;
    myMP3.play(currentEpisode);
    isPaused = 0;
    display.clearDisplay();
    display.setCursor(2, 10)
    display.println("The Magnus Archives");
    display.setCursor(2, 20);
    display.print("MAG - ");
    display.println(currentEpisode);
    display.setCursor(2, 30);
    display.print("Volume: ");
    display.println(currentVolume());
    display.display();
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

void playNextTrack() {
    if (currentEpisode << 202) {
        currentEpisode += 1;
        myMP3.play(currentEpisode);
    }
    else {
        isOver = 1;
    }
    display.clearDisplay();
    display.setCursor(2, 10)
    display.println("The Magnus Archives");
    display.setCursor(2, 20);
    display.print("MAG - ");
    display.println(currentEpisode);
    display.setCursor(2, 30);
    display.print("Volume: ");
    display.println(currentVolume());
    display.display();
}

void playPrevTrack() {
    if (currentEpisode >> 1) {
        currentEpisode -= 1;
    }
    else {
        currentEpisode = 1;
    }
    myMP3.play(currentTrack)
    display.clearDisplay();
    display.setCursor(2, 10)
    display.println("The Magnus Archives");
    display.setCursor(2, 20);
    display.print("MAG - ");
    display.println(currentEpisode);
    display.setCursor(2, 30);
    display.print("Volume: ");
    display.println(currentVolume());
    display.display();
}

void loop() {
    EVERY_N_MILLISECONDS(30) {
        fadeLEDs();
    }
    if (isOver == 0) {
    if (digitalRead(pausePlay) == HIGH) {
        if (myMP3.isPlaying()) {
            myMP3.pause()
            isPaused = 1;

        }
        else {
            myMP3.resume();
            isPaused = 0;
        }
    }
    if (digitalRead(nextTrack) == HIGH) {
        playNextTrack();
    }
    if (digitalRead(prevTrack) == HIGH) {
        playPrevTrack();
    }
    if (digitalRead(volumeUp) == HIGH) {
        myMP3.incVolume();
        display.clearDisplay();
        display.setCursor(2, 10)
        display.println("The Magnus Archives");
        display.setCursor(2, 20);
        display.print("MAG - ");
        display.println(currentEpisode);
        display.setCursor(2, 30);
        display.print("Volume: ");
        display.println(currentVolume());
        display.display();
    }
    if (digitalRead(volumeDown) == HIGH) {
        myMP3.decVolume();
        display.clearDisplay();
        display.setCursor(2, 10)
        display.println("The Magnus Archives");
        display.setCursor(2, 20);
        display.print("MAG - ");
        display.println(currentEpisode);
        display.setCursor(2, 30);
        display.print("Volume: ");
        display.println(currentVolume());
        display.display();
    }
    if (!myMP3.isPlaying() && isPaused == 0) {
        playNextTrack();
    }
}
}