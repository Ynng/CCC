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

const int MOD = 1e9+7, MX = 1000000 + 5;

int N, D;
int psa[MX];
int main()
{
  scanf("%d %d", &N, &D);
  for(int i = 1; i <= N; i++){
    scanf("%d", psa+i);
    psa[i]+=psa[i - 1];
  }
  int l = 1, r = N;
  for(int i = 1, n; i <= D; i++)
  {
    scanf("%d", &n);
    int f = psa[l+n-1] - psa[l-1];
    int s = psa[r] - psa[l+n-1];
    if(f>=s){
      printf("%d\n",f);
      l=l+n;
    }else{
      printf("%d\n",s);
      r=l+n-1;
    }
  }
  
  return 0;
}