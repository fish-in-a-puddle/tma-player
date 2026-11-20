# The Magnus Archives-themed Podcast Player

*add image here*


## What it is

An ESP32-based MP3 player designed to look like a handheld tape recorder like the one used in the podcast "The Magnus Archives" containing every episode of the podcast. It uses a DFPlayer Mini module to play the audio and 11 SK6812E LEDs to add green lighting under the control buttons and "speaker" grill. A 0.91" OLED display allows you to select which episode you would like to listen to and shows what's playing.

## Why I made this project

I started listening to The Magnus Archives, a horror podcast that tells the story through a series of tape recordings, a few months ago. Throughout the series, the tape recorders almost became characters of their own and I couldn't shake the idea of listening to the story on a replica of one. The hardest part of the project was definitely 3D-modeling the case itself, but I learned a lot about using Fusion, as well as designing PCBs.

## How to assemble 

Assembling the hardware itself should not be difficult. Once you have all the parts (as listed in Bill of Materials below) you will simply have to solder them onto their respective PCBs. To connect the two PCBs, you will need to take nine female-to-female jumper wires and connect each pin on the main PCB to its mate (5v to 5v, GND to GND, DIN to DIN, etc.). To connect the OLED screen to the main PCB, take four more female-to-female jumper wires and connect the pins of the display to the pin headers on the PCB as shown:

*add wiring diagram*

You will also need to wire the battery, charging board, step-up module and on/off switch as shown. These parts will be arranged in the case later, so it's important not to make the wires too short or too long.

*add wiring diagram*

Before putting the whole thing together, you will need to flash the firmware to the ESP32, as it will not be accessible when the main PCB is in the case. To flash the code, you will need to have the Arduino IDE installed (download the latest version [here](https://www.arduino.cc/en/software/)). You will also need to have the "esp32" board pack and a few useful libraries installed, which is very easy to do. Just go to "Boards" and search "esp32" and click install on the pack. Make sure that you select the pack with the title in all lowercase. To download the libraries, go the "Libraries" and install these libraries:

- Adafruit_GFX
- Adafruit_SSD1306
- FastLed
- DFPlayerMini_Fast


 Once your IDE is all set up, go to the file "[player-code.ino](https://github.com/fish-in-a-puddle/tma-player/blob/main/player-code.ino)" and copy its contents. Paste them into the IDE. Connect the ESP32 to your computer via USB. Select your board and port in the dropdown menu at the top of your screen and click "Upload". Boom! Code uploaded!

 The code is not the only thing you'll need to download, though. The DFPlayer Mini is a tiny MP3 player that reads audio files from a microSD card. The files have to be named and organized a certain way, though, in order for the DFPlayer to be able to play them. But we're getting a bit ahead of ourselves. Before organizing the files, you need to download them. Unfortunately, I can't provide them all here as the podcast is not mine to distribute, but I can show you how to get them yourself. You can download them all from YouTube with a third-party downloader like [this one](https://apps.microsoft.com/detail/xpffdcd2ps6dgh?hl=en-US&gl=CA) that I used. All 200 episodes can be found on [this playlist](https://www.youtube.com/playlist?list=PLSbuB1AyaJk8zTF3nE2KRxuixG_A5gBKJ) and you can download the entire playlist at once (plus the Oh... Hello. extra [here](https://youtu.be/0ue0QZ2ED9w?si=zBTRZmKF8gP67J3-)). Be forewarned, it may take several hours and altogether is about 4.5GB. When the files are downloaded, copy them over to your microSD card (which must be formatted as FAT32!) and rename them as 0001, 0002, 0003, etc. If you need more info, check out [this article](https://printed-droid.com/kb/dfplayer-mini-guide/)by Printed Droid - it helped me a lot. If you want, you can also cut out some of the ads in an audio editing software like Audacity.


Back to the hardware! 3D print the top and bottom of the case and and place the main PCB inside the bottom part. The microSD card slot and headphone jack should line up with the holes on the top of the case. Next, take the side PCB and fit it into the large slot on the right side of the bottom part. Secure it in place with electrical tape so it doesn't slide. Right next to the headphone jack, there is a large slot for the charging board. Position the board so the charging port is accessible and secure it with electrical tape. Do the same for the on/off switch slot above it. Place the OLED display on the top part so it is visible through the rectangular hole and - you guessed  it - secure it with electrical tape. As you put the top and bottom parts together, you may have to get a little creative arranging the battery and wires in the case. Once everything is packed away, screw together the top and bottom with four M3 screws.