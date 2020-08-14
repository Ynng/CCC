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

const int MOD = 1e9 + 7, MX = 1e6 + 5;

int N, K;
int c[MX];
deque<int> dq;
int di;
ll ans;
int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 1, temp; i <= N; i++)
  {
    scanf("%d", &temp);
    dq.push_back(temp);
    if (c[temp] == 0)
      di++;
    c[temp]++;
    while (di >= K && !dq.empty())
    {
      c[dq.front()]--;
      if (c[dq.front()] == 0)
        di--;
      dq.pop_front();
    }
    ans += dq.size();
  }

  ans = ((ll)N + (ll)N * N) / 2 - ans;
  printf("%lld\n", ans);

  return 0;
}