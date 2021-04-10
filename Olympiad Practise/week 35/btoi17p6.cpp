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

const int MOD = 1000000007, MX = 2e5 + 5;

int N, D, dis[MX], ans;
vi adj[MX];

void dfs(int u, int pa)
{
  deque<int> q;
  for (int v : adj[u])
  {
    if (v == pa)
      continue;
    dfs(v, u);
    q.pb(dis[v] + 1);
  }
  sort(q.begin(), q.end());
  while(q.size()>=2 && q[0] + q[1] < D){
    ans--;
    q.pop_front();
  }
  if(q.empty())dis[u] = 0;
  else dis[u] = q[0] % D;
  if(dis[u]==0)ans++;
}

int main()
{
  scanf("%d %d", &N, &D);

  for (int i = 1, pa; i < N; i++)
  {
    scanf("%d", &pa);
    adj[pa].pb(i);
    adj[i].pb(pa);
  }

  dfs(0, -1);

  printf("%d", ans);

  return 0;
}