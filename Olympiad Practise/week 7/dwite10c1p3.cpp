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

const int MOD = 1e9 + 7, MX = 10000 + 5;

int N, M;

int highestPof2(int n)
{
  for (int i = n; i >= 1; i--)
    if ((i & (i - 1)) == 0)
      return i;
  return 0;
}

int recur(int n, int m)
{
  if (!(n && m))
    return 0;
  int n2 = highestPof2(n);
  int m2 = highestPof2(m);
  if (n2 == m2 == n == m)
    return 1;
  else
  {
    int l = min(n2, m2);
    return 1 + recur(n-l, l) + recur(n, m-l);
  }
}

void solve()
{
  int i = recur(N, M);
  printf("%d\n", i);
}

int main()
{

  for (int i = 0; i < 5; i++)
  {
    scanf("%d %d", &N, &M);
    solve();
  }
  return 0;
}