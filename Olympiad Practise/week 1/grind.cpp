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
#define MAXN 10000005
// #define DEBUG

int N;
int a[MAXN];

int main()
{
  scanf("%d", &N);

  int range = 0;

  for (int i = 0, s, f; i < N; i++)
  {
    scanf("%d %d", &s, &f);
    a[s]++;
    a[f]--;
    if (f > range)
      range = f;
  }

  int max = 0;

  for (int i = 1; i < range; i++)
  {
    a[i] += a[i - 1];
    if (a[i] > max)
      max = a[i];
  }

  printf("%d", max);
  return 0;
}