#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

#define INF 0x3f3f3f3f            // for int
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

const int MOD = 1e9 + 7, MX = 1000000 + 5;

int N;
ll r[MX];
int rfreq[MX];
ll sum;
int main()
{
  scanf("%d", &N);
  int mxr = 0, mxc = 0;
  for (int i = 1, t; i <= N; i++){
    scanf("%d", &t);
    mxr = max(t, mxr);
    r[t]+=t;
    rfreq[t]++;
  }
  for(int i = 1; i <= MX-5; i++)
  {
    rfreq[i]+=rfreq[i-1];
    r[i]+=r[i-1];
  }
  for (int i = 1, t; i <= N; i++){
    scanf("%d", &t);
    sum+=r[t];
    sum+=(N-(ll)rfreq[t])*t;
    mxc = max(mxc, t);
    if(t>mxr){
      printf("-1\n");
      return 0;
    }
  }
  if(mxr != mxc){
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", sum);

  return 0;
}