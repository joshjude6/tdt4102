#pragma once
#include "std_lib_facilities.h"

constexpr double gravity = 9.81;
constexpr double pi = 3.14159265359;


//oppgave 1a - akselerasjon oppover
double acclY();

//oppgave 1b - fart i y-retning
double velY(double initvelocityY, double time);

//oppgave 1c - posisjon i x og y-retning
// posX
double posX(float initPosition, float initVelocity, float time);
//posY
double posY(float initPosition, float initVelocity, float time);

//oppgave 4a
//oppgave 1d - print time
void printTime(double time);

//oppgave 1e - flight time
double flighttime(double initvelocityY);

// Ber brukeren om en vinkel
double getUserInputTheta();

//Ber brukeren om en absoluttfart
double getUserInputAbsVelocity();

// Konverterer fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double absVelocity);

//oppgave 3b og 3c
void testDeviation(double compareOperand, double toOperand, double maxError, string name);

//oppgave 4b
double getDistanceTraveled(double velocityX, double velocityY);

//oppgave 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

//oppgave 5d
void playtargetpractice();