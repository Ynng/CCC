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

const int MOD = 1000000007, MX = 5000 + 5;

int N, Q;
ll bit[MX][MX];

//2d maximum binary indexed tree
//2d bit

ll query(int x, int y)
{
  ll val = 0;
  int origX = x;
  while (y > 0)
  {
    x = origX;
    while (x > 0)
    {
      val += bit[x][y];
      x -= (x & -x);
    }
    y -= (y & -y);
  }
  return val;
}

void update(int x, int y, ll diff)
{
  int origX = x;
  while (y <= MX)
  {
    x = origX;
    while (x <= MX)
    {
      bit[x][y] += diff;
      x += (x & -x);
    }
    y += (y & -y);
  }
}

int main()
{
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= Q; i++)
  {
    char op;
    scanf(" %c", &op);
    if (op == 'U')
    {
      int x1, y1, x2, y2, v;
      scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
      update(x1, y1, v);
      update(x1, y2+1, -v);
      update(x2+1, y1, -v);
      update(x2+1, y2+1, v);
    }
    else if (op == 'Q')
    {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      ll sum = 0;
      for (int x = x1; x <= x2; x++)
      {
        for (int y = y1; y <= y2; y++)
        {
          sum+=query(x, y);
        }
      }
      printf("%lld\n", sum);
      // printf("%lld\n", query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1));
    }
  }
  return 0;
}