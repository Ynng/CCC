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
const ll MOD = 998244353;
const int MX = 300000 + 5;

int N, Q;
vi G[MX];
vi etour;
int head[MX];
int psa[MX][51];
bool visited[MX];
int st[20][3*MX];
int mxdepth = 0;
//LCA lowest common ancestors


//power of ll
ll powll(ll base, ll exp)
{
  ll ans = 1;
  for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
    if (exp & 1)
      ans = (ans * base) % MOD;
  return ans;
}

void dfs(int i, int d){
  mxdepth = max(d,mxdepth);
  visited[i]=true;
  head[i]=etour.size();
  etour.push_back(d);
  // printf("%d %d", i, etour[head[i]]);
  for(int child : G[i]){
    if(visited[child])continue;
    dfs(child, d+1);
    etour.push_back(d);
    // printf("%d %d", i, etour[head[i]]);
  }
} 

//sparse table query (inclusive)
int queryMin(int l, int r){
  int k = log2(r-l+1);
  return min(st[k][l], st[k][r-(1<<k)+1]);
}

//building sparse table
void build(){
  //initializing sparse table
  int tourLen = etour.size();
  int logLen = log2(tourLen);
  //copying value for sparse table first layer
  for(int i = 0; i < tourLen; i++)
    st[0][i]=etour[i];
  //initializing sparse table
  for (int k = 1; k <= logLen; k++)
    for (int i = 0; i <= tourLen - (1 << k); i++)
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}

int main()
{
  scanf("%d", &N);

  for (int i = 1, u, v; i <= N - 1; i++)
  {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,0);
  build();

  for (int i = 1; i <= mxdepth; i++)
    psa[i][1] = (psa[i - 1][1] + i) % MOD;

  //precalculating power sums
  for (int j = 2; j <= 50; j++)
    for (int i = 1; i <= mxdepth; i++)
      psa[i][j] = ((psa[i - 1][j] + ((psa[i][j-1] - psa[i-1][j-1]) * (ll)i))%MOD+MOD)%MOD;
      // psa[i][j] = ((psa[i-1][j] + powll(i, j))%MOD+MOD)%MOD;

  scanf("%d", &Q);
  for(int i = 1, u, v, k; i <= Q; i++)
  {
    scanf("%d %d %d", &u, &v, &k);
    int l = min(head[u], head[v]);
    int r = max(head[u], head[v]);
    int dl = etour[l];
    int dr = etour[r];
    int dlca = queryMin(l, r);
    int ans = psa[dl][k] + psa[dr][k] - psa[dlca][k];
    if(dlca>1)
      ans-=psa[dlca-1][k];
    ans = ((ans%MOD)+MOD)%MOD;
    printf("%d\n", ans);
  }
  return 0;
}