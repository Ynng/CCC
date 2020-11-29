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

const int MOD = 1000000007, MX = 200 + 5;

//interval dp

int N, L;
int x[MX], T[MX];
ll dp[MX][MX][MX][2];
int ans;

int main()
{
  ms(dp, 0x3f);

  scanf("%d %d", &N, &L);
  for (int i = 1; i <= N; i++)
    scanf("%d", x + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", T + i);

  dp[N+1][0][0][0] = dp[N+1][0][0][1] = 0;
  x[N+1] = L;
  for (int l = N+1; l > 0; l--){
    for(int r = 0; r < l; r++){
      for(int k = 0; k<=N+1-(l-r); k++){
        ll time = min(dp[l][r][k][0] + x[l] - x[l-1], dp[l][r][k][1] + L + x[r] - x[l-1]);
        int d = (time <= T[l-1]) ? 1:0;
        dp[l-1][r][k+d][0] = min(dp[l-1][r][k+d][0], time);
        time = min(dp[l][r][k][0] + L + x[r+1]-x[l], dp[l][r][k][1] + x[r+1] -x[r]);
        d = (time <= T[r+1])?1:0;
        dp[l][r+1][k+d][1] = min(dp[l][r+1][k+d][1], time);
        
      }
    }
  }
  for (int l = N+1; l > 0; l--){
    for(int r = 0; r < l; r++){
      for(int k = 0; k<=N+1-(l-r); k++){
        if(dp[l][r][k][0] < INF || dp[l][r][k][1] < INF) ans = max(ans, k);
      }
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}