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

const int MOD = 1e9 + 7, MX = 5000 + 5;


//0/N knapsack with binary package

int N, M;
ll dp[MX];
pi trucks[MX];
ll pma[MX];
int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 1, n, w, v; i <= N; i++)
  {
    scanf("%d %d %d", &n, &w, &v);
    //binary package
    for (ll j = 1; j <= n; j *= 2)
    {
      ll val = v * j;
      ll weight = w * j;
      for (int k = MX; k >= weight; k--)
        dp[k] = max(dp[k], dp[k - weight] + val);
      n -= j;
    }
    ll val = v * (ll)n;
    ll weight = w * (ll)n;
    for (int k = MX; k >= weight; k--)
      dp[k] = max(dp[k], dp[k - weight] + val);
  }

  for (int i = 1; i <= MX; i++)
    pma[i] = max(dp[i], pma[i - 1]);

  ll mx = -INF;
  for (int i = 1, c, f; i <= M; i++)
  {
    scanf("%d %d", &c, &f);
    ll earning = pma[c] - f;
    mx = max(mx, earning);
  }
  printf("%lld", mx);
  return 0;
}