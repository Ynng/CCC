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

const int MOD = 1000000007, MX = 100000 + 5;

int N;
vector<int> G[MX];
int visited[MX];
bool used[MX];
int compCount = 0;

void dfs(int cur, int nodeNum){
  visited[cur] = nodeNum;
  for(int neighbor : G[cur]){
    if(visited[neighbor] !=0 && visited[neighbor] < nodeNum && !used[visited[neighbor]]){
      used[visited[neighbor]] = true;
      compCount--;
    }else if(visited[neighbor] == 0) dfs(neighbor, nodeNum);
  }
}

int main()
{
  scanf("%d", &N);
  for(int i = 1, parent; i <= N; i++)
  {
    scanf("%d", &parent);
    G[parent].push_back(i);
  }

  int nodeNum = 0;
  compCount = 0;
  for(int i = 1; i <= N; i++)
  {
    if(!visited[i]){
      compCount++;
      nodeNum++;
      dfs(i, nodeNum);
    }
  }

  printf("%d ", compCount);

  for (int i = 1; i <= N; i++){
    G[i].clear();
    visited[i] = 0;
    used[i] = false;
  }

  scanf("%d", &N);
  for(int i = 1, parent; i <= N; i++)
  {
    scanf("%d", &parent);
    G[parent].push_back(i);
  }
  nodeNum = 0;
  compCount = 0;
  for(int i = 1; i <= N; i++)
  {
    if(!visited[i]){
      compCount++;
      nodeNum++;
      dfs(i, nodeNum);
    }
  }

  printf("%d\n", compCount);
  
  return 0;
}