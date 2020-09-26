#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7, MX = 4000 + 5;

int H, W;
char m[MX][MX];
int mark[MX][MX];
vector<int> g[MX*MX/2];
bool visited[MX*MX/2];

void dfs(int i, int j, int count, char c){
  if(mark[i][j]){
    if(mark[i][j]!=0 && mark[i][j]!=count){
      g[count].push_back(mark[i][j]);
      g[mark[i][j]].push_back(count);
    }
    return;
  }
  if(m[i][j]!=c)return;
  mark[i][j] = count;
  i++;
  dfs(i,j,count, c);
  i-=2;
  dfs(i,j,count, c);
  i++;
  j++;
  dfs(i,j,count, c);
  j-=2;
  dfs(i,j,count, c);
}

int main()
{
  scanf("%d %d", &H, &W);
  for(int i = 1; i <= H; i++)
  {
    for(int j = 1; j <= W; j++)
    {
      scanf(" %c", &m[i][j]);
    }
  }

  int count = 0;
  for(int i = 1; i <= H; i++)
  {
    for(int j = 1; j <= W; j++)
    {
      char cur = m[i][j];
      if(cur != '.' && mark[i][j] == 0){
        count++;
        dfs(i,j, count, cur);
      }
    }
  }

  queue<pi> q;
  q.push({1,1});
  int mx = 0;
  visited[1]=true;

  while(!q.empty()){
    pi curp = q.front();
    int cur = curp.f;
    q.pop();
    mx = max(mx, curp.s);
    for (auto itr = g[cur].begin(); itr != g[cur].end(); ++itr) {
      if(visited[*itr])continue;
      visited[*itr] = true;
      q.push({*itr, curp.s+1});
    }
  }

  

  printf("%d", mx);
  
  return 0;
}