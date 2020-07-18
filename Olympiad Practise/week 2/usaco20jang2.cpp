#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define ins insert

#define MOD 1000000007
#define MAXN 5005
const int MV = 1e6 + 5;

int N, Q, cnt[MV * 2], a[MAXN];
ll psa[MAXN][MAXN];
int main()
{
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i <= N - 1; i++)
  {
    for (int k = i + 1, val; k <= N; k++)
    {
      val = MV - (a[i] + a[k]);
      if (val >= 0 && val < 2 * MV)
        psa[i][k] += cnt[val];
      cnt[a[k] + MV]++;
    }
    for (int k = i + 1; k <= N; k++)
    {
      cnt[a[k] + MV]--;
    }
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    }
  }

  for (int i = 0, a, b; i < Q; i++)
  {
    scanf("%d %d", &a, &b);
    printf("%lld\n", psa[b][b] - psa[a - 1][b] - psa[b][a - 1] + psa[a-1][a-1]);
  }

  return 0;
}