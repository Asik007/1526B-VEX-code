/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Vex-Advik's                                      */
/*    Created:      Tue Sep 28 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// EncoderA             encoder       A, B            
// EncoderB             encoder       C, D            
// EncoderC             encoder       E, F            
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4, H   
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
///////////////////////////////////////////////////////////////////
//    Basic varaiables and function
double pi = 2*acos(0.0);
int dia = 4;
float circum = dia*pi;
float cent_dist = 7.5;

float degrad(int pog){
  return pog * (pi/180);
}
///////////////////////////////////////////////////////////////////
//Position Coordinate initialization
float Prev_Pos[4] = {};
float Pos[4] = {};
float Delta[4] = {}; 
//1 = Center
//2 = X
//3 = Y
//4 = Theta

// array of encoder values
float Encod[3] = {};
//0 = Left
//1 = Right
//2 = Back
void track(int encode){
  int tick = 0;
    if (encode == 0){
     tick = EncoderA.position(degrees);
     Brain.Screen.print("POG");
    }
    else if (encode == 1){
     tick = EncoderB.position(degrees); 
     Brain.Screen.print("POG2");
    }
    else if (encode == 2){
     tick = EncoderC.position(degrees); 
     Brain.Screen.print("POG3");
    }
  
  Encod[encode] = degrad(tick);
  // Brain.Screen.print("POGCHAMP");
  EncoderA.setPosition(0, degrees); 
    if (encode == 0){
     EncoderA.setPosition(0,degrees);
    }
    else if (encode == 1){
     EncoderB.setPosition(0,degrees); 
    }
    else if (encode == 2){
     EncoderC.setPosition(0,degrees); 
    }
  }





void getDelta(void){
  std::fill_n(Delta, 4, 0);
  float Delt_L = Encod[0];
  float Delta_R = Encod[1];
  Delta[0] = (Delt_L + Delta_R/2);
  Delta[3] = (Delt_L + Delta_R)/(2*cent_dist);
  Delta[1] = Delta[0] * cos(Delta[3]/2);
  Delta[2] = Delta[0] * sin(Delta[3]/2);
}

void Odometry(void){
  for (int i = 0; i < 4; i++) {
    Pos[i] = Prev_Pos[i] + Delta[i];
  }
  for (int i = 0; i < 4; i++) {
    Prev_Pos[i] = Pos[i];
  }
}





int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  std::string val;
  while (true){
    
    // switch (i){
    //   case 0:
    //     val = "A:";
    //     break;
    //   case 1:
    //     val = "B:";
    //     break;
    //   case 2:
    //     val = "C:";
    //     break;
    // }
      // Brain.Screen.print(val.c_str());
      track(0);
      Brain.Screen.print(Encod[0]);
      Brain.Screen.newLine();
      track(1);
      std::cout << "hello" << std::endl;
      
      Brain.Screen.print(Encod[1]);
      Brain.Screen.newLine();

      track(2);
      Brain.Screen.print(Encod[2]);
      Brain.Screen.newLine();
      getDelta();
      Odometry();
      Brain.Screen.print(Pos[0]);
      Brain.Screen.newLine();
      Brain.Screen.print(Pos[1]);
      Brain.Screen.newLine();
      Brain.Screen.print(Pos[2]);
      Brain.Screen.newLine();
      Brain.Screen.print((Pos[3])/(pi/180));
      Brain.Screen.newLine();
    wait(1, seconds);
    Brain.Screen.clearScreen(); 
    Brain.Screen.setCursor(1,1);
    // clr_encode(0);
    // clr_encode(1);
    // clr_encode(2);
    if (Brain.Screen.pressing()){
      EncoderA.setPosition(0,degrees);
      Brain.Screen.clearScreen();

    }

  }
}
