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

const int MOD = 1e9 + 7, MX = 200000 + 5;

int N;
int h[MX];
int a[MX];

ll bit[MX];
ll dp[MX];

ll getMax(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum = max(bit[r], sum);
    r ^= (r & -r);
  }
  return sum;
}

void update(ll dif, int index)
{
  while (index <= N)
  {
    if(dif>bit[index])
      bit[index] = dif;
    index += (index & -index);
  }
}
int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", h + i);
  }
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", a + i);
  }
  
  ll answer = 0;
  for(int i = 1; i <= N; i++)
  {
    ll maxPrevious = getMax(h[i]);
    dp[i] = maxPrevious + a[i];
    update(dp[i], h[i]);
    answer = max(dp[i], answer);
  }
  printf("%lld", answer);
  return 0;
}