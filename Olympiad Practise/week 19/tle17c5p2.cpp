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

const int MOD = 1000000007, MX = 100000 + 5;

int N, D;
int x[MX];
int lftR = INT_MAX, ritR = INT_MIN;
int lftL = INT_MAX, ritL = INT_MIN;
int main()
{
  scanf("%d %d", &N, &D);
  for(int i = 1; i <= N; i++)
    scanf("%d", x+i);
  for(int i = 1, j1, j2; i <= D; i++){
    scanf("%d %d", &j1, &j2);
    j1 = x[j1];
    j2 = x[j2];
    if(j2 > j1){
      lftR = min(j1, lftR);
      ritR = max(j2, ritR);
    }else{
      lftL = min(j2, lftL);
      ritL = max(j1, ritL);
    }
  }

  if(lftL == INT_MAX)printf("%d\n", ritR - lftR);
  else if(lftR == INT_MAX)printf("%d\n", ritL - lftL);
  else{
    int dist1 = max(ritL, ritR) - lftR + max(ritL, ritR) - lftL;
    int dist2 = ritR - min(lftL, lftR) + ritL - min(lftL, lftR);
    printf("%d\n", min(dist1, dist2));
  }

  return 0;
}