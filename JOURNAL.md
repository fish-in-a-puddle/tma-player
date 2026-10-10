# October 2, 2026 - Designing the PCB
Today I spent a while working on the schematic and routing for the main PCB, which has the Xiao, DF Player Mini, headphone jack and LEDs for effect. The other PCB, with the buttons and LEDs underneath, is to be put on the side of the player to replicate the buttons on the side of a tape recorder like this one: 

<img width="300" height="225" alt="3FWBAYc2eKwBWGnF" src="https://github.com/user-attachments/assets/d55ee92a-ded8-4abc-a2c2-1c8063be6f18" />

I had already mostly finished the side PCB before starting to track my progress, so I left it alone for today.

I had spent a couple of hours last week finding the right KiCad footprints to use for the PCB, but it turns out that I had made a mistake in finding the right footprint for the Seeeduino Xiao ESP-32-C3 module. The footprint that I used for the module did not account for header pins but instead intended the module to be soldered directly to the PCB, which is not what I was looking for since this wouldn't allow connections on the back.

<img width="1920" height="1080" alt="Screenshot (23)" src="https://github.com/user-attachments/assets/a17ad052-5d9b-40b2-81af-854d8318ceaa" />

So, back to the hunt I went. It only took about ten minutes this time to find the right footprint, which was almost identical save for the handy pin headers. Then I went back to routing the PCB. I went back to reassign footprints and remembered to add resistors to the RX and TX connections of the DF Player Mini as well (which I read can help cut down on staticky noise while audio is playing). A bit more work on routing the PCB and it was starting to look good!

<img width="1180" height="789" alt="Screenshot (24)" src="https://github.com/user-attachments/assets/cde19b2d-11d7-473b-b2f0-07503251e8a2" />
 
Next time, I will touch up the routing and work on routing the LEDs, which are in a bit of a weird spot, so it'll probably take a little while.

### Time today: 1 hour
### Total time: 1 hour

# October 7, 2026 - Routing the PCB

I went back and looked at some of my work from last week and redid some of the routing to make everything fit better in the area around the pin headers that connect the main PCB to the side PCB and the headers that connect the 7-segment display to the main PCB. It took a while, but I was able to fix some problems that had slipped my notice last week, like a pin that never got connected and a ground that was completely cut off. Plus, I took another look at the side PCB that will have the buttons and fixed some problems there too.I also made a rough outline of the PCB's size. The finished player will be in the ballpark of 9x15x3cm, so I drew a rough approximation of that and that helped me figure out where to arrange the LEDs. 

<img width="1920" height="1080" alt="Screenshot (28)" src="https://github.com/user-attachments/assets/c5e1031a-cd78-46e2-86ed-38bf64681cf8" />

They need to be near the bottom so they shine through the tiny holes that would usually let a speaker be heard. I am not planning on adding a speaker to this as I am having a hard enough time with these LEDs though. When I went to route them, I noticed something really strange about the footprints. On two of the footprints, the pads are arranged like this:

<img width="1920" height="1080" alt="Screenshot (26)" src="https://github.com/user-attachments/assets/ae792e7b-846d-4bc4-be8a-ea924e6b5fd0" />

But on the other four, they look like this:

<img width="1920" height="1080" alt="Screenshot (27)" src="https://github.com/user-attachments/assets/72340675-ddc4-454b-a7c8-c5805c2499a0" />

The 5V and GND switched places! Which is weird because they're the EXACT SAME FOOTPRINT. I CHECKED. SEVERAL TIMES. This was very confusing and I checked all the footprint tools and they said there was no difference. Extremely weird and also bad because I can't route them as it wouldn't work when I solder the actual LEDs on. I'll try again tomorrow. Maybe time will fix this bug.

*Today's update was made possible by pure hate for this issue and the desire to complain about it loudly*

### Time today: 2 hours
### Total time: 3 hours

# October 9, 2026: Finishing the PCB

I figured out the issue with the footprints - it turns out I wired the schematic wrong, mixing up the 5v and GND on two of the LEDs. It just took a fresh brain and checking the datasheet and the schematic to fix this lol. Once I got that sorted out, I was finally able route the LEDs and get everything in its place. It took some tweaking to figure out how to arrange the LEDs, but we got there in the end.

<img width="1920" height="1080" alt="Screenshot (31)" src="https://github.com/user-attachments/assets/f893dc42-74e6-4b01-b033-70feec7f66fb" />

I had to make a small modification to the order of the pins on the connector that connects to the side PCB to make everything fit properly, so I also had to go back and make some changes to the side PCB (again) but it has worked really well as far as I can tell.

<img width="1920" height="1080" alt="Screenshot (30)" src="https://github.com/user-attachments/assets/901aeeae-ce4a-4a6e-aeae-92866f616ea2" />

Right now, I am cautiously optimistic that this is pretty much it for the PCB design except for fixing up the silkscreen designs because I forgot to save and lost them :(. 
 
<img width="1920" height="1080" alt="Screenshot (29)" src="https://github.com/user-attachments/assets/50f6e612-3bc0-453c-a2e1-e5f07718e502" />

*Today's progress is brought to you by the album Day and Age by the Killers and also several Reese's peanut butter cups*

### Time today: 1.5 hours
### Total time: 4.5 hours

# October 10, 2026: Back to the PCB

I lied. I was not nearly done with the PCB. I went back and checked some wiring resources for the DFPlayer Mini because I wasn't sure if I was right about how I had connected the audio jack. This led me down a rabbit hole of double checking everything which led me to question how I was adding the battery. The Xiao board I'm using is capable of charging a battery and getting its power from that, so I considered changing how I was connecting the battery. However, this did not work because when I found a schematic symbol that included the battery pads it didn't work with the footprint I was using. I considered using a different footprint, but realized that if I took this path with the battery the device would have to be turned on in order to charge, which isn't ideal, and I'm tired. I'm sticking with having the battery circuit separate from the PCB and a diode to prevent issues. Now I just have to actually add the logo and then I can move on to the CAD modeling of the case.

<img width="1920" height="1080" alt="Screenshot (33)" src="https://github.com/user-attachments/assets/1732bd92-0f27-4a8e-836c-09fa22c10ad7" />

*Today's progress brought to you the thought of pumpkin pie tomorrow (happy Thanksgiving to my fellow Canadians)*

### Time today: 2 hours
### Total time: 6.5 hours
