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

const int MOD = 998244353, MX = 200000 + 5;

int NI, N, K;
int NO;
char SI[MX];
char S[MX];

// #define BRUTE_FORCE

int main()
{
  scanf("%d %d", &NI, &K);
  scanf("%s", SI + 1);
  for (int i = 1; i <= NI; i++)
  {
    if (SI[i] == 'W' || SI[i] == 'A' || SI[i] == 'C')
    {
      N++;
      S[N] = SI[i];
    }
  }
  NO = N;

  ll block = 0, ending = 0, starting = 0, c = 0, w = 0, a = 0;
  for (int i = 1; i <= N; i++)
  {
    if(S[i]=='W')w++;
    else if(S[i]=='A'){
      a++;
      starting+=w;
    }
    else if(S[i]=='C'){
      c++;
      ending+=a;
      block+=starting;
    }
  }
  block = block%MOD;
  ending = ending%MOD;
  starting = starting%MOD;

  ll total = block;
  for (int i = 2; i <= K; i++)
  {
    //how do I mod correctly
    block+= (ending*w)%MOD + (starting*c)%MOD + (((a * c)%MOD * w)%MOD * (i-2))%MOD;
    block = block%MOD;
    total+=block;
    total = total%MOD;
  }
  printf("%lld\n", total);

  return 0;
}