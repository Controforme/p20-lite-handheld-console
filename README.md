# p20-lite-handheld-console

This repository contains the code for P20 lite to handheld console convertion.
The goal of the project is to turn an old smartphone into a PSX emulation device. The code provided is used to manage a controller inspired by the original PSX controller (without analog sticks and triggers).

Detailed project page: https://www.controforme.com/project/gaming-handheld-from-old-smartphone/

The code runs on a Pro Micro or Arduino Leonardo board connected to a dpad (4 buttons), 4 face buttons, 4 back buttons, and 2 additional buttons for select and start.

IMPORTANT NOTE: The code has been "manually" optimized to run on an older android phone (Huawei P20 lite) which recognize all the buttons without additional configuration needed (with the exception of start and select not being recognized in some apps like ES-DE). If used with more modern smartphones, the buttons are assigned differently, thus the code needs to be changed.

Based on the "Simple arcade stick example" from the "Arduino Joystick Library by https://github.com/MHeironimus

Link to the Library: https://github.com/MHeironimus/ArduinoJoystickLibrary

PINS USED IN THE PROJECT:

X AND Y AXIS

Pin 14 -> DPAD UP

Pin 10 -> DPAD RIGHT

Pin 15 -> DPAD DOWN

Pin 16 -> DPAD LEFT

FACE BUTTONS

Pin 7 -> Xbox A - PS cross

Pin 5 -> Xbox B - PS circle

Pin 8 -> Xbox X - PS square

Pin 6 -> Xbox Y - PS triangle

SHOULDER BUTTONS

Pin 20 (A2)-> Xbox LB - PS L1

Pin 3 -> Xbox RB - PS R1

Pin 19 (A1)-> Xbox LT - PS L2

Pin 4 -> Xbox RT - PS R2

START AND SELECT

Pin 18 (A0)-> Xbox back - PS select

Pin 9 -> Xbox options - PS start
