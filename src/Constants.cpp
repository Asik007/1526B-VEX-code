#pragma once


#include <math.h>
///////////////////////////////////////////////////////////////////
//    Basic varaiables and function
double pi = 2*acos(0.0);
int dia = 4;
float circum = dia*pi;
float cent_dist = 7.5;
///////////////////////////////////////////////////////////////////
//Position Coordinate initialization

float Des_theta = {};
float Prev_Pos[4] = {};
float Delta[4] = {}; 
//1 = Center (not used any where)
//2 = X
//3 = Y
//4 = Theta



////////////////////////////////////////////////////////////////////////////////////////
// array of encoder values
float Encod[2] = {};
//0 = Left
//1 = Right
//2 = Back

//PID constants
double PID[3];
int desiredValue = 0;
int desiredTurnValue = 0;

//dont touch (PID variables that change)
int error;
int prevError = 0;
int derivative;
int totalError;

int turnError;
int turnPrevError = 0;
int turnDerivative;
int turnTotalError;
bool resetDriveSensors = false;
bool enableDrivePID = true;
