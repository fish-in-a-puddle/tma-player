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

# October 15, 2026: Starting the case

Finally worked up the courage to start working on the bottom part case in Fusion. I've never used Fusion before but it wasn't as hard as I thought it would be. It took a while, but I was able to use the Hackpad tutorial to get started. I apologize for the lack of detail in this update, but I didn't have time to do it when I actually finished last night and forgot to take screenshots as well. Basically, I fiddled around with the rectangle tool for a while, figured out how to make curves so I could round out the corners and managed to add some holes to put the top and bottom together. I didn't get around to extruding it and making it actually 3D, though (mostly because I was scared to exit the sketch mode).

<img width="1366" height="768" alt="Screenshot (53)" src="https://github.com/user-attachments/assets/74545eda-adac-49f0-b145-1a1304e4130a" />

### Time today: 50 minutes
### Total time:  7 hours and 20 minutes

# October 16, 2026: Working on the case

I came back to the case today and started by extruding the base to make the sides. I had to go back and forth between Fusion and Kicad a bit to get the measurements right, but I made an opening for the buttons on the side (which I will probably have to enlarge later) and an opening for the headphone jack. I made the headphone jack opening extra big because the walls of the case are 5mm thick and the headphones I plan on using have a fairly wide piece of plastic about 2mm back from the actual headphone jack, which is probably to make it easier to pull them out but in this case means there needs to be some extra space.

<img width="1366" height="768" alt="Screenshot (52)" src="https://github.com/user-attachments/assets/2492a92c-8aff-4843-9265-353fdec8d36d" />

After realizing that the headphones needed extra space, I panicked about the charging port and how much space it would need. I went to AliExpress and spent a while trying to find a decent charging board and step-up module. Turns out I didn't really need to worry about that, as I belatedly realized that I could just MEASURE THE CHARGING CABLE, but I did nail down two of my sources for parts, so yay for that. 

<img width="1366" height="768" alt="Screenshot (50)" src="https://github.com/user-attachments/assets/99de0a7f-773c-4df8-8c9d-2d039ece96e2" />

<img width="1366" height="768" alt="Screenshot (51)" src="https://github.com/user-attachments/assets/4e5e5314-8828-4367-beef-5e0dfeedc6d1" />

*This update brought to you by me starting season 4 of The Magnus Archives and strengthening my resolve to learn Fusion*

### Time today: 1 hour
### Total time: 8 hours and 20 minutes

# October 20, 2026: Fixing the side PCB and working on the case

Today I spent a quick half hour making a few changes to the PCB with the buttons on it and the case to accommodate it. Since my Hackpad PCB came yesterday, I realized that the keycaps need a bit more space than I thought. Now there's one extra millimeter between the footprints and another five millimeters of space in the case. So not a lot happened, but I have early morning band and a chemistry test tomorrow morning so that's it for tonight folks.

<img width="1366" height="768" alt="Screenshot (54)" src="https://github.com/user-attachments/assets/dcc4e7d8-7422-49f3-8899-81e74bc72f08" />

### Time today: 30 minutes
### Total time: 8 hours and 50 minutes

# October 28, 2026: Downloading episodes, finding parts and tracking down datasheets

After a busy week with no time to work on this (plus almost losing the flash drive with all my work lol) I finally got back to this project. I knew from the start that getting the audio files themselves may not be easy, but that didn't really turn out to be true. All I really had to do was install a YouTube downloader and grab the link to the official playlist. 

<img width="1920" height="1080" alt="Screenshot (34)" src="https://github.com/user-attachments/assets/a6f15f58-7fde-4051-93d4-4ad67812e76f" />

I'll have to go through the files and cut out the ads for other podcasts at the start (if you're reading this Mr Jonny Sims or Mr Alexander Newall I'm sorry. I still listen to your podcast on the app too but this is so much cooler and there's no fast-forward on the chip I'm using so I just have to cut the ads I'm sure you understand) but otherwise it's just the download time that's not to my advantage. I'll just toss the clips in Audacity or something to trim stuff and rename the files. Since there are, you know, 200 episodes each 20-30 minutes in length, the downloads are taking a while. I'm at 30% now and it's been nearly two hours so hopefully I can just leave it running overnight. While the downloads were running, I went hunting for parts and eventually datasheets and user opinions for said parts which was a bit of a rabbit hole. It turns out that the REAL DFPlayer Mini chip, YX5200-24SS, has been discontinued for a few years and it can be tough to find a suitable substitute. After going through an in-depth comparison article and tracking down a very thorough explanation on a forum that started in the year 2000, I found that the chip on the module I had been leaning towards was the YX5200-24QS which is supposed to be practically identical to the YX5200-24SS.

<img width="1920" height="1080" alt="Screenshot (35)" src="https://github.com/user-attachments/assets/75cd02d2-0119-4f86-9863-fd138c9dc0a8" />

Now, I don't know if the product will actually have this exact chip but it's looking like the best chance I've got at getting a module with a decent chip. The other parts were much easier, even the Seeeduino Xiao wasn't hard to find. Next up, more 3D modeling (I hate it I hate it I hate it) (I actually don't but it's kind of frustrating)

*Today's update brought to you by me realizing I'm almost done of season four and that I need to lock in on this project*

### Time today: 35 minutes
### Total time: 9 hours and 25 minutes

# November 1, 2026: Nearly finished case bottom and began case top

Happy Halloween guys we are back in business. I have almost finished the bottom part of the case for the project and have finally gotten up the courage to start the top. While the bottom part was pretty simple except for the openings for headphones, the micro SD card and the charging port (which are only harder because I don't know the exact measurements of the charging board relative to the PCB) but on the top part there are a lot more details, like the cassette window and the tiny holes for speakers.

<img width="1366" height="768" alt="Screenshot (56)" src="https://github.com/user-attachments/assets/29dd0d26-3fb5-4835-bc6c-ee874fa78342" />

It took a few tries, but I think I know what I'm doing now.

<img width="1366" height="768" alt="Screenshot (55)" src="https://github.com/user-attachments/assets/b0718f62-5e5b-4ee2-a740-839dd0036f9e" />

I'll need to add an opening for the display (which I'm considering making an OLED instead of a 7-segment display to A: make it a bit more clear what is playing and B: make it look a bit more like an actual old recorder) which should be fairly easy. I am also planning on putting the Sony symbol on the front as well, which is probably copyright infringement but really does make it look more real. Maybe I'll make up another company to put there instead. 

*This entry brought to you by me getting a callback for my school musical! Yay!*

### Time today: 1 hour and 25 minutes
### Total time: 10 hours and 50 minutes

# November 2, 2026: Editing the MP3s

I decided to take a break from 3d modeling today and to start trimming the MP3 files I downloaded, renaming them and converting them to mono. The DFPlayer Mini can only play mono but the original downloads were stereo, so I fixed that. I also trimmed out the ads and Patreon shoutouts (again, sorry Rusty Quill guys, but on this it's just the intro, episode and credits) and renamed the ones I converted properly so the DFPlayer Mini library can recognize them. I'm going to try to do ten episodes a day until I've converted everything, which will probably be accompanied by some 3d modeling most days. Gotta lock in and get this project ready to ship before the end of November!

<img width="1366" height="768" alt="Screenshot (57)" src="https://github.com/user-attachments/assets/d9fb2e06-10d2-49e6-9176-7891ad23cd73" />

### Time today: 35 minutes
### Total time: 11 hours and 25 minutes

# November 3, 2026: Trimming MP3s and working on the case

Back to 3d modeling hooray. Added some more holes to the top part to simulate the speaker that would be in a real tape recorder, which went smoothly. I also realized on the bus home today that duh, I don't have to take out one of the layers when converting the MP3s to mono. After this epiphany, I went back and redid the episodes from yesterday. I forgot to turn on the timelapse for part of it, though, so I didn't record like a third of the time today.

<img width="1366" height="768" alt="Screenshot (58)" src="https://github.com/user-attachments/assets/99188a33-9c3f-464b-9d12-47e214aa3a74" />

### Time today: 50 minutes
### Total time: 12 hours and 15 minutes

# November 5, 2026: Keep going on model and files

Ok, so I basically did exactly what I did last time. Ten episodes converted to mono, a couple rows of holes in the top of the 3d model. Not a whole lot to say, but it's coming along smoothly. Once I get past all these little holes, I think I'll have to revise the LED placement on the main PCB to make sure the light comes through in the right spot.

<img width="1366" height="768" alt="Screenshot (59)" src="https://github.com/user-attachments/assets/88e5db1e-d7cc-4494-9bee-f3fd38a89250" />

*This update is brought to you by a KitKat bar. A Canadian one, not an American one. The American ones taste weird. I'm so sorry you have to live like that Americans*

### Time today: 50 minutes
### Total time: 13 hours and 5 minutes

# November 8, 2026: Almost finished with the top of the case!

Today I finally finished the the little speaker holes and got most of the details of the tape done! I ended up having to redo the rectangle to make it look more authentic, but I was also able to find an SVG of the Sony logo. It was looking kind of plain (and directly plagiarized) though, so I added a pupil to the "o" to turn it into an eye. It looks pretty good so far, but I think I'll add some simple eyelash details for more of an effect.

<img width="1366" height="768" alt="Screenshot (60)" src="https://github.com/user-attachments/assets/31bc2f2a-1ace-416a-b1a7-349958276d29" />

As you can see, it's finally starting to come together. I had quite a time trying to make the curves for the tape details, though, as I managed to forget every tool and how it worked today. Eventually the Arc tool and a good old copy-paste got the area around the wheels of the tape right. I would like to apologize in advance to people who actually know what tape recorders look like because I'm sure there are plenty of offending inaccuracies visible to a trained eye. My eye is untrained and since I have seen a Walkman in person, like, twice, a lot of nuance is probably escaping me. My main criteria is "Does it look cool?", "Does it resemble the reference vaguely?" and "Can I get away with it?". Case in point: the 0.91" OLED that will be in the blank rectangle you see on the model. It will show options on startup and what track is playing. My hope is that it will look like the little text that usually says "Featuring auto-stop technology" or "Built-in microphone" or something, but only putting the thing together will give an answer.

### Time today: 1 hour and 35 minutes
### Total time: 14 hours and 40 minutes

# November 9, 2026: Adding OLED window and eye details to the 3D model

Today I looked into using an OLED to display which track is playing and made a small window in the model for it. It's in the spot that would usually have text saying "Built-in microphone" or would tell you how good the playback was. One that was done, I started to add some more details to the eye in the "O" of Sony. I thought it would look better with stylized eyelashes to emphasize that it's not just an oval in a circle. Turns out the eyelashes are really hard to do and they kept looking weird or uneven. After a while, I had to just delete everything and start over simpler. Once I had a decent shape set up, I just left it alone. I'll come back to this tomorrow and finish it up.

<img width="1366" height="768" alt="Screenshot (61)" src="https://github.com/user-attachments/assets/c51bce4a-d727-4752-a901-b83760f4e07d" />

### Time today: 1 hour and 15 minutes
### Total time: 15 hours and 55 minutes

# November 10, 2026: Finishing the model and PCB

The case and PCB are both done!! I finished up with the eye details and added a slot for the charging board in the bottom part of the case so I can charge the battery without opening the whole thing up. I also fixed up the PCB so the LEDs will shine through the right spot in the case, which took a little while but has worked out very well. Now that the physical parts are ready, I need to write the code, which I'll try to do this weekend.

<img width="1366" height="768" alt="Screenshot (62)" src="https://github.com/user-attachments/assets/846a6b07-a800-481f-9fcd-739e9822af2e" />

### Time today: 1 hour and 35 minutes
### Total time: 16 hours and 30 minutes

# November 13, 2026: Starting the code

Today I started to write the code for the player! I started with getting a small fade-in fade-out animation for the LEDs down. I'm using the FastLED library for this for simplicity's sake. I also added a small "placeholder" loop in for the DFPlayer Mini code. For that, I'm using the DFPLayerMini_Fast library because, although kind of old, it's still better than the official library which is even older and much worse. I'm leaving it at that for tonight but tomorrow I'll get the OLED code started. Then I can get to the hard part - the code to let you select the season and episode you want when you turn it on. That part will probably go in the setup loop so it only runs once. If you want to go back and select a different episode, you can turn it off and on again or spam the next or previous track buttons.

<img width="1366" height="768" alt="Screenshot (63)" src="https://github.com/user-attachments/assets/b12e301c-0b40-45e9-96e5-6ee33570ec17" />

*This update brought to you by my sister finding a KitKat bar with no wafer. Just solid chocolate. It was kind of weird*

### Time today: 40 minutes
### Total time: 17 hours and 10 minutes

