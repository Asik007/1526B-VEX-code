using namespace std;

#include <iostream>
#include <math.h>

// int POG = {1,2,3,4,5};
// int POGO[5] = {1,2,3,4,5};

 float POG = 0;
// char POGstr = itoa(POG);
// int std::vector POGer;
double pi = 2*acos(0.0);
// float degrad(float pog){return pog * (pi/180);}
float raddeg(float pog){return pog * (180/pi);}
float calc(int x, int y, int x1, int y1){
  float dist = sqrt((abs(x1-x))^2 + (abs(y1-y))^2);
  int rot = raddeg(atan((y1-y)/(x1-x)));
  int final_rot;
//   Brain.Screen.print(rot);
  if(x<=x1 && y>=y1 == true){final_rot = 180+rot;}
  if(x>=x1 && y>=y1 == true){final_rot = 270-rot;}
  if(x>=x1 && y<=y1 == true){final_rot = 360+rot;}
  if(x==x1 && y==y1 == true){final_rot = 0;}
  POG = final_rot;

//   Brain.Screen.print(final_rot);
  return dist;
}
float img;
int main() {
for (int i = 0; i < 100; i++){
    // cout << "how";
    // cin >> img;

    // cout << c << '\n';
    calc(cos(i)*10,sin(i)*10,0,0);
    cout << "____" << i << "____" << POG << '\n';
}  

return 0;
 }