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

const int MOD = 1e9 + 7, MX = 1024 + 5;

int N;
ll m[MX][MX];
ll ans[MX][10];
#define mxg(i) ans[i][1]
#define mig(i) ans[i][2]
#define mxgr(i) ans[i][3]
#define migr(i) ans[i][4]
#define mxgc(i) ans[i][5]
#define migc(i) ans[i][6]
int main()
{
  scanf("%d", &N);
  ans[1][1]=1;
  ans[1][2]=1;
  ans[1][3]=1;
  ans[1][4]=1;
  ans[1][5]=1;
  ans[1][6]=1;
  for (int i = 1, r, c; i <= N; i++)
  {
    scanf("%d %d", &r, &c);
    ll mx = -LL_INF, mi = LL_INF;
    ll mxr = -LL_INF, mir = LL_INF;
    ll mxc = -LL_INF, mic = LL_INF;
    for (int j = 1; j <= r; j++)
      m[j][0]=0;
    for (int k = 1; k <= c; k++)
      m[0][k]=0;

    for (int j = 1; j <= r; j++)
    {
      for (int k = 1; k <= c; k++)
      {
        scanf("%lld ", &m[j][k]);
        mx = max(m[j][k], mx);
        mi = min(m[j][k], mi);
        m[0][k]+=m[j][k];
        m[j][0]+=m[j][k];
      }
      mxr = max(m[j][0], mxr);
      mir = min(m[j][0], mir);
    }
    for (int k = 1; k <= c; k++)
    {
      mxc = max(m[0][k], mxc);
      mic = min(m[0][k], mic);
    }
    ans[i+1][1] = max(max(mxg(i) * mx, mxg(i) * mi), max(mig(i) * mx, mig(i) * mi));
    ans[i+1][2] = min(min(mxg(i) * mx, mxg(i) * mi), min(mig(i) * mx, mig(i) * mi));
    ans[i+1][3] = max(max(mxgr(i) * mxr, mxgr(i) * mir), max(migr(i) * mxr, migr(i) * mir));
    ans[i+1][4] = min(min(mxgr(i) * mxr, mxgr(i) * mir), min(migr(i) * mxr, migr(i) * mir));
    ans[i+1][5] = max(max(mxgc(i) * mxc, mxgc(i) * mic), max(migc(i) * mxc, migc(i) * mic));
    ans[i+1][6] = min(min(mxgc(i) * mxc, mxgc(i) * mic), min(migc(i) * mxc, migc(i) * mic));
  }
  printf("%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n", mxg(N+1), mig(N+1), mxgr(N+1), migr(N+1), mxgc(N+1), migc(N+1));

  return 0;
}