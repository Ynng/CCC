#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
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

const int MOD = 1e9+7, MX = 500000 + 5;

int N;

//bit example
//binary indexed tree
int bit[MX];

ll query(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[r];
    r ^= (r & -r);
  }
  return sum;
}

void update(int dif, int index)
{
  while (index <= N)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}

int main()
{
  scanf("%d", &N);
  ll inversion = 0;
  for(int i = 1, val; i <= N; i++)
  {
    scanf("%d", &val);
    ll less = query(val);
    ll more = i-less-1;
    if(less > more)
      inversion+=more;
    else
      inversion+=less;

    update(1, val);
  }

  printf("%lld\n", inversion);
  return 0;
}