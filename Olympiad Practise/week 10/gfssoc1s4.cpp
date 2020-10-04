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

const int MOD = 1e9 + 7, MX = 250 + 5;

int N, Q;
ll bit[MX][MX][MX];
ll val[MX][MX][MX];

//3d binary indexed tree
//3d bit
//2d binary indexed tree
//2d bit

ll query(int x, int y, int z)
{
  ll val = 0;
  for (int zi = z; zi > 0; zi -= (zi & -zi))
    for (int yi = y; yi > 0; yi -= (yi & -yi))
      for (int xi = x; xi > 0; xi -= (xi & -xi))
        val += bit[xi][yi][zi];
  return val;
}

void update(int x, int y, int z, ll diff)
{
  for (int zi = z; zi <= N; zi += (zi & -zi))
    for (int yi = y; yi <= N; yi += (yi & -yi))
      for (int xi = x; xi <= N; xi += (xi & -xi))
                bit[xi][yi][zi] += diff;
}
int main()
{
  scanf("%d", &N);
  scanf("%d", &Q);
  ll sum = 0;
  for (int i = 1; i <= Q; i++)
  {
    char c;
    scanf(" %c", &c);
    if (c == 'C')
    {
      int x, y, z, l;
      scanf(" %d %d %d %d", &x, &y, &z, &l);
      update(x, y, z, l - val[x][y][z]);
      val[x][y][z] = l;
    }
    else
    {
      int x1, y1, z1, x2, y2, z2;
      scanf(" %d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
      x1--;
      y1--;
      z1--;
      sum += query(x2, y2, z2);
      sum -= query(x1, y2, z2) + query(x2, y1, z2) + query(x2, y2, z1);
      sum += query(x1, y1, z2) + query(x1, y2, z1) + query(x2, y1, z1);
      sum -= query(x1, y1, z1);
    }
  }
  printf("%lld\n", sum);
  return 0;
}