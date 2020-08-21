#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
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

const int MOD = 1e9 + 7, MX = 200000 + 5;

ll N, Q;
ll a[MX];
ll smin[MX], smax[MX];

int findFirstBiggerThan(int target)
{
  int l = 0;
  int r = N;
  int m;
  int ans = 0;
  while (l <= r)
  {
    m = (l + r) / 2;
    if (smax[N-m] <= target)
      l = m+1;
    else
    {
      ans = N-m;
      r = m - 1;
    }
  }
  if(ans > N) ans = N;
  return ans;
}

int findFirstSmallerThan(int target)
{
  int l = 0;
  int r = N;
  int m;
  int ans = 0;
  while (l <= r)
  {
    m = (l + r) / 2;
    if (smin[m+1] >= target)
      r = m - 1;
    else {
      ans = m+1;
      l = m + 1;
    }
  }
  if(ans > N) ans = N;
  return ans;
}

int main()
{
  scanf("%lld %lld", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%lld", a + i);

  smin[N] = a[N];
  smax[N] = a[N];
  for (int i = N - 1; i >= 1; i--)
  {
    smin[i] = min(smin[i + 1], a[i]);
    smax[i] = max(smax[i + 1], a[i]);
  }

  for (int i = 1, l, e; i <= Q; i++)
  {
    scanf("%d %d", &l, &e);
    int a = findFirstBiggerThan(l + e);
    int b = findFirstSmallerThan(l - e);
    ll len = max(a,b);
    printf("%lld\n", N - len);
  }

  return 0;
}