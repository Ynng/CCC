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

const int MOD = 1e9+7, MX = 10000 + 5;

int main()
{
  ll k, n, x, output;
  scanf("%lld %lld", &k, &n);

  ll vertex = 0.5*(1+sqrt(-1+8.0 * k));
  ll k2 = 2*k;
  double sqrt2 = sqrt(2.0);

  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &x);

    if(x > vertex){
      printf("%lld\n", vertex);
    }else{
      output = ceil(2 * (sqrt( (x * x - x + k2) )/sqrt2) - x);
      printf("%lld\n", output);
    }
  }
}