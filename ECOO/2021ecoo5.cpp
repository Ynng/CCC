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

const ll MOD = 1000000007, MX = LLONG_MAX - 10LL;

set<pl> points;
ll queryCounter = 0;

pl query(pl point)
{
  printf("? %lld %lld\n", point.f, point.s);
  fflush(stdout);
  queryCounter++;
  ll x, y;
  scanf("%lld %lld", &x, &y);
  if (x == 1000000001 && y == 1000000001)
    exit(0);
  points.insert({x, y});
  return {x, y};
}

int main()
{
  pl xmaxp = query({MX, 0});
  pl xminp = query({-MX, 0});
  pl ymaxp = query({0, MX});
  pl yminp = query({0, -MX});

  ll xmax = xmaxp.f;
  ll xmin = xminp.f;
  ll ymax = ymaxp.s;
  ll ymin = yminp.s;

  // ll xmax = 10;
  // ll xmin = -10;
  // ll ymax = 10;
  // ll ymin = -10;

  pl last = xmaxp;
  pl lastQ = {xmax, ymax};
  while (queryCounter < 2000)
  {
    ll x = 2 * (lastQ.f - last.f);
    ll y = 2 * (lastQ.s - last.s);
    if(x==0)x=1;
    if(y==0)y=1;
    x = last.f - x;
    y = last.s - y;
    if(x > xmax)x=xmax;
    if(x < xmin)x=xmin;
    if(y > ymax)y=ymax;
    if(y < ymin)y=ymin;
    query({x, y});
  }
  // for (ll x = xmin; x <= xmax; x++)
  // {
  //   for (ll y = ymin; y <= ymax; y++)
  //   {
  //     query({x,y});
  //   }
  // }

  printf("! %ld\n", points.size());
  fflush(stdout);

  return 0;
}