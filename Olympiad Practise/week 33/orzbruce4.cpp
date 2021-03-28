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

const int MOD = 1000000007, MX = 200000 + 5;

int N, M, K;
vector<int> G[MX];
int dist1[MX], distN[MX];

//quick power
ll quickpow(ll base, ll exp)
{
  ll ans = 1;
  for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
    if (exp & 1)
      ans = (ans * base) % MOD;
  return ans;
}

int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1, a, b; i <= M; i++)
  {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<pi> q;
  q.push({1,0});
  dist1[1]=-1;
  while(!q.empty()){
    for(int n : G[q.front().f]){
      if(dist1[n])continue;
      dist1[n] = q.front().s+1;
      q.push({n, dist1[n]});
    }
    q.pop();
  }

  q.push({N,0});
  distN[N]=-1;
  while(!q.empty()){
    for(int n : G[q.front().f]){
      if(distN[n])continue;
      distN[n] = q.front().s+1;
      q.push({n, distN[n]});
    }
    q.pop();
  }

  ll num = 0;

  for(int i = 1; i <= N; i++)
  {
    // printf("%d: %d %d\n", i, dist1[i], distN[i]);
    if(dist1[i]<=0 || distN[i] <= 0)continue;
    // printf("yes\n");
    if(dist1[i] <= K && distN[i] <= K)num++;
  }


  printf("%lld\n", quickpow(2, num));
  return 0;
}