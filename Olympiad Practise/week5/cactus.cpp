#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9 + 7, MX = 200000 + 5;

int N, M, K, mxt;
pi armour[10];
ll psa[MX];
ll totalHealth;
int main()
{
  scanf("%d %d %d", &N, &M, &K);
  totalHealth = N * 100LL;
  for (int i = 1; i <= K; i++)
  {
    scanf("%d %d", &armour[i].f, &armour[i].s);
  }
  for (int i = 1, s, l, x; i <= M; i++)
  {
    scanf("%d %d %d", &s, &l, &x);
    psa[s] += x;
    psa[s + l] -= x;
    mxt = max(s + l, mxt);
  }

  for (int i = 0; i <= mxt; i++)
  {
    if (i != 0)
      psa[i] += psa[i - 1];
    ll min = psa[i] * 100;
    for (int j = 1; j <= K; j++)
    {
      ll damage = psa[i] - armour[j].f;
      if (damage < 0)
        damage = 0;
      else
        damage *= 100 - armour[j].s;

      if (damage < min)
        min = damage;
    }
    if (totalHealth < min)
    {
      printf("Act Like A Cactus.\n");
      return 0;
    }
    totalHealth -= min;
  }
  printf("%lld.%lld%lld\n", totalHealth / 100, totalHealth % 100 / 10, totalHealth % 10);

  return 0;
}