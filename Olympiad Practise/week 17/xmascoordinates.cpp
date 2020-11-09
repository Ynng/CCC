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

const int MOD = 1000000007, MX = 1000 + 5;

int N, M;
char grid[MX][MX];
char visited[MX][MX];
int movegrid[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int startdis, enddis;
queue<pair<pi, int>> q;

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= M; j++)
    {
      scanf(" %c", &grid[i][j]);
      if(grid[i][j] == 'P'){
        visited[i][j] = true;
        q.push({{i,j}, 0});
      }
    }
  }
  
  //BFS
  while(!q.empty()){
    pi pos = q.front().f;
    int dis = q.front().s;
    q.pop();
    if(grid[pos.f][pos.s] == 'O')startdis = dis;
    if(grid[pos.f][pos.s] == 'X')enddis = dis;
    for(int k = 0; k < 4; k++){
      int ni = pos.f + movegrid[k][0];
      int nj = pos.s + movegrid[k][1];
      if (visited[ni][nj]) continue;
      if(ni<1 || nj < 1 || ni>N || nj > M || grid[ni][nj]=='#') continue;
      visited[ni][nj]=true;
      q.push({{ni,nj}, dis+1});
    }
  }
  if(!startdis || !enddis)printf("-1\n");
  else printf("%d\n", startdis + enddis);
  
  return 0;
}