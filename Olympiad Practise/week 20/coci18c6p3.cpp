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

const int MOD = 1000000007, MX = 500 + 5;

int N,M,K;
int P[MX];
int B[MX];
int dp[MX][MX];
int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 1; i <= N; i++)
    scanf("%d", P+i);

  for(int i = 0; i <= M; i++)
    scanf("%d", B+i);

  for(int i = 1; i <= N; i++)
    for (int j = P[i]; j <= M; j++)
      for (int k = j-P[i]; k <= K; k++)
        dp[i][k] = max(dp[i][k], dp[i-1][k-(j-P[i])] + B[j]);

  printf("%d\n", dp[N][K]);
  
  return 0;
}