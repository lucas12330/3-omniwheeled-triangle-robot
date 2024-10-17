#include <Arduino.h>
#include <PS2X_lib.h>
#include <motorAltear.hpp>
#include <vectoring.hpp>
#include <Servo.h>
#include <moveServo.hpp>


PS2X ps2x; // create PS2 controller object
Servo servo;

// Déclaration de toute les variable non constante
int lY = 0;
int lX = 0;
int rY = 0;
int rX = 0;

int val = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
  pinMode(A0, INPUT);
  // put your setup code here, to run once:
  int error = ps2x.config_gamepad(21, 2, 20, 3, false, false);
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
  break;
  }
  
  

}

void loop() {
  moveServo(analogRead(A1), 10);
  delay(10);
}
