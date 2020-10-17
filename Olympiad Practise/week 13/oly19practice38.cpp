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
ll psa[MX][50];
bool visited[MX];
int st[19][2*MX];

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
  visited[i]=true;
  head[i]=etour.size();
  etour.push_back(d);
  printf("%d %d", i, etour[head[i]]);
  for(int child : G[i]){
    if(visited[child])continue;
    dfs(child, d+1);
    etour.push_back(d);
    printf("%d %d", i, etour[head[i]]);
  }
} 

//sparse table query (inclusive)
int queryMin(int l, int r){
  int k = log2(r-l+1);
  return min(st[k][l], st[k][r-(1<<k)+1]);
}

int main()
{
  scanf("%d", &N);
  for (int j = 1; j <= 50; j++)
  {
    if (j == 1)
    {
      for (int i = 1; i <= MX - 5; i++)
        psa[i][j] = (psa[i - 1][j] + i) % MOD;
      continue;
    }
    for (int i = 1; i <= MX - 5; i++)
    {
      psa[i][j] = (psa[i - 1][j] + (((psa[i][j-1] - psa[i-1][j-1]) * i))%MOD)%MOD;
      // psa[i][j] = ((psa[i-1][j] + powll(i, j))+MOD)%MOD;
      while(psa[i][j]<0)psa[i][j]+=MOD;
    }
  }

  for (int i = 1, u, v; i <= N - 1; i++)
  {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,1);

  //initializing sparse table
  int tourLen = etour.size();
  int logLen = log2(tourLen);
  for(int i = 1; i <= tourLen; i++)
    st[0][i]=etour[i-1];
  for (int k = 1; k <= logLen; k++)
    for (int i = 1; i <= tourLen - (1 << k) + 1; i++)
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);

  scanf("%d", &Q);
  for(int i = 1, u, v, k; i <= Q; i++)
  {
    scanf("%d %d %d", &u, &v, &k);
    int l = min(head[u], head[v]);
    int r = max(head[u], head[v]);
    // printf("%d", l);

    printf("\n%d %d\n", etour[r]-1, k);
    printf("\n%lld %lld\n", psa[etour[l]-1][k], psa[etour[r]-1][k]);
    printf("\n%d %d %d\n", etour[l], etour[r], queryMin(l+1, r+1)-1);
    printf("%lld\n", ((psa[etour[l]-1][k] + psa[etour[r]-1][k] - psa[queryMin(l+1, r+1)-1][k] - psa[queryMin(l+1, r+1)-2][k])+MOD)%MOD);
  }
  return 0;
}