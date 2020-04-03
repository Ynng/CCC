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

int T, N;
int m[105][105];
int temp;
int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    memset(m, 0, sizeof(m[0][0]) * 105 * 105);
    scanf("%d", &N);
    int k, r, c;
    k = r = c = 0;
    for (int i = 1; i <= N; i++)
    {
      bool badRow = false;
      memset(m[0], 0, sizeof(m[0][0]) * 105);
      for (int j = 1; j <= N; j++)
      {
        scanf("%d", &temp);
        if(i==j)k+=temp;
        if(m[0][temp] && !badRow){
          badRow = true;
          r++;
        }
        m[0][temp] = true;
        if(m[temp][j] && !m[j][0]){
          m[j][0] = true;
          c++;
        }
        m[temp][j] = true;
        

        // printf("%d %d %d\n", k, r, c);
        // for (int o = 0; o <= N; o++)
        // {
        //   for (int l = 0; l <= N; l++)
        //   {
        //     printf("%d", m[o][l]);
        //   }
        //   printf("\n");
        // }
        // printf("\n");
        

      }
    }
    printf("Case #%d: %d %d %d\n", t, k, r, c);
  }
  return 0;
}