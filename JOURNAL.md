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
