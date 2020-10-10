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

const int MOD = 1e9 + 7, MX = 6000 + 5;
int N, Q;
vector<pi> in[MX];
vector<pi> etour;
pi st[15][2*MX];
ll dis[MX];
int head[MX];
bool visited[MX];

void dfs(int i, int d, ll dist){
  visited[i]=true;
  dis[i]=dist;
  etour.push_back({d, i});
  head[i]=etour.size();
  for(pi child : in[i]){
    if(visited[child.f])continue;
    dfs(child.f, d+1, dist+child.s);
    etour.push_back({d, i});
  }
} 

//sparse table query (inclusive)
//pair sparse table
pi queryMin(int l, int r){
  int k = log2(r-l+1);
  return min(st[k][l], st[k][r-(1<<k)+1]);
}

//LCA lowest common ancestors
//Euler tour + range minimum query
int main()
{
  scanf("%d", &N);

  for (int i = 1, a, b, w; i <= N - 1; i++)
  {
    scanf("%d %d %d", &a, &b, &w);
    in[a].push_back({b,w});
    in[b].push_back({a,w});
  }
  dfs(0, 1, 0);

  //initializing sparse table
  int tourLen = etour.size();
  int logLen = log2(tourLen);
  for(int i = 1; i <= tourLen; i++)
    st[0][i]=etour[i-1];
  for (int k = 1; k <= logLen; k++)
    for (int i = 1; i <= tourLen - (1 << k) + 1; i++)
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);


  //handling queries
  scanf("%d", &Q);
  for(int i = 1, u, v; i <= Q; i++)
  {
    scanf("%d %d", &u, &v);
    int l = min(head[u], head[v]);
    int r = max(head[u], head[v]);
    int lca = queryMin(l, r).s;
    printf("%lld\n", dis[u] + dis[v] - 2 * dis[lca]);
  }

  return 0;
}