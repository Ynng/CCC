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

const int MOD = 1e9 + 7, MX = 500000 + 5;

int N;
int S[MX];
ll psa[MX][2];//seconds
int main()
{
  scanf("%d", & N);
  for(int i = 1; i <= N; i++)
    scanf("%d", S+i);
  for(int i = 2, mx = S[1]; i <= N; i++){
    if(S[i]>mx)mx=S[i];
    psa[i][0] = mx - S[i] + psa[i-1][0];
  }
  for(int i = N-1, mx = S[N]; i >= 1; i--){
    if(S[i]>mx)mx=S[i];
    psa[i][1] = (ll)mx - S[i] + psa[i+1][1];
  }

  ll mincost = psa[1][0]+psa[1][1];
  for(int i = 2; i <= N; i++)
    mincost = min(psa[i][0]+psa[i][1], mincost);
  printf("%lld", mincost);
  return 0;
}