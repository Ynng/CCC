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

const int MOD = 1e9 + 7, MX = 3000 + 5;

int M, N;

ll bit[MX][MX];
ll a[MX][MX];

ll getSum(int x, int y)
{
  ll sum = 0;
  int origX = x;
  while (y > 0)
  {
    x = origX;
    while (x > 0)
    {
      sum += bit[x][y];
      x -= (x & -x);
    }
    y -= (y & -y);
  }
  return sum;
}

void update(int x, int y, int diff)
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
  scanf("%d %d", &M, &N);
  while (true)
  {
    int r, c, x;
    scanf("%d %d %d", &r, &c, &x);
    if (r == 0 && c == 0 && x == 0)
      break;
    int diff = x - a[r][c];
    a[r][c] = x;
    if ((r + c) % 2)
      diff = -diff;
    update(r, c, diff);
  }
  while (true)
  {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
      return 0;
    ll ans = getSum(r2, c2) - getSum(r2, c1 - 1) - getSum(r1 - 1, c2) + getSum(r1 - 1, c1 - 1);
    if ((r1 + c1) % 2)
      ans = -ans;
    printf("%lld\n", ans);
  }
  return 0;
}