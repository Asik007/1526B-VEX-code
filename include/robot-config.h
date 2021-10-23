using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor_group Lift;
extern motor Claw;
extern encoder Left;
extern encoder Right;
extern motor Back_Lift;
extern digital_out Sol1;
extern digital_out Sol2;
extern encoder Back;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );