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

const int MOD = 1000000007, MX = 10000 + 5;

ll N, M, K;
ll a,b;
unordered_map<ll, bool> row, col;
int main()
{
  scanf("%lld %lld %lld", &N, &M, &K);
  for (int i = 1; i <= K; i++)
  {
    scanf("%lld %lld", &a, &b);
    row[a] ^= 1;
    col[b] ^= 1;
  }
  vl vr, vc;

  for (auto e : row)
    if (e.second)
      vr.pb(e.first);
  for (auto e : col)
    if (e.second)
      vc.pb(e.first);

  int ans = max(vr.size(), vc.size()), sz = min(vr.size(), vc.size());
  printf("%d\n", ans);

  for (int i = 0; i < sz; i++)
    printf("%lld %lld\n", vr[i], vc[i]);

  for (size_t i = sz; i < vr.size(); i++)
    printf("%lld %d\n", vr[i], 1);

  for (size_t i = sz; i < vc.size(); i++)
    printf("%d %lld\n", 1, vc[i]);
  return 0;
}