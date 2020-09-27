#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9 + 7, MX = 4000 + 5;

int H, W;
char g[MX][MX];
bool visited[MX][MX];
queue<pi> q, q1;

void bfs(int count, char c)
{
  int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
  while(!q.empty()){
    int i,j;
    tie(i,j)=q.front();
    q.pop();
    for(int k = 0; k < 4; k++){
      int ni = i + move[k][0];
      int nj = j + move[k][1];
      if (visited[ni][nj]) continue;
      if(ni<1 || nj < 1 || ni>H || nj > W || g[ni][nj]=='.') continue;
      visited[ni][nj]=true;
      if (g[ni][nj] == c){
        q.push({ni,nj});
      }else{
        q1.push({ni,nj});
      }
    }
  }

}

int main()
{
  int rcount = 0, fcount = 0;
  scanf("%d %d", &H, &W);
  for (int i = 1; i <= H; i++)
    for (int j = 1; j <= W; j++)
      scanf(" %c", &g[i][j]);

  int count = 0;
  int cur = g[1][1];
  q1.push({1, 1});
  visited[1][1]=true;
  while (!q1.empty())
  {
    count++;
    swap(q, q1);
    bfs(count, cur);
    cur = cur == 'F' ? 'R' : 'F';
  }

  printf("%d\n", count);

  return 0;
}