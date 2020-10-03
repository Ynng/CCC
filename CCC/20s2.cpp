
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

const int MOD = 1e9 + 7, MX = 10000 + 5;

int M, N;
int grid[1005][1005];
bool visited[1000005];
vector<int> adj[1000005];
#define CURRENT grid[row][col]

bool bfs()
{
  queue<int> q;
  q.push(grid[1][1]);
  while(!q.empty()){
    if(q.front() == M*N)return true;
    for(int n : adj[q.front()]){
      if(visited[n])continue;
      visited[n] = true;
      q.push(n);
    }
    q.pop();
  }
  return false;
}

int main()
{
  scanf("%d", &M);
  scanf("%d", &N);
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++){
      scanf("%d", &grid[i][j]);
      adj[i*j].push_back(grid[i][j]);
    }

  printf(bfs() ? "yes" : "no");
  return 0;
}