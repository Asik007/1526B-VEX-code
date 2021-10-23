#pragma once

 extern double pi;
 extern int dia;
 extern float circum;
 extern float cent_dist;
 extern float Des_theta;
 extern float Prev_Pos[4];
 extern float Delta[4];
 extern float Encod[3];
 extern float PID[3]; //uint32_t = list
 extern int desiredValue;
 extern int desiredTurnValue;
 extern int error;
 extern int prevError;
 extern int derivative;
 extern int totalError;
 extern int turnError;
 extern int turnPrevError;
 extern int turnDerivative;
 extern int turnTotalError;
 extern bool resetDriveSensors;
 extern bool enableDrivePID;
