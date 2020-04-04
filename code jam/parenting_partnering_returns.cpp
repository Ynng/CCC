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
#define ET s[i].e
#define ST s[i].s

struct Activity{
  int s;
  int e;
  int i;
  char p;//Person
};

int T, N;
Activity s[1005];
int iS, iE;

int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    memset(s, 0, sizeof(s));

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
      scanf("%d %d", &iS, &iE);
      s[i] = {iS, iE, i};
    }
    sort(s, s+N, [](const Activity &left, const Activity &right) {
      return left.s < right.s;
    });

    printf("Case #%d: ", t);
    int c, j;
    c = j = 0;
    bool bad = false;
    for (int i = 0; i < N; i++)
    {
      if(ST >= c){
        c = ET;
        s[i].p =  'C';
      }else if(ST >= j){
        j = ET;
        s[i].p = 'J';
      }else{
        bad = true;
        break;
      }
    }
    if(bad){
      printf("IMPOSSIBLE");
    }
    else{
      sort(s, s+N, [](const Activity &left, const Activity &right) {
        return left.i < right.i;
      });
      for (int i = 0; i < N; i++)
      {
        printf("%c", s[i].p);
      }
    }
    printf("\n"); 
  }
}