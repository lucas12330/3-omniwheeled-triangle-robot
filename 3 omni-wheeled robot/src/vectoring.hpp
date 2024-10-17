#pragma once
/*
    Auteur: Lucas Bezanilla Bou
    Date de création : 17/10/2024
    Description : Permet de mouvoir un robot 3 roue holonome. 
    fichier main : ./main.cpp
*/

// Inclusion des librairie et fichier en-tête
#include <Arduino.h>
#include <math.h>
#include <AFMotor.h>
#include <PS2X_lib.h>

// Déclaration des moteurs
AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);

/*
    En suposant que il y est 1 avant.
*/ 

// Déclaration des fonction
long vectoringOneWheel(long x, long y, long n);
void MoveFront3(int front, int speed);
void allInRelease();
void allInForward();
void allInBackward();

// Déclaration des variable Globale
bool initMoveFront3 = true;

// Déclaration des constante Globale


// Définition des fonction 

// Définition de la fonction de vectorisation pour 1 moteur
long vectoringOneWheel(long x, long y, long n) {
    long result = 0;
    long center = 57800;
    result = sin(sinh((170*sin(n))/sqrt(center - center * cos(n))))*sqrt(center - center * cos(n));
    return result;
}

// Déclaration de la fonction de mouvance sur plusieur roue avec variable avant
void moveFront3(int speed){
    if (initMoveFront3){
        allInForward();
        m2.run(BACKWARD);
        initMoveFront3 = false;
    }
    m2.setSpeed(speed);
    m3.setSpeed(speed);

    

}

// Déclaration de la fonction de libération de toutes les roues
void allInRelease(){
    m1.run(RELEASE);
    m2.run(RELEASE);
    m3.run(RELEASE);
}

// Déclaration de la fonction de toutes les roues en avant
void allInForward(){
    m1.run(FORWARD);
    m2.run(FORWARD);
    m3.run(FORWARD);
}

// Déclaration de la fonction de toutes les roues en arrière
void allInBackward(){
    m1.run(BACKWARD);
    m2.run(BACKWARD);
    m3.run(BACKWARD);
}