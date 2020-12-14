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

const int MOD = 1000000007, MX = 100000 + 5;

int N, K, F, dis[MX], dep[MX], mx;
vector<int> adj[MX];
bool gym[MX];

void dfs(int u, int pa){
  dis[u]=0;
  for(int v: adj[u]){
    if(v!=pa){
      dep[v]=dep[u]+1;
      dfs(v,u);
      if(gym[v]){
        dis[u]+=dis[v]+1;
        gym[u]=true;
      }
    }
  }
  if(gym[u]) mx = max(mx, dep[u]);
}

int main()
{
  scanf("%d %d %d", &N, &K, &F);
  for (int i = 1, x; i <= K; i++)
  {
    scanf("%d", &x);
    gym[x] = true;
  }

  for (int i = 1, u, v; i < N; i++)
  {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1,0);
  int without_dragon = 2*dis[1] - mx;
  gym[F] = true;
  dfs(1,0);
  int with_dragon = dis[1];

  printf("%d\n", min(with_dragon, without_dragon));

  return 0;
}