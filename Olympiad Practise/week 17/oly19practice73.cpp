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

const int MOD = 1000000007, MX = 1000 + 5;

int N, W;
int P[MX], S[MX];
ll dp[MX][2];
//weird 0/1 knapsack with large weight
int main()
{
  scanf("%d %d", &N, &W);
  ms(dp, 1);
  dp[0][0] = 0;
  for(int i = 1,w,wc,v=1; i <= N; i++)
  {
    scanf("%d %d", P+i, S+i);
    w = (P[i]+S[i]);
    wc = P[i]/2+S[i];
    for(int j = MX; j >= v; j--){
      dp[j][0]=min(dp[j][0], dp[j-v][0]+w);
      dp[j][1]=min(dp[j][1], dp[j-v][0]+wc);
      dp[j][1]=min(dp[j][1], dp[j-v][1]+w);
    }
  }

  for(int i = MX-1; i >= 0; i--){
    if(dp[i][1]<=W){
      printf("%d\n", i);
      return 0;
    }
    if(dp[i][0]<=W){
      printf("%d\n", i);
      return 0;
    }
  }
  
  return 0;
}