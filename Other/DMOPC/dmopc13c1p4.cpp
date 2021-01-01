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

const int MOD = 1000000007, MX = 50 + 5;

int T, L, W;
char grid[MX][MX];
pi c;
pi w;

pi offset[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool inBound(pi cur){
  return cur.f >= 1 && cur.f <= W && cur.s >= 1 && cur.s <= L;
}

void solve()
{
  scanf("%d %d", &L, &W);
  for (int i = 1; i <= W; i++)
  {
    for (int j = 1; j <= L; j++)
    {
      scanf(" %c", &grid[i][j]);
      if (grid[i][j] == 'C')
        c = {i, j};
      if (grid[i][j] == 'W')
        w = {i, j};
    }
  }

  queue<pair<pi, int>> q;
  q.push({c, 0});
  grid[c.f][c.s] = 'X';
  int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
  int ans = 100;
  bool found = false;

  while(!q.empty()){
    int i, j, d;
    i = q.front().f.f;    
    j = q.front().f.s;    
    d = q.front().s;
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      int ni = i + move[k][0];
      int nj = j + move[k][1];
      int nd = d+1;
      if (ni<1 || nj < 1 || ni>W || nj > L) continue;
      if (grid[ni][nj] == 'W'){
        ans = nd;
        found = true;
        break;
      }
      if (grid[ni][nj] == 'X') continue;
      grid[ni][nj] = 'X';
      q.push({{ni, nj}, nd});
    }
    if(found)break;
  }

  if(ans >= 60)printf("#notworth\n");
  else printf("%d\n", ans);
}

int main()
{
  scanf("%d", &T);
  for (int i = 1; i <= T; i++)
  {
    solve();
  }
  return 0;
}