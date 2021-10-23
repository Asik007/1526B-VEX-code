
//Position Coordinate initialization
float Des_Pos[3][4] = {
{72,0,1,0},
{20,0,2,0},
{0,0,0,0},
};
//1 = x
//2 =y
//3 = frt_lift (0 nothing, 1 up, 2 down)
//4 = bak_lift (0 nothing, 1 up, 2 down)
float Pos[4] = {0,0,0,0};
//1 = Center (not used any where)
//2 = X
//3 = Y
//4 = Theta
//ticks need to traverse 1 in
int Left_tick = 1234;
int Right_tick = 1234;

//PID constants
double KPID[3] = {1,2,3};
double TPID[3] = {1,2,3};
double I_limit = 1234;