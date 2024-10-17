#pragma once

// Include librairi
#include <Arduino.h>
#include <Servo.h>

// Déclaration des variable
bool change = true;

Servo servo;

void setInServo(int pwmPin){
    pinMode(pwmPin, OUTPUT);
}

void moveServo(int degrees, int pwmPin){
    if (change == true){
        setInServo(pwmPin);
        change = false;
    }
    servo.attach(pwmPin);
    servo.write(degrees);
}