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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 200000 + 5, MXLOG = 40;

int N, logN;
ll a[MX];
ll sorted[MX];
ll sdiff[MX];//diff of sorted
ll stmax[MXLOG][MX];
unordered_map<ll, int> mp;

//sparse table query (inclusive)(maximum)
ll queryMax(int l, int r)
{
  int k = log2(r - l + 1);
  return max(stmax[k][l], stmax[k][r - (1 << k) + 1]);
}

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%lld", a + i);
    sorted[i] = a[i];
  }
  sort(sorted + 1, sorted + 1 + N);
  for (int i = 2; i <= N; i++)
  {
    sdiff[i] = sorted[i] - sorted[i-1];
  }
  for (int i = 1; i <= N; i++)
    mp[sorted[i]] = i;

  // for (int i = 1; i <= N; i++){
  //   printf("%d ", sdiff[i]);
  // }

  memcpy(stmax, sdiff, sizeof(ll) * (N + 1));
  logN = log2(N);

  //initializing sparse table (maximum)
  for (int k = 1; k <= logN; k++)
    for (int i = 1; i <= N - (1 << k) + 1; i++)
      stmax[k][i] = max(stmax[k - 1][i], stmax[k - 1][i + (1 << (k - 1))]);

  ll ans = 0;
  for (int i = 1; i <= N; i++){
    if(a[i]!=sorted[i]){
      int curPos = i;
      int tPos = mp[a[i]];
      int l = min(curPos, tPos);
      int r = max(curPos, tPos);
      l++;
      ans = max(ans, queryMax(l, r));
    }
  }

  printf("%lld\n", ans);
  
  return 0;
}