--------------------------------------------------------------------------------
OLED Screen Tester Firmware. v1.0

Created by Wierzbowsky [RBSC] in 2025 for testing of OLED 128x32 screens
Public domain: use in any of your projects freely, no reference is needed
--------------------------------------------------------------------------------

About
-----

This is a simple tester firmware for Arduino (Atmega328P-based) boards. It can be used to test
128x32 OLED screens before installing them into Gotek floppy drive emulator. Please use the
latest Adruino IDE version and the follwing OLED screen libraries (see the png file):

 - Adafruit_GFX
 - Adafruit_SSD1306

Connect the OLED screen as follows:

 - VCC of the screen to 3V3 pin of Arduino board
 - GND of the screen to GND pin of Arduino board
 - SCK of the screen to A5 pin of Arduino board
 - SDA of the screen to A4 pin of Arduino board

The test consists of several different parts - full filling test, frame test, table test, flicker
test, line filling test and text scroller test. After the last test the version info will be shown
and the test restarts after 10 seconds.

The video of the testing could be found on Wierzbowsky's Youtube channel:

https://www.youtube.com/@alexwierzbowsky

Feel free to check other interesting project on the RBSC's website:

https://rbsc.su/en/


IMPORTANT!
----------

All the files and information are provided for free, without any liability (see the disclaimer.txt
file). The provided information, software or hardware may be used for commercial purposes if anyone
figures our how to do that. This project must not be used to harm any individual or any country.
