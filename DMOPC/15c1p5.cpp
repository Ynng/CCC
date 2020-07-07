#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAXN 255
// #define DEBUG

int N, W, H;
int f[MAXN][MAXN];
int main()
{
  scanf("%d %d %d", &W, &H, &N);
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1, s; j <= W; j++)
    {
      scanf("%d", &s);
      f[i][j] = s + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    }
  }

  int w = 1, h = N;

  while(h>H){
    w++;
    h = N/w;
  }

  int max = 0;
  while(w <= W && h >= 1){
    for (int i = h; i <= H; i++)
    {
      for (int j = w, sum; j <= W; j++)
      {
        sum = f[i][j] - f[i-h][j] - f[i][j-w] + f[i-h][j-w];
        if (sum > max)
          max = sum;
      }
    }
    w++;
    h = N/w;
  }

  printf("%d", max);
  return 0;
}