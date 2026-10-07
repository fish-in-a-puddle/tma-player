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

I went back and looked at some of my work from last week and redid some of the routing to make everything fit better in the area around the pin headers that connect the main PCB to the side PCB and the headers that connect the 7-segment display to the main PCB. It took about half an hour, but I was able to fix some problems that had slipped my notice last week, like a pin that never got connected and a ground that was completely cut off. I also made a rough outline of the PCB's size. The finished player will be in the ballpark of 9x15x3cm, so I drew a rough approximation of that and that helped me figure out where to arrange the LEDs. 

<img width="1920" height="1080" alt="Screenshot (28)" src="https://github.com/user-attachments/assets/c5e1031a-cd78-46e2-86ed-38bf64681cf8" />

They need to be near the bottom so they shine through the tiny holes that would usually let a speaker be heard. I am not planning on adding a speaker to this as I am having a hard enough time with these LEDs though. When I went to route them, I noticed something really strange about the footprints. On two of the footprints, the pads are arranged like this:

<img width="1920" height="1080" alt="Screenshot (26)" src="https://github.com/user-attachments/assets/ae792e7b-846d-4bc4-be8a-ea924e6b5fd0" />

But on the other four, they look like this:

<img width="1920" height="1080" alt="Screenshot (27)" src="https://github.com/user-attachments/assets/72340675-ddc4-454b-a7c8-c5805c2499a0" />

The 5V and GND switched places! Which is weird because they're the EXACT SAME FOOTPRINT. I CHECKED. SEVERAL TIMES. This was very confusing and I checked all the footprint tools and they said there was no difference. Extremely weird and also bad because I can't route them as it wouldn't work when I solder the actual LEDs on. I'll try again tomorrow. Maybe time will fix this bug.

### Time today: 2 hours
### Total time: 3 hours

