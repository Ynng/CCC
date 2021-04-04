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

int N;
int cost[MX];

vpi G1[MX];
pair<pi, pi> V[MX];
bool visited1[MX];

int groupId[MX];

pi G2[MX];
int lastGroup[MX];

vpi G3[MX];
vector<pair<int, pi>> edges;

//Disjoint set stuff
int parent[MX], height[MX];

void dfsMark(int v, int groupNum)
{
  visited1[v] = true;
  groupId[v] = groupNum;
  for (pi path : G1[v])
  {
    if (visited1[path.f])
      continue;
    dfsMark(path.f, groupNum);
  }
}

int find(int idx)
{
  if (parent[idx] != idx)
    return find(parent[idx]);
  return idx;
}

bool merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v)
    return false;
  if (height[u] > height[v])
    parent[v] = u;
  else
    parent[u] = v;

  if (height[v] == height[u])
    height[v]++;
    
  return true;
}

int main()
{
  scanf("%d", &N);
  for (int i = 1, a, b, c, d; i <= N; i++)
  {
    scanf("%d %d %d %d %d", cost + i, &a, &b, &c, &d);
    G1[a].push_back({b, i});
    G1[b].push_back({a, i});
    G1[c].push_back({d, i});
    G1[d].push_back({c, i});
    V[i] = {{a, b}, {c, d}};
  }

  //Finding Connected Components
  int groupNum = 0;
  for (int v = 1; v <= 2*N; v++)
    if (!visited1[v])
      dfsMark(v, ++groupNum);

  for (int i = 1; i <= N; i++)
  {
    int u = groupId[V[i].f.f];
    int v = groupId[V[i].s.f];
    G3[v].pb({u, cost[i]});
    G3[u].pb({v, cost[i]});
    edges.pb({cost[i], {u, v}});

    // printf("%d %d %d\n",cost[i], u, v);
  }

  // Sort edges in increasing order on basis of cost
  sort(all(edges));

  for (int i = 1; i <= groupNum; i++)
    parent[i] = i;

  ll cost = 0;
  //Minimum spanning tree Kruskal
  int c = 0;
  for (auto edge : edges)
  {
    if (c == N - 1)
      break;
    if (merge(edge.s.f, edge.s.s))
    {
      cost += edge.f;
      c++;
    }
  }

  printf("%lld\n", cost);

  return 0;
}