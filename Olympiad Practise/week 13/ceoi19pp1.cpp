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

const int MOD = 1e9+7, MX = 1500 + 5;

int H, V;
ll Y[MX], X[MX];
unordered_map<ll, int> y;

int main()
{
  scanf("%d %d", &H, &V);
  for(int i = 1; i <= H; i++)
  {
    scanf("%lld", Y+i);
    for (int j = 1; j < i; j++)
      y[Y[i] - Y[j]]++;
  }
  int sum = 0;
  for(int i = 1; i <= V; i++)
  {
    scanf("%lld", X+i);
    for (int j = 1; j < i; j++){
      ll dis = X[i] - X[j];
      sum+=y[dis];
    }
  }
  
  
  printf("%d", sum);
  
  
  return 0;
}