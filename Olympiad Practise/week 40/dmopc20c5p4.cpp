#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 10000 + 5;

const int base = 131;
int N, M;
vector<string> a, s;
gp_hash_table<ll, int> mp;//The better hashmap
ll ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  s.resize(N);
  for (size_t i = 0; i < N; i++)
    cin >> s[i];

  if (N > M)
  {
    a.resize(M, string(N, ' '));
    for (int i = 0; i < M; i++)
    {
      for (int j = 0; j < N; j++)
      {
        a[i][j] = s[j][i];
      }
    }
    swap(N, M);
    swap(a, s);
  }

  for (int r1 = 0; r1 < N; r1++)
  {
    vl hsh(M, 0);
    for (int r2 = r1 + 1; r2 < N; r2++)
    {
      for (int c = 0; c < M; c++)
        hsh[c] = hsh[c] * base + s[r2][c];
      mp.clear();
      for (size_t c = 0; c < M; c++)
      {
        if (s[r1][c] == s[r2][c])
        {
          ans += mp[hsh[c]];
          mp[hsh[c]]++;
        }
        else
          mp.clear();
      }
    }
  }

  cout << ans << endl;

  return 0;
}