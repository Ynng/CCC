#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define sz(x) (int)(x).size()
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 1000 + 5, MXN = 1000000+5;

int N, M, R;

pair<pi,int> I[MX];

int dp[MXN];

ll bit[MXN];

//binary indexed tree maximum

ll query(int r)
{
  ll mx = 0;
  while (r > 0)
  {
    mx = max(bit[r], mx);
    r ^= (r & -r);
  }
  return mx;
}

void update(ll val, int index)
{
  while (index < MXN)
  {
    bit[index] = max(val, bit[index]);
    index += (index & -index);
  }
}


int main()
{
  scanf("%d %d %d", &N, &M, &R);
  for(int i = 0,s,e,v; i < M; i++)
  {
    scanf("%d %d %d", &s, &e, &v);
    I[i]={{s,e},v};
  }
  sort(I, I+M);

  ll ans = 0;

  for (int i = 0; i < M; i++)
  {
    int s = I[i].first.first;
    int e = I[i].first.second;
    int v = I[i].second;
    ll val = query(s) + v;
    ans = max(val,ans);
    update(val,e+R);
  }
  
  printf("%lld", ans);

  return 0;
}