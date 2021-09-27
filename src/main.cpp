#include "robot.h"
#include "vmath.h"
#include "vmap.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// Arm                  motor_group   5, 6            
// Claw                 motor         7               
// Intake               motor         8               
// Left                 encoder       A, B            
// Right                encoder       C, D            
// Back                 encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
// also define your global variables here
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
double pi = 2*acos(0.0);
//IDK the classes of objects for c++ so there a bunch of errors from confounding classes
int wheel_dia = 4;
float circum = wheel_dia*pi;
float cent_dist = 7.5;
int radius = 5;

int degrad(int pog){
  float rad;
  rad = pog * (pi/180);
  return rad;
}

float distdeg(float dist_turn, float cent_radius){
  return (dist_turn/(radius*2*pi))/(pi/180);
}

float dist(int x){  
  return(x/360)*circum;
}

float percentout(float mot, float encode){
  return (mot - encode)/encode;
}

float odometry(void){
  /*------------
  Has to be called every 10ms
  that way we can accurately find delta x and delta y
  idk if we want to add rotation comparison i.e. we compare delta left to delta right and find the rotation
  if we do add it it should be:
    float center_dist = (some number);
    int L_degrees = Left.position(degrees);
    int R_degrees = Right.position(degrees);
    float Turn_rad = degrad((L_degrees - R_degrees);
    Left.setPosition(0, degrees);
    Right.setPosition(0, degrees);  
    return (Turn)
    
    
  */
  float L_dist = dist(Left.position(degrees));
  //float Lmot_dist = dist(leftMotorA.position(degrees));
  float R_dist = dist(Left.position(degrees));

  float B_dist = dist(Back.position(degrees));
  //float Rmot_dist = dist(Left.position(degrees));
  // Idk how to address the motor when they are in a drive train

  float x = (L_dist+R_dist)/2;
  float diff = fabs(L_dist-R_dist)/2;
  float dist_turn = (distdeg(diff, 7.5))*wheel_dia;
  //this should compensate for turning because it takes the average 
  //and the encoders would spin in opposite directions when turning
  //idk how to take absval
  float y = B_dist - dist_turn;
  Left.setPosition(0, degrees);
  Right.setPosition(0, degrees);
  Back.setPosition(0, degrees);

  return x, y;
driveforT(fwd, 10, inches, 500 );

}
//I just realized that this(the one above) only works if we work on a cartesian grid
//so we have to some how detect when we turn and how much we turned then convert
//those radial coordinates to cartesian somehow 
void coordinate(void){
  //function to convert distance to  coordinate system
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Left.setPosition(0, degrees);
  Right.setPosition(0, degrees);
  Back.setPosition(0, degrees);



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

void autonomous(void) {
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
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  Brain.Screen.print(odometry());

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.

  if (true) {
    Brain.Screen.drawImageFromFile("pog.png",20,20);
    
  }
}
