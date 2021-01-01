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
#define MAXN 100005
// #define DEBUG

int N, T;
ll A[MAXN], B[MAXN], C[MAXN];

void psum(ll *a)
{
  for (int i = 1; i <= T + 1; i++)
    a[i] += a[i - 1];
}

int main()
{
  scanf("%d %d", &N, &T);
  for (ll i = 0, l, r, a, b, c; i < N; i++)
  {
    scanf("%lld %lld %lld %lld %lld", &l, &r, &a, &b, &c);
    C[l] += c;
    C[r + 1] -= c;
    if (r - l >= 1)
    {
      B[l + 1] += b + a;
      B[r + 1] -= b + a;
      C[r + 1] -= a * (r - l) * (r - l) + b * (r - l);
      A[l + 2] += a * 2;
      A[r + 1] -= a * 2;
      B[r + 1] -= 2 * a * (r - l - 1);
    }
  }

  for (int i = 1; i <= T + 1; i++)
    A[i] += A[i - 1];
  for (int i = 1; i <= T + 1; i++)
    B[i] += B[i - 1] + A[i];
  for (int i = 1; i <= T + 1; i++)
    C[i] += C[i - 1] + B[i];

  for (int i = 1; i <= T; i++)
    printf("%lld ", C[i]);

  return 0;
}