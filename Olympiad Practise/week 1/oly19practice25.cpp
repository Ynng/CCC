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
#include <queue>
#include <unordered_map>

// #define DEBUG

typedef long long ll;
int N, M, K, Q;

ll a[5005][5005];

void psum(){
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
}

int main(int argc, const char **argv)
{
  scanf("%d %d %d", &N, &M, &K);
  int xa, ya, xb, yb;
  for (int i = 0; i < K; i++)
  {
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    a[xa][ya]++;
    a[xb + 1][yb + 1]++;
    a[xa][yb + 1]--;
    a[xb + 1][ya]--;
  }

  psum();
  psum();

  scanf("%d", &Q);

  for (int i = 0; i < Q; i++)
  {
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    printf("%lld\n", a[xb][yb] - a[xa - 1][yb] - a[xb][ya - 1] + a[xa - 1][ya - 1]);
  }

  return 0;
}