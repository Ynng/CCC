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

const int MOD = 1e9 + 7, MX = 1000 + 5;

int n, m;
char g[MX][MX];
bool explored[MX][MX];

deque<pi> q;
deque<int> qi;
pi start;
pi endding;
int main()
{
  scanf("%d %d", &n, &m);
  char c;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      scanf(" %c", &c);
      if (c == 's')
      {
        start = {i, j};
      }
      if (c == 'e')
      {
        endding = {i, j};
        c = '.';
      }
      g[i][j] = c;
    }
  }

  q.push_back(start);
  qi.push_back(0);
  while (q.size() > 0)
  {
    int r = q.front().f;
    int c = q.front().s;
    int i = qi.front();
    q.pop_front();
    qi.pop_front();

    if (r == endding.f && c == endding.s)
    {
      printf("%d\n", i-1);
      return 0;
    }

    explored[r][c] = true;
    r++;
    if (!explored[r][c] && g[r][c] == '.')
    {
      q.push_back({r, c});
      qi.push_back(i + 1);
    }
    r -= 2;
    if (!explored[r][c] && g[r][c] == '.')
    {
      q.push_back({r, c});
      qi.push_back(i + 1);
    }
    r++;
    c++;
    if (!explored[r][c] && g[r][c] == '.')
    {
      q.push_back({r, c});
      qi.push_back(i + 1);
    }
    c -= 2;
    if (!explored[r][c] && g[r][c] == '.')
    {
      q.push_back({r, c});
      qi.push_back(i + 1);
    }
  }

  printf("%d\n", -1);
  return 0;
}