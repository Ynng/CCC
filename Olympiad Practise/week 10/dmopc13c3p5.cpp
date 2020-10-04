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

const int MOD = 1e9 + 7, MX = 150 + 5;

int M, U, R;
int V[MX], T[MX], F[MX];
int dp[305][105];
int main()
{
  scanf("%d %d %d", &M, &U, &R);
  for (int i = 1; i <= R; i++)
  {
    scanf("%d %d %d", V + i, T + i, F + i);
    for (int t = M; t >= T[i]; t--)
      for (int f = U; f >= F[i]; f--)
        dp[t][f] = max(dp[t][f], dp[t - T[i]][f - F[i]] + V[i]);
  }
  
  int answer = 0;
  for (int t = M; t >= 0; t--)
    for (int f = U; f >= 0; f--)
      answer = max(answer, dp[t][f]);
  printf("%d\n", answer);

  return 0;
}