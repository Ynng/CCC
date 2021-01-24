#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define INF 0x3f3f3f3f            // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define sz(x) (int)(x).size()
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 2000 + 5;

typedef pair<int, pi> pii;
int N, x[MX], y[MX], mx[MX], dp[MX], tmp[MX];
vector<pii> vec;
int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d %d", x + i, y + i);
    for (int j = 0; j < i; j++)
    {
      int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      vec.push_back({d, {j, i}});
    }
  }

  sort(vec.begin(), vec.end());
  for (pii e : vec)
  {
    int d = e.f, u = e.s.f, v = e.s.s;
    if(d > mx[u]){mx[u] = d; tmp[u] = dp[u];}
    if(d > mx[v]){mx[v] = d; tmp[v] = dp[v];}
    dp[u] = max(dp[u], tmp[v] + 1);
    if(u != 0) dp[v] = max(dp[v], tmp[u] + 1);
  }
  printf("%d\n", dp[0]);

  return 0;
}