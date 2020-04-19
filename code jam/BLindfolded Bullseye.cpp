#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <fstream>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
int T, A, B;
char input[10];
int main()
{
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  scanf("%d %d %d", &T, &A, &B);
  for (int t = 1; t <= T; t++)
  {
    bool axis = false;
    int direction = 1;
    double lx = 0;
    double ly = 0;
    int cx, cy;
    cx = cy = 0;
    double diffx = 1e9;
    double diffy = 1e9;
    int last = 2;
    int hitcount = 0;
    int misscount = 0;
    //find y
    while(diffy>0.5){
      if(cx || cy)break;
      printf("%d %d\n", (int)lx, (int)ly);
      memset(input, 0, sizeof(input));
      scanf("%s", input);
      if(strcmp(input, "CENTER")==0){
        cx = lx;
        cy = ly;
        last = 1;
      }else if(strcmp(input, "HIT")==0){
        hitcount++;
        misscount = 0;
        if(last == 3)direction *= -1;
        last = 2;
      }else if(strcmp(input, "MISS")==0){
        misscount++;
        if(last == 2)
          direction *= -1;
        last = 3;
      }

      if(misscount>5){
        misscount = 0;
        if(lx > 1e9/3)
          lx = -1e9/2;
        else lx=1e9/2;
        int last = 2;
        ly = 0;
        double diffy = 1e9;
        continue;
      }

      if(axis){
        diffx/=2;
        lx+=diffx*direction;
      }
      else {
        diffy/=2;
        ly+=diffy*direction;
      }
    }

    double firstx = lx;
    double firsty = ly;
    diffx = 1e9;
    diffy = 1e9;
    hitcount = 0;
    misscount = 0;
    last = 2;
    axis = false;
    direction = 1;
    while(diffy>0.5){
      if(cx || cy)break;
      printf("%d %d\n", (int)lx, (int)ly);
      memset(input, 0, sizeof(input));
      scanf("%s", input);
      if(strcmp(input, "CENTER")==0){
        cx = lx;
        cy = ly;
        last = 1;
      }else if(strcmp(input, "HIT")==0){
        hitcount++;
        misscount = 0;
        if(last == 3)direction *= -1;
        last = 2;
      }else if(strcmp(input, "MISS")==0){
        misscount++;
        if(last == 2)
          direction *= -1;
        last = 3;
      }

      if(misscount>5){
        misscount = 0;
        diffy = 1e9;
        ly = firsty;
        direction = -1;
        continue;
      }

      if(axis){
        diffx/=2;
        lx+=diffx*direction;
      }
      else {
        diffy/=2;
        ly+=diffy*direction;
      }
    }

    double secondy = ly;
    ly = firsty;
    lx = firstx;
    int midy = (firsty+secondy)/2;
    diffx = 1e9;
    diffy = 1e9;
    hitcount = 0;
    misscount = 0;
    last = 2;
    axis = true;
    direction = 1;

    while(diffy>0.5){
      if(cx || cy)break;
      printf("%d %d\n", (int)lx, (int)ly);
      memset(input, 0, sizeof(input));
      scanf("%s", input);
      if(strcmp(input, "CENTER")==0){
        cx = lx;
        cy = ly;
        last = 1;
      }else if(strcmp(input, "HIT")==0){
        hitcount++;
        if(last == 3)direction *= -1;
        last = 2;
      }else if(strcmp(input, "MISS")==0){
        misscount++;
        if(last == 2)
          direction *= -1;
        last = 3;
      }

      if(axis){
        diffx/=2;
        lx+=diffx*direction;
      }
      else {
        diffy/=2;
        ly+=diffy*direction;
      }
    }

    double secondx = lx;
    int midx = (firstx + secondx)/2;
    axis = true;
    direction = 1;
    int diff = 1;
    int counter = 0;
    while(!(cx||cy)){
      printf("%d %d", midx, midy);
      memset(input, 0, sizeof(input));
      scanf("%s", input);
      if(strcmp(input, "CENTER")==0){
        break;
      }
      counter++;
      switch(counter%4){
        case 1:
          axis = false;
          direction = 1;
        break;
        case 2:
          axis = true;
          direction = -1;
          diff++;
        break;
        case 3:
          axis = false;
          direction = -1;
        break;
        case 0:
          axis = true;
          direction = 1;
          diff++;
        break;
      }

      if(axis){
        lx+=diffx*direction;
      }
      else {
        ly+=diffy*direction;
      }
    }
  }
  
}