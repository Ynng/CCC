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
int T, X, Y;

int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    scanf("%d %d", &X, &Y);
    int temp;
    int bx[40], by[40];
    int counter;
    memset(bx, 0, sizeof(bx));
    memset(by, 0, sizeof(by));

    temp = X;
    for(int i = 0; temp>0; i++){
      bx[i] = temp%2;
      temp = temp/2;
    }

    temp = Y;
    for(int i = 0; temp>0; i++){
      by[i] = temp%2;
      temp = temp/2;
    }
    
    
  }
}