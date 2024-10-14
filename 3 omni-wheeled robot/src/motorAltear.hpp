#pragma once

#include <AFMotor.h>
#include <Arduino.h>    

void motor(int num, int speed);
void motor(int num, int speed){
    AF_DCMotor m1(num);
    if (speed > 255 || speed < -255){
        speed = 255;
    } else if (speed = 0){
        m1.run(RELEASE);
    } else {
        if (speed < 0){
            m1.run(BACKWARD);
            m1.setSpeed(speed);
        } else {
            m1.run(FORWARD);
            m1.setSpeed(speed);
        }
    }
}