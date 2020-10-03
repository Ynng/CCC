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

const int MOD = 1e9+7, MX = 100*1000;

//0/1 knapsack with large weight

int N, W;
ll dp[MX+5];
int answer;
int main()
{
  scanf("%d %d", &N, &W);
  ms(dp, 1);
  dp[0] = 0;
  for(int i = 1,w,v; i <= N; i++)
  {
    scanf("%d %d", &w, &v);
    for(int j = MX; j >= v; j--){
      dp[j]=min(dp[j], dp[j-v]+w);
    }
  }

  for(int i = MX; i >= 0; i--){
    if(dp[i]<=W){
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}