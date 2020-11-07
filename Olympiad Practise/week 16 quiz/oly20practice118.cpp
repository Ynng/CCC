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

int N;
int a[MX];
int psa[MX];

int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d", a+i);
    psa[i] = a[i] + psa[i-1];
  }

  int lo = 1, hi = N;
  int mid = MOD;
  int ans = MOD;
  //TODO: learn to properly do binary search
  while(true){
    mid = (lo + hi)/2;
    if(mid == lo)break;
    if(psa[mid] < (psa[N]-psa[mid])){
      lo = mid;
    }
    else{
      hi = mid;
    }
    ans = min(ans, abs(psa[mid] - (psa[N]-psa[mid])));
  }
  printf("%d\n", ans);
  return 0;
}