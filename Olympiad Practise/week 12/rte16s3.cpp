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
int p[MX][MX];
ll dis[MX];
bool visited[MX];
int m[MX];

//need better solution
//TODO: ask about this one (p3)

int main()
{
  scanf("%d", &N);

  for (int i = 1, a, b, w; i <= N - 1; i++)
  {
    scanf("%d %d %d", &a, &b, &w);
    a++;
    b++;
    in[a].push_back({b, w});
    in[b].push_back({a, w});
  }

  for (int i = 1; i <= N ; i++)
    p[i][i]=i;

  queue<int> nodes;
  queue<int> parents;
  nodes.push(1);
  parents.push(1);
  visited[1]=true;
  int c = 1;
  m[1]=1;
  while(!nodes.empty()){
    int cur = nodes.front();
    int parent = parents.front();
    nodes.pop();
    parents.pop();
    // printf("cur %d\n", cur);
    // for (int i = 1; i <= N; i++){
    //   for (int j = 1; j <= N; j++)
    //     printf("%d ", p[i][j]);
    //   printf("\n");
    // }
    int ccur = m[cur];
    for(pi child : in[cur]){
      if(visited[child.f])continue;
      visited[child.f]=true;
      c++;
      m[child.f]=c;
      nodes.push(child.f);
      parents.push(cur);
      dis[c] = dis[ccur]+child.s;
      for(int i = 1; i < c;i++)
        if(p[ccur][i]){
          p[c][i]=p[ccur][i];
          p[i][c]=p[ccur][i];
        }
    }
  }

  // for (int i = 1; i <= N; i++){
  //   for (int j = 1; j <= N; j++)
  //     printf("%d ", p[i][j]);
  //   printf("\n");
  // }

  scanf("%d", &Q);
  for (int i = 1, u, v; i <= Q; i++)
  {
    scanf("%d %d", &u, &v);
    u++;
    v++;
    u = m[u];
    v=m[v];
    printf("%lld\n", dis[u]+dis[v]-2*dis[p[u][v]]);
  }

  return 0;
}