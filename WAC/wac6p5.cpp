#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define INF 0x3f3f3f3f // for int
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
vector<int> G[MX];
bool visited[MX];
bool looped[MX];
int K;
int line;

void dfs(int cur){
  int childCount = 0;
  for(int child: G[cur]){
    childCount++;
    if(visited[child])continue;
    visited[child] = true;
    dfs(child);
  }

  K += childCount/2;
  if(childCount == 2){
    line++;
  }
}

/**
 * Does not work
 */

int main()
{
  scanf("%d", &N);
  for(int i = 1, u, v; i < N; i++)
  {
    scanf("%d %d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
  } 


  visited[1] = true;
  dfs(1);

  K-=line/2;

  printf("%d\n", K);

  return 0;
}