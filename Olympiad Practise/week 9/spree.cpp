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

int N, T;
int dp[MX];
int main()
{
  scanf("%d %d", &N, &T);
  for(int i = 1; i <= N; i++)
  {
    int val, cost;
    scanf("%d %d", &val, &cost);
    for (int j = T; j >= cost; j--)
    {
      dp[j] = max(dp[j], dp[j - cost] + val);
    }
  }

  printf("%d", dp[T]);
  return 0;
}