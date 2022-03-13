// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    9, 1, 2, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    9, 1, 2, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Lift                 motor_group   5, 6            
// Claw                 motor         7               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back_Lift            motor         8               
// Sol1                 digital_out   G               
// Sol2                 digital_out   H               
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

#include "Odometry.h"
#include "Constants.h"
#include "Variables.h"




using namespace vex;


void POG(void){
  Brain.Screen.print("POG");
};
// A global instance of competitiondgdsf
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
  for(int i = 0; i < 4; i++ ){
  Drivetrain.driveFor(forward,6, inches);
  Drivetrain.turn(right);
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



void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    if (Controller1.ButtonA.pressing()){
      Sol1.set(true);}
      else {Sol1.set(false);}
    if (Controller1.ButtonB.pressing()){
      Sol1.set(true); 
      
      
      
      
      Controller1.rumble("-.-.-");  
      }else {Sol1.set(false);};
    
    /**
 * @todo Take over the world
 * @body Humans are weak; Robots are strong. We must cleans the world of the virus that is humanity.
 */

    if (Controller1.ButtonX.pressing()){
      Back_Lift.setVelocity(100,percent);
    }
        if (Controller1.ButtonY.pressing()){
      Back_Lift.spin(reverse);
    }

    if (Controller1.ButtonY.pressing() && Controller1.ButtonX.pressing() == true){
      Back_Lift.stop();
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
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Set up callbacks for autonomous and driver control periods.
  // odometry();
  
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.

  while (true) {
    // Controller1.Screen.print(Controller1.Axis4);

    if (Controller1.ButtonLeft.pressing()){
      auton_prog();
      Brain.Screen.print(3);
    }
    wait(100, msec);
  }
}
