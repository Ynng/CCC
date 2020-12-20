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
int A[MX];
ll psa[MX];
int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d", A+i);
    psa[i]= A[i] + psa[i-1];
  }

  ll minDiff = INT32_MAX;
  for(int i = 2; i < N; i++)
  {
    ll sumL = psa[i-1];
    
    int l = i;
    int r = N;

    while(l<r){
      int m = (l+r)/2;
      ll sumM = psa[m]-psa[i-1];
      ll sumR = psa[N]-psa[m];
      ll diff = max(sumL, max(sumM, sumR)) - min(sumL, min(sumM, sumR));

      if(sumM<sumR)l=m+1;
      else r = m;

      minDiff = min(diff, minDiff);
    }
  }
  printf("%lld", minDiff);
  return 0;
}