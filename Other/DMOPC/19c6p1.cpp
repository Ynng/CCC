#include <iostream>
#include <math.h>
// #define DEBUG
#define M1 (((y2-y1)*1.0)/(x2-x1))
#define M2 (((y4-y3)*1.0)/(x4-x3))
#define TEMP ((x3 - x1) * M1 + y1)
int main(){
  int x1, y1, x2, y2, x3, y3, x4, y4;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
  double m1, m2;
  m1 = M1;
  m2 = M2;
  #ifdef DEBUG
    printf("M1: %f, M2: %f\n", M1, M2);
  #endif
  
  if(M1==M2){
    //parallel, extend from x1 to try to reach x3
    #ifdef DEBUG
    printf("y3: %d, temp: %f\n", y3, TEMP);
    #endif
    if(TEMP == y3 || (isinf(M1) && x1 == x3)){
      //coincident
      printf("coincident");
    }else{
      //coincident
      printf("parallel");
    }
  }else{
    double cx, cy;
    if(isinf(M1)){
      cx = x1;
      cy = (x1 - x3) * M2 + y3;

    }else if(isinf(M2)){
      cx = x3;
      cy = (x3 - x1) * M1 + y1;
    }else{
      cx = (M1*x1 - M2*x3 + y3 - y1)/(M1-M2);
      cy = ((M1*x1 - M2*x3 + y3 - y1)/(M1-M2) - x1) * M1 + y1;
    }
    printf("%.8f %.8f", cx, cy);
  }
  return 0;
}