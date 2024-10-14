#include <Arduino.h>
#include <PS2X_lib.h>
#include <motorAltear.hpp>


PS2X ps2x; // create PS2 controller object


// Déclaration de toute les variable non constante
int lY = 0;
int lX = 0;
int rY = 0;
int rX = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  const int error = ps2x.config_gamepad(21, 3, 20, 2, false, false);
  switch (error)
  {
  case 0:
  Serial.println("Controller found!");
    break;

  case 1:
  Serial.println("Controller not found, check wiring or power.");
  break;

  case 2:
  Serial.println("Controller found, but not in PS2 mode!");
  break;

  case 3:
  Serial.println("Controller refusing to enter Pressures mode, may not support it.");
  }
  
  

}

void loop() {
  ps2x.read_gamepad();
  lX = ps2x.Analog(PSS_LX);
  Serial.println(lX);
}
