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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 100000 + 5;

int N, A[MX], D;
int freq[MX];

ll f[MX]; //factorial
ll inv[MX];

//quick power
ll quickpow(ll base, ll exp)
{
  ll ans = 1;
  for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
    if (exp & 1)
      ans = (ans * base) % MOD;
  return ans;
}

//nChoosek nck choosing notation
ll choose(int n, int k)
{
  return f[n] * inv[k] % MOD * inv[n - k] % MOD;
}

//initializing choosing notation and factorial etc
void init(int N)
{
  f[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= N + 5; i++)
    f[i] = f[i - 1] * i % MOD;
  for (int i = 1; i <= N + 5; i++)
    inv[i] = quickpow(f[i], MOD - 2);
}

int main()
{
  scanf("%d", &N);
  init(N);

  for (int i = 1; i <= N; i++)
  {
    scanf("%d", A + i);
    freq[A[i]]++;
  }
  sort(A + 1, A + 1 + N);
  for (int i = 1; i <= N; i++)
    freq[i] += freq[i - 1];

  scanf("%d", &D);
  for (int i = 1, k; i <= D; i++)
  {
    scanf("%d", &k);
    int p = A[k];
    int need = k - freq[p - 1], tot = freq[p] - freq[p - 1];
    printf("%lld\n", choose(tot, need));
  }

  return 0;
}