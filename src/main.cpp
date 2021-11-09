
#include "vex.h"

#include "Odometry.h"
#include "Constants.h"
#include "Variables.h"



using namespace vex;



// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void auton_prog(void) {
  Brain.Screen.print(Des_Pos_len);
  for(int i = 0; i < Des_Pos_len; i++ ){
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(Des_Pos[i][0]);
    Brain.Screen.print("_____");
    Brain.Screen.print(Des_Pos[i][1]);
    Brain.Screen.print("_____");
    Brain.Screen.print(Pos[1]);
    Brain.Screen.print("_____");
    Brain.Screen.print(Pos[2]);
    Brain.Screen.print("_____");
    float forwd = calc(Pos[1],Pos[2],Des_Pos[i][0],Des_Pos[i][1]);
    Brain.Screen.newLine();
    Brain.Screen.print(forwd);
    Drivetrain.driveFor(forward,forwd, inches);
    frt_lift(Des_Pos[i][2]);
    bak_lift(Des_Pos[i][3]);
    Brain.Screen.print("DONE");
    wait(5,seconds);
  }
}

void autonomous(void) {

  auton_prog();
  // Brain.Screen.print(pi);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int POGGERS;
bool Sol1state;
bool Sol2state;

void Sol1close(void){
  Sol1.set(false);
  Sol1state = false;
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("Sol1 closed"); 
  }
void Sol2close(void){
  Sol2.set(false);
  Sol2state = false;
  Controller1.Screen.setCursor(2,0);
  Controller1.Screen.print("Sol2 closed");
  Controller1.Screen.print(POGGERS); 
  }

void usercontrol(void) {
  vexcodeInit();
  // User control code here, inside the loop
  while (1) {

    Controller1.Screen.clearScreen();
    Controller1.ButtonA.released(Sol1close);
    Controller1.ButtonB.released(Sol2close);
    if (Controller1.ButtonA.pressing()){
      // Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("Sol1 open"); 
      if(Sol2state == false){POGGERS++;Sol1state = true;}
      Sol1.set(true);
      Sol1state = true;
      Controller1.Screen.print(POGGERS);
      }
      
    while (Controller1.ButtonB.pressing()){
       
      Controller1.Screen.setCursor(2,0);
      Controller1.Screen.print("Sol2 open"); 
      if(Sol2state == false){POGGERS++;Sol1state = true;}
      Sol2state = true;
      Sol2.set(true);
      Controller1.Screen.print(POGGERS);// Controller1.rumble("-.-.-");  
      }
    if (Controller1.ButtonX.pressing() && Controller1.ButtonY.pressing() == true){
      auton_prog();
    }
      

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  vexcodeInit();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Set up callbacks for autonomous and driver control periods.
  // odometry();
  
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.

  while (true) {
    wait(100, msec);
  }
}
