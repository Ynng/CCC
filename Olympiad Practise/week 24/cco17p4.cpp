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

const int MOD = 1000000007, MX = 500 + 5;

int N;
int h[MX];
bool dp[500][50 * MX];
unordered_set<int> st;
int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", h + i);
  sort(h, h + N, greater<int>());
  dp[0][0] = true;
  int vol = h[0] * N;
  for (int i = 1; i < N; i++)
  {
    int cur = h[i];
    for (int j = 0; j <= vol; j++)
      dp[i][j] = dp[i - 1][j];
    for (int pre : st)
    {
      int dif = pre - cur;
      for (int j = 0; j <= vol - dif; j++)
        if (dp[i - 1][j])
          dp[i][j + dif] = true;
    }
    st.insert(cur);
  }

  for (int j = 0; j <= vol; j++)
    if (dp[N - 1][j])
      printf("%d ", j);
  printf("\n");
  return 0;
}