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

const int MOD = 1000000007, MX = 10000 + 5;

int N;
struct rectangle
{
  int x, y, w, h;
};
rectangle arr[MX];

int main()
{
  scanf("%d", &N);
  for (int i = 1, x, y, w, h; i <= N; i++)
  {
    scanf("%d %d %d %d", &x, &y, &w, &h);
    arr[i] = {x, y, w, h};
  }
  int p, q;
  scanf("%d %d", &p, &q);

  for (int i = N; i >= 1; i--)
  {
    rectangle cur = arr[i];
    if (cur.x <= p && cur.y <= q && (cur.x + cur.w) >= p && (cur.y + cur.h) >= q)
    {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}