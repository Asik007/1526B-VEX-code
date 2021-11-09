#include <vex.h>
#include "Constants.h"
#include "Variables.h"
using namespace vex;


//multiuse functions


float degrad(float pog){return pog * (pi/180);}
float raddeg(float pog){return pog * (180/pi);}
float calc(int x, int y, int x1, int y1){
  float dist = sqrt((abs(x1-x))^2 + (abs(y1-y))^2);
  float rot = raddeg(atan((y1-y)/(x1-x)));
  Brain.Screen.print(rot);
  if(x<=x1 && y>=y1 == true){rot = 180+raddeg(atan((y1-y)/(x1-x)));Brain.Screen.print("POG");}
  if(x>=x1 && y>=y1 == true){rot = 270-raddeg(atan((y1-y)/(x1-x)));Brain.Screen.print("POG2");}
  if(x>=x1 && y<=y1 == true){rot = 360+raddeg(atan((y1-y)/(x1-x)));Brain.Screen.print("POG3");}
  if(x==x1 && y==y1 == true){rot = 0;}
  Brain.Screen.print(rot);
  Drivetrain.turnFor(rot, rotationUnits::deg);
  return dist;
}


void track(void){
  Encod[0] = Left.rotation(rotationUnits::raw)/Left_tick; 
  Encod[1] = Right.rotation(rotationUnits::raw)/Right_tick; 
  Brain.Screen.print("POGCHAMP");
  Left.setPosition(0,rotationUnits::raw);
  Right.setPosition(0,rotationUnits::raw); 
}

void getDelta(void){
  std::fill_n(Delta, 4, 0);
  Delta[0] = (Encod[0] + Encod[1]/2);
  Delta[3] = (Encod[0] + Encod[1])/(2*cent_dist);
  Delta[1] = Delta[0] * cos(Delta[3]/2);
  Delta[2] = Delta[0] * sin(Delta[3]/2);
}

void odometry(void){
  Brain.Screen.clearScreen();
  track();
  getDelta();
  for (int i = 0; i < 4; i++) {
    Pos[i] = Prev_Pos[i] + Delta[i];
  }
  for (int i = 0; i < 4; i++) {
    Prev_Pos[i] = Pos[i];
  }
}

void frt_lift(int POO){
  switch(POO){
    case 1:
      //TODO; write the solenoids into this
      Brain.Screen.newLine();
      Brain.Screen.print(POO);
      Sol1.set(true);
      wait(.05,seconds);
      Brain.Screen.print("POGGER");
      Lift.rotateFor(fwd, 180, degrees);
      break;
      
    case 2:
      Brain.Screen.newLine();
      Brain.Screen.print(POO);
      Sol1.set(false);
      wait(.05,seconds);
      Brain.Screen.print("POGGER");
      Lift.rotateFor(reverse, 180, degrees);
      break;

    default:
      Brain.Screen.newLine();
      Brain.Screen.print(POO);    
      break;
  }
  
}

void bak_lift(int POO){
  switch(POO){
    case 1:
      //TODO; write the solenoids into this
      Brain.Screen.newLine();
      Brain.Screen.print(POO);
      Sol1.set(true);
      wait(.05,seconds);
      Brain.Screen.print("POGGER");
      break;
      
    case 2:
      Brain.Screen.newLine();
      Brain.Screen.print(POO);
      Sol1.set(false);
      wait(.05,seconds);
      Brain.Screen.print("POGGER");
      break;

    default:
      Brain.Screen.newLine();
      Brain.Screen.print(POO);    
      break;
  }
}
