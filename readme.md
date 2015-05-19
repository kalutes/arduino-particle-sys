About
-----
A particle system library for arduino  
Mainly intended to be used with low-resolution displays (like an 8x8 RGB matrix).  

Installation
------------
Clone the repo into the arduino libraries directory 

Dependencies
------------
The FastLEDPartMatrix.cpp and .h depend on the FastLED library

RAM Usage
---------
This version of the Particle System can be used for an arbitrary size of matrix (max. 256x256 Pixels)
The particle coordinates and other values use 16-bit integers to hold the relevant values.
If you have a LED Matrix of 8x8 Pixels or smaller on hardware with limited RAM (i.E. atmega328 with 2kb of RAM), I recommend to use the original Particle System: https://github.com/giladaya/arduino-particle-sys


Hardware
--------
A [Colorduino](http://imall.iteadstudio.com/development-platform/im120410004.html) or a [Rainbowduino](http://www.seeedstudio.com/depot/rainbowduino-led-driver-platform-plug-and-shine-p-371.html), mounted in a box behind a screen made of tracing-paper.  
Paint the inside of the box in black for some added contrast.  
![Hardware setup](http://giladlabs.files.wordpress.com/2013/02/hardware-setup1.jpg)


Examples
--------
You can see some of the example sketches in action in these videos:
- Spin: http://www.youtube.com/watch?v=dpA7wznAwgc
- Painter: http://www.youtube.com/watch?v=9r_VlEYINW4
- Flame: http://www.youtube.com/watch?v=w89Qrq5i1SE
