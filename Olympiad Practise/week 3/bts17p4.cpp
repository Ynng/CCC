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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9 + 7, MAXN = 1e5 + 5;

int N, M, J, mx = 0;
set<pi> mud;
pi wet[MAXN];
bool a[MAXN];

int main()
{
  scanf("%d %d %d", &N, &M, &J);
  memset(a, 1, sizeof(a));

  for (int i = 1, p, t; i <= M; i++)
  {
    scanf("%d %d", &p, &t);
    wet[i] = {t, p};
    a[p] = false;
  }
  sort(wet + 1, wet + M + 1);
  a[N + 1] = false;
  for (int i = 1, cur = 0, l = 0; i <= N + 1; i++)
  {
    if (a[i])
    {
      if (cur == 0)
        l = i;
      cur++;
    }
    else
    {
      if (l > 0 && cur != 0)
        mud.insert({l, i - 1});
      cur = 0;
    }
    if (cur > mx)
      mx = cur;
  }

  if (mx >= J)
  {
    printf("-1");
    return 0;
  }

  for (int i = M, l, r, cur; i >= 1; i--)
  {
    if (mud.size() == 0)
    {
      mud.insert({wet[i].s, wet[i].s});
      cur = 1;
    }
    else
    {
      set<pi>::iterator it = mud.upper_bound({wet[i].s, MAXN});

      l = r = wet[i].s;
      if (it != mud.end())
      {
        if ((*it).f == 1 + wet[i].s)
        {
          r = (*it).s;
          mud.erase(it);
          it = mud.upper_bound({wet[i].s, MAXN});
        }
      }
      if (it != mud.begin() && mud.size() > 0)
      {
        it--;
        if ((*it).s == wet[i].s - 1)
        {
          l = (*it).f;
          mud.erase(it);
        }
      }
      mud.insert({l, r});
      cur = r - l + 1;
    }

    if (cur >= J)
    {
      printf("%d", wet[i].f);
      return 0;
    }
  }

  printf("0");

  return 0;
}