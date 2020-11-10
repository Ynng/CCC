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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 10000 + 5;

int T;

//quick power
ll quickpow(ll base, ll exp)
{
  ll ans = 1;
  for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
    if (exp & 1)
      ans = (ans * base) % MOD;
  return ans;
}

void solve(){
  int a1,a2,a3,k;
  scanf("%d %d %d %d", &a1, &a2, &a3, &k);
  if(a3-a2==a2-a1)
    //arithmetic sequence
    printf("%lld\n",(a1+(a2-a1)*(ll)(k-1))%MOD);
  else
    //geometric sequence
    printf("%lld\n",(a1*quickpow(a2/a1,k-1))%MOD);
}
int main()
{
  scanf("%d", &T);
  for(int i = 1; i <= T; i++)
    solve();
  return 0;
}