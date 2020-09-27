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

const int MOD = 1e9+7, MX = 1000 + 5;

int N, M, K;
int cost[MX];
int val[MX];
int deals[MX][2];
ll dp[MX];

//Binary package
//DP knapsack

int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 1,a,b; i <= N; i++)
  {
    scanf("%d %d", cost+i, val+i);
    //Unlimited knapsack
    //reverse looping for unlimited
    for(int j = cost[i]; j<=K; j++){
      dp[j] = max(dp[j], dp[j-cost[i]] + val[i]);
    }
  }
  for(int i = 1, q, t, d, a; i <= M; i++)
  {
    scanf("%d %d %d %d", &q, &t, &d, &a);
    //binary package
    //limited knapsack
    for(int k = 1; k <= a; k=k*2){
      int w = k*d;
      ll v = k * (ll)q * val[t];
      for(int j=K; j>=w; j--){
        dp[j]=max(dp[j], dp[j-w] + v);
      }
      a-=k;
    }
    int w = a*d;
    ll v = a * (ll)q * val[t];
    for(int j=K; j>=w; j--){
      dp[j]=max(dp[j], dp[j-w] + v);
    }
  }

  printf("%lld\n", dp[K]);

  
  
  return 0;
}