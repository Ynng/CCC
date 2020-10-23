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

const int MOD = 1e9+7, MX = 2000 + 5;

int M, N, S;
int psa[MX][MX];

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
  scanf("%d %d %d", &M, &N, &S);
  ll sum = 0;
  int sm = min(S,M-S+1);
  int sn = min(S,N-S+1);
  char c;
  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= N; j++)
    {
      scanf(" %c", &c);
      if(c=='X')
        sum+=min(min(i, M-i+1), sm)*min(min(j, N-j+1), sn);
    }
  }
  printf("%.10f", (double)sum/(M-S+1)/(N-S+1));
  
  return 0;
}