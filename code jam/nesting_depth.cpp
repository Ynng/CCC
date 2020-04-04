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

#define DEBUG
#define VALUE (str[i] - '0')


int T;
int S;
char str[105];
// int p[105];

int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    memset(str, 0, sizeof str);
    scanf("%s", str);
    int v = 0;
    int len = strlen(str);
    int p;
    printf("Case #%d: ", t);
    for (int i = 0; i < len; i++)
    {
      p = VALUE - v;
      while(p!=0){
        if(p>0){
          printf("(");
          p--;
        }else{
          printf(")");
          p++;
        }
      }
      v = VALUE;
      printf("%d", VALUE);
    }
    p = 0 - v;
    while(p!=0){
      if(p>0){
        printf("(");
        p--;
      }else{
        printf(")");
        p++;
      }
    }
    printf("\n");
  }
}