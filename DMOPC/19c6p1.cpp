#include <iostream>
#include <math.h>
// #define DEBUG
int main(){
  int x1, y1, x2, y2, x3, y3, x4, y4;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
  double m1, m2;
  m1 = ((y2-y1)*1.0)/(x2-x1);
  m2 = ((y4-y3)*1.0)/(x4-x3);
  #ifdef DEBUG
    printf("m1: %f, m2: %f\n", m1, m2);
  #endif
  double temp;
  
  if(m1==m2){
    //parallel, extend from x1 to try to reach x3
    temp = (x3 - x1) * m1 + y1;
    #ifdef DEBUG
    printf("y3: %d, temp: %f\n", y3, temp);
    #endif
    if(temp == y3 || (isnan(temp) && x1 == x3)){
      //coincident
      printf("coincident");
    }else{
      //coincident
      printf("parallel");
    }
  }else{
    double cx, cy;
    if(isinf(m1)){
      cx = x1;
      cy = (cx - x3) * m2 + y3;

    }else if(isinf(m2)){
      cx = x3;
      cy = (cx - x1) * m1 + y1;
    }else{
      cx = (m1*x1 - m2*x3 + y3 - y1)/(m1-m2);
      cy = (cx - x1) * m1 + y1;
    }
    printf("%.6f %.6f", cx, cy);
  }
  return 0;
}