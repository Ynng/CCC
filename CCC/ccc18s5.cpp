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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 100000 + 5;

struct E
{
  int u, v, w;
  bool f;
};

int N, M, P, Q, r[MX], c[MX], row, col;
vector<E> e;
ll tot, mst;

int fd(int d, int p[])
{
  if (p[d] != d)
    p[d] = fd(p[d], p);
  return p[d];
}

int main()
{
  scanf("%d %d %d %d", &N, &M, &P, &Q);
  row = N;
  col = M;
  for (int i = 1, u, v, w; i <= P; i++)
  {
    scanf("%d %d %d", &u, &v, &w);
    e.pb(E{u, v, w, 0});
    tot += (ll)N * w;
  }
  for (int i = 1, u, v, w; i <= Q; i++)
  {
    scanf("%d %d %d", &u, &v, &w);
    e.pb(E{u, v, w, 1});
    tot += (ll)M * w;
  }
  sort(all(e), [](E x, E y) { return x.w < y.w; });

  /* Disjoint set initialization */
  for (int i = 1; i <= N; i++)
    r[i] = i;
  for (int i = 1; i <= M; i++)
    c[i] = i;

  for (E x : e)
  {
    if (x.f)
    { //vertical edge
      if (row == 1)
        continue;
      int fu = fd(x.u, r), fv = fd(x.v, r);
      if (fu != fv)
      {
        r[fu] = fv;
        row--;
        mst += (ll)x.w * col;
      }
    }
    else
    { //horizontal edge
      if (col == 1)
        continue;
      int fu = fd(x.u, c), fv = fd(x.v, c);
      if (fu != fv)
      {
        c[fu] = fv;
        col--;
        mst += (ll)x.w * row;
      }
    }
    if (row == 1 && col == 1)
      break;
  }

  printf("%lld", tot - mst);
  return 0;
}