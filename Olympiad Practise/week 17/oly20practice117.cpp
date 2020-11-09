#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
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

#define INF 0x3f3f3f3f // for int
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

ll x,y,A,B;

ll lcm(ll n1, ll n2){
  ll hcf = n1;
  ll temp = n2;
  
  while(hcf != temp)
  {
      if(hcf > temp)
          hcf -= temp;
      else
          temp -= hcf;
  }

  return (n1 * n2) / hcf;
}

int main()
{
  scanf("%lld %lld %lld %lld", &x, &y, &A, &B);
  printf("%lld\n", (y/A-(x-1)/A)+(y/B-(x-1)/B)-(y/lcm(A,B)-(x-1)/lcm(A,B)));
  
  return 0;
}