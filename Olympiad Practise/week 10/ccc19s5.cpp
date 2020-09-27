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

int N, K;
int a[MX][MX];
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
      val = max(val, bit[x][y]);
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
      bit[x][y] = max(bit[x][y], diff);
      x += (x & -x);
    }
    y += (y & -y);
  }
}

int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++)
      scanf(" %d", &a[i][N - i + j]);
  ll sum = 0;
  for(int i = 1; i <= N; i++)
  {
    //add diagonal to bit
    for (int j = 0; j < i; j++)
    {
      int r = N-j, c = N+1-i+j;
      update(r, c, a[r][c]);
    }
    if(i<K)continue;
    int tric = i-K+1;
    for (int j = 0; j < tric; j++)
    {
      int r = N-j, c = N-tric+1+j;
      sum+=query(r, c);
    }
  }
  printf("%lld", sum);
  return 0;
}