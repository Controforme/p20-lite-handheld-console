/*Retro style gamepad (dpad + 4 face buttons + 4 back button + start and select)
  2025 Controforme

  tested on LineageOS on Huawei P20 Lite (with online gamepad tester)
  board used: pro micro / leonardo

  Based on the "Simple arcade stick example" from the "Arduino Joystick Library
  https://github.com/MHeironimus/ArduinoJoystickLibrary
  
  The sketch demonstrates how to read fourteen
  Arduino Pro Micro digital pins and map them to the
  Arduino Joystick library.


  Original gamepad example by Matthew Heironimus
  2016-11-24
  Adapted for arcade machine setup by Ben Parmeter
  2019-05-20
  Adapted for use on Huawei P20 lite with lineageOS by Controforme
  2026-01-18
  --------------------------------------------------------------------*/

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  10, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

//Buttons pins on the board<---------------------------------------------------Change here for different wiring
//X and Y axis
int up_pin = 14;
int right_pin = 10;
int down_pin = 15;
int left_pin = 16;

//Face buttons
int cross_pin = 7; //xbox A
int circle_pin = 5; //xbox B
int squareb_pin = 8; //xbox X
int triangle_pin = 6; //xbox Y

//Shoulder buttons
int L1_pin = 20; //pin A2-20 - xbox LB
int R1_pin = 3; //xbox RB
int L2_pin = 19; //pin A1-19 - xbox LT
int R2_pin = 4; //xbox RT

// Start and select
int select_pin = 18; //pin A0-18 - xbox back / ps4 share
int start_pin = 9; //xbox/ps4 options

void setup() {
  // Initialize Button Pins
  pinMode(up_pin, INPUT_PULLUP);
  pinMode(right_pin, INPUT_PULLUP);
  pinMode(down_pin, INPUT_PULLUP);
  pinMode(left_pin, INPUT_PULLUP);
  pinMode(cross_pin, INPUT_PULLUP);
  pinMode(circle_pin, INPUT_PULLUP);
  pinMode(squareb_pin, INPUT_PULLUP);
  pinMode(triangle_pin, INPUT_PULLUP);
  pinMode(L1_pin, INPUT_PULLUP);
  pinMode(R1_pin, INPUT_PULLUP);
  pinMode(L2_pin, INPUT_PULLUP);
  pinMode(R2_pin, INPUT_PULLUP);
  pinMode(select_pin, INPUT_PULLUP);
  pinMode(start_pin, INPUT_PULLUP);
  /*pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);*/

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

// Last state of the buttons
int lastButtonState[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buttonMap[16] = {up_pin, right_pin, down_pin, left_pin, cross_pin, circle_pin, select_pin, squareb_pin, triangle_pin, start_pin, L1_pin, R1_pin, L2_pin, R2_pin/*, 18, 21*/};
/* Buttons order for old android phones:
cross/xbox A = 0;
circle/xbox B = 1
square/xbox X = 3
triangle/xbox Y = 4
L1/xbox LB = 6
R1/xbox RB = 7
L2/xbox LT = 8
R2/xbox RT = 9
start and select -> to be mapped in software
*/

void loop() {

  // Read pin values
  for (int index = 0; index < 16; index++)
  {
    int currentButtonState = !digitalRead(buttonMap[index]);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
        case 0: // UP
          if (currentButtonState == 1) {
            Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 1: // RIGHT
          if (currentButtonState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 2: // DOWN
          if (currentButtonState == 1) {
            Joystick.setYAxis(1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 3: // LEFT
          if (currentButtonState == 1) {
            Joystick.setXAxis(-1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 4: // B0 - cross - A
          Joystick.setButton(0, currentButtonState);
          break;
        case 5: // B1 - circle - B
          Joystick.setButton(1, currentButtonState);
          break;
        case 6: // Select - to be mapped in software
          Joystick.setButton(2, currentButtonState);
          break;
        case 7: // B3 - square - X
          Joystick.setButton(3, currentButtonState);
          break;
        case 8: // B4 - triangle - Y
          Joystick.setButton(4, currentButtonState);
          break;
        case 9: // start - to be mapped in software
          Joystick.setButton(5, currentButtonState);
          break;
        case 10: // B6 - L1 - LB
          Joystick.setButton(6, currentButtonState);
          break;
        case 11: // B7 - R1 - RB
          Joystick.setButton(7, currentButtonState);
          break;
        case 12: // B8 - L2 - LT
          Joystick.setButton(8, currentButtonState);
          break;
        case 13: // B9 - R2 - RT
          Joystick.setButton(9, currentButtonState);
          break;
        /*case 14: // Other Button 3 - unused
          Joystick.setButton(10, currentButtonState);
          break;
        case 15: // Other Button - unused
          Joystick.setButton(11, currentButtonState);
          break;*/
      }
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(10);
}
