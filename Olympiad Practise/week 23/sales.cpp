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

const int MOD = 1000000007, MX = 3e4 + 5;

int B, N, D, dp[55], w[MX], v[MX];
set<pi, greater<pi>> card[55];
int main()
{
  scanf("%d %d %d", &B, &N, &D);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d %d", w + i, v + i);
    card[w[i]].insert({v[i], i});
  }
  
  for(int i = 1,a,b,x,y; i <= D; i++)
  {
    scanf("%d %d %d %d", &a, &b, &x, &y);
    card[w[a]].erase({v[a], a});
    w[a] = b;
    card[w[a]].insert({v[a], a});
    memset(dp, 0, sizeof(dp));
    for(int j = 1; j <= B; j++)
    {
      int cnt = 0;
      for(const pi& e: card[j]){
        if(cnt >= B/j)break; 
        if(e.s >= x && e.s <=y){
          cnt++;
          for (int k = B; k >= j; k--)
            dp[k] = max(dp[k], dp[k-j] + e.f);
          
        }
      }
    }

    printf("%d\n", dp[B]);
  }

  return 0;
}