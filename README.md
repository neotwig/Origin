# Origin

Origin is an open-source, customizable touchscreen HDMI switch with IR remote control.

This project was created by Ryan Black with coding by David Williams.  Documentation written by Ryan Black.

An annoucement video with a demonstration of a 25 port unit is [posted here](https://youtu.be/hIJCa2q1oEo).

Special thanks to Bob from [RetroRGB](https://www.retrorgb.com/) for his help in advertising the first and second generation units, allowing me to recoup some of my development costs.

## Features

* Can be built in 5, 9, 13 or 25 port configurations (17 or 21 ports are possible, but not yet implemented)
* 3.2" or 7" touchscreen display with brightness and auto-dimming / auto-off settings
* Infrared remote control, user-programmable to work with most any IR remote control
* User-configurable input names and color scheme
* Uses 1 to 6 HDMI switchboards internally.  Origin is designed to power off any switchboards not currently needed to conserve power.  Only 1 or 2 switchboards are powered at any given time.

## License

I am releasing the source code and build instructions under the MIT license.  You are free to use any of it however you would like.  If you profit from my work, please consider sending a little something my way since I did invest quite a bit of time and money into this project.

There is no warranty of any kind, and it is up to you to make sure you build and use the device SAFELY.  If you plug 25 consoles into a lightweight extension cord and burn down your house, that is on you!  If you don't know how to work with electronic devices and electricity safely, this project is not for you.  Please game responsibly.

## Limitations

* I am not selling these devices.  I have a few extras I may sell to recover some of my development costs, but once they're gone, they're gone.  Total parts cost is high and the build is time consuming, so I cannot make these at a price most people would be willing to pay.  Current cost for PARTS ONLY for a 3.2" 9 port model is $250, and a 7" 25 port model is $500.
* I am not providing support for these devices.  Sorry, I am very busy and don't have the time to provide free technical support.
* I am NOT an expert at any of this.  I know just enough to get this working but this is a hobby, not a career.  There are probably better ways to do the electronics, the coding, and the 3D modeling for the case.  I welcome any and all improvements to the project.
* As of this writing, the 3.2" display models support 5, 9, and 13 port configurations.  The 7" display models only support 25 port configurations.
* The HDMI switchboards used internally DO support auto-switching of devices, but Origin does NOT support this as a whole.  Auto-switching will occur within a 5 port switchboard, but not for the rest of Origin.  Example: Ports 6-10 on a 25 port model are on the same physical switch board.  If I am using device #6 and turn it off, and device #10 is powered on, the switchboard will auto-select device #10.  However, if I then turn on device #2 and turn off device #10, it will NOT switch to device #2 since that is a different switchboard.

## Feature Additions

At this point in time, I do not plan to add any more features.  There are other things I would like to see added, but I am leaving this to the community.  Some ideas include:
* Protections against the user selecting conflicting colors, such as black text on a black background
* Wi-Fi / Ethernet / Bluetooth connectivity
* Web interface and/or phone and tablet apps to control and configure Origin
* The ability to control power for connected systems, such that pressing the NES button turns on your NES console via a smart outlet
* Support for pictures instead of just text, so that the user can touch an image of a console
* Full-screen display of the selected input for easier reading from across a room, especially when changing inputs via remote control

I am not going to claim that the GUI is perfect, but I did invest extra time in making it as close as I could.  I am certainly open to improvements, but fair warning that I am picky about this.  For example, Nextion does not natively allow for centering of multi-line text on buttons.  It "centers" the text as a block, with all lines left-justified based on the longest line.  I find this to be inexcusable, so I wrote extra code to implement proper multi-line centering with hotspots instead.  This does make the code more complex, but I think the user interface looks substantially better as a result.

## Hardware Build Video

I've created a [build video](https://youtu.be/xENX4zxrqHY) explaining the process from beginning to end, excluding the 3D printing of the enclosure.  The video is for a 5 port model, but the process is nearly identical for any port configuration.  The video is 1 hour and 42 minutes long.  I sped up some of the more tedious and repetitive tasks to shorten it as much as I could.

When building a device, you'll need to place a FAT32 formatted Micro SD card in the standalone internal SD card reader (NOT the one on the Nextion display).  You can pre-populate it with one of the provided sample preference files if you want, but if one doesn't exist then the software will generate a new one for you.

Note that the pin definitions are specified in the file "libraries\Origin\OriginConfig.h", so you may want to reference that for hooking up the wiring.

The commercial HDMI switchboards I've used are all internally branded as "ASK Technology" models "HDSW0015M1_1V3" or "HDSW0015M1_1V4".  Other models may not work, or may require significant modifications to the board, wiring, code, or enclosure design.

## Software Build Instructions

Requirements
* [Arduino IDE](https://www.arduino.cc/en/software) (developed with version 1.8.13)
* [Nextion Editor](https://nextion.tech/nextion-editor/) (developed with version 1.63.3)

Place the contents of the "libaries" folder inside your Arduino libraries folder.  On Windows, this is in your Documents library under Arduino\libraries.

Edit the file "OriginConfig.h" to specify the number of connected HDMI switches.  A 9 port Origin uses 2 switchboards, so set NUM_SWITCHES = 2.  A 25 port Origin uses 6 physical switchboards, so set NUM_SWITCHES = 6.

Connect the Arduino Mega 2650 to your computer via USB.  Select the Arduino Mega 2560 board in the Tools menu under the Board submenu, and choose the port your Arduino is connected to.  If you've already removed the Arduino fuse (per the build instructions) and/or connected the Arduino to other Origin components such as HDMI switchboards and a touchscreen, you must supply external power to the Origin box in order to program the Arduino.

The Nextion display is programmed with a Micro SD card.  If you have the same Nextion display model that I used, you can simply copy the appropriate .tft file to a FAT32 formatted Micro SD card.  If you are using a different model, you have to export a TFT file using the Nextion Editor software.  To program the Nextion, first turn Origin off.  Insert the Micro SD card into the slot on the bottom of Origin.  Then power Origin on, and you should see the display install the new code.  Once it reports that it is complete, you may power off Origin and remove the Micro SD card.

## History

This is the third generation of the Origin HDMI switch, but the first two were not publicly released.  I developed the first two versions entirely by myself, which proved to be quite a challenge!  I selected the name "Origin" due to the purpose of the device.  My goal was to have a single point to select any video game console or multimedia device, rather than having to change inputs on the TV and also on a variety of switchboxes.  Hence, the "Origin" of all video signals in your entertainment setup would be this switchbox, and your TV's input selection never has to change.

I started by making a 17 port version based on HDMI 1.3b switches.  It was a learning project, to push the limits of my electronics, coding, and 3D modeling skills.  All of these things were purely hobbies that I learned by watching YouTube videos, reading documentation and experimenting on sacrificial electronics.  I originally only made one Origin device for my personal use.  After successful completion of the project, I decided to make and sell two more.  Unfortunately they were expensive to make, time consuming to build, and would not be feasible to sell for profit.

The second generation was also a 17 port version, and it was based on HDMI 1.4 switches.  The goal of the second version was to reduce the cost of materials and possibly produce small batches for sale.  Unfortunately the cheaper components led to compatibility issues with some systems such as Hi-Def NES and UltraHDMI N64 modded consoles.  The design of the cheaper HDMI switches allowed for direct control over input selection which was an advantage over both the first and third iterations of Origin, but the compatibility issues and lack of support for HDMI 2.0 made it less desirable.  Seven of these models were made and sold, but despite the cheaper materials they were still not profitable, partly due to the compatibility issues.

I set forth to develop a third generation Origin device.  By this time my game console collection had grown beyond the 17 ports of the original version, and HDMI 2.0 support was becoming more important.  Since the first two models were not profitable, and the parts to support HDMI 2.0 were even more expensive, I decided to throw profitability out the window and simply develop the best switch possible, regardless of cost, with the intention of open-sourcing the device rather than trying to sell it.  I purchased and tested numerous HDMI switches and cables.  I had to tear each HDMI switch apart to determine how readily it could be controlled by an Arduino.  I focused on models that are widely available since development takes a long time and there's no point in open-sourcing something if the hardware is discontinued by the time the project is complete.  Eventually I landed on a set of parts that provided the best compatibility, modability, and availability.  The list of parts is included in this release, though availability may change as time goes on.

I recruited my friend David to help set with the coding part of the new Origin project.  Unlike myself, he does coding professionally and has a much better understanding of how to arrange things.  Don't blame him for any mess you might find in the code though, as I did contribute a fair amount with my duct tape and bubblegum "just get it done" coding skills.  :)

Traditional Arduino-compatible touchscreen displays are very slow, and I knew that something better would be needed for anything larger than 17 ports.  I landed on a much more expensive, but much more powerful Nextion display.  These displays have their own processor and their own programming environment and language.  It presented another learning curve, but I think it was the right choice.  A Nextion expert could significantly improve the way it's implemented, but David and I came up with a reasonably fast and user-friendly interface.  It's our first Nextion project, so improvements are welcome!

This project has taken approximately 3 years to complete as a hobby project, not a full-time endeavor.  It has been an expensive undertaking, with the need for 3D printing hardware, filament, soldering tools and supplies, and a fair amount of HDMI switches which were sacrificed to find the best configuration.
