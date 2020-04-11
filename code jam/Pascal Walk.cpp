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
int T, N;

int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    scanf("%d", &N);
    printf("Case #%d:\n", t);
    int zs = 0;
    int pro = N;
    int pow = 30;
    int bi[40];

    for(int i = 0; pro>0; i++){
      if(pro%2 == 0)zs++;
      pro = pro/2;
    }
    pro = N;
    // pro = pro-2*zs;
    zs = 0;
    int temp = pro;
    // printf("zs:%d, temp: %d\n", zs, temp);
    int digits = -1;
    int counter = 0;
    for(int i = 0; temp>0; i++){
      bi[i] = temp%2;
      // printf("bi[%d] = %d\n",i, temp%2);

      counter++;
      if(temp%2 == 0){
        zs++;
      }else{
        digits = i;
      }
      temp = temp/2;
    }
    int diff = N - (zs + pro);
    // printf("digits:%d, pro: %d, diff: %d\n", digits, pro, diff);
    bool l2r = true;
    for (int i = 0; i <= digits; i++)
    {
      if(bi[i]){
        for (int j = 1; j <= i+1; j++)
        {
          printf("%d %d\n", i+1, l2r? j : i+2-j);
        }
        l2r=!l2r;
      }else{
        printf("%d %d\n", i+1, l2r? 1 : i+1);
      }
    }
    while(diff>0){
        digits++;
        diff--;
        printf("%d %d\n", digits+1, l2r? 1 : digits+1);
    }
  }
}