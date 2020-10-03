#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7, MX = 100 + 5, MW=1e5+5;

//0/1 knapsack 

int N, W;
int w, v;
ll dp[MW];
int main()
{
  scanf("%d %d", &N, &W);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d %d", &w, &v);
    for (int j = W; j >= w; j--)
      dp[j] = max(dp[j], dp[j-w]+v);
  }
  
  ll mx = 0;
  for (int i = 1; i <= W; i++)
    mx = max(mx, dp[i]);
  
  printf("%lld", mx);  
  
  return 0;
}