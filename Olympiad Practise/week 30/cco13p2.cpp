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

const int MOD = 1000000007, MX = (1 << 21) + 5;

int N, M, K;
pi S[MX];
int main()
{
  scanf("%d %d", &N, &M);
  N = 1 << N;
  K = N - 1;
  for (int i = K + 1, tmp; i <= K + N; i++)
  {
    scanf("%d", &tmp);
    S[i] = {tmp, i - K};
  }

  for (int i = K; i >= 1; i--)
    S[i] = max(S[2 * i], S[2 * i + 1]);

  for (int j = 1; j <= M; j++)
  {
    char op;
    scanf(" %c", &op);
    if (op == 'W')
      printf("%d\n", S[1].s);
    else if (op == 'S')
    {
      int x;
      scanf("%d", &x);
      int cnt = 0;
      for (int i = (K + x) / 2; i >= 1; i /= 2)
      {
        if (S[i].s == x)
          cnt++;
        else
          break;
      }
      printf("%d\n", cnt);
    }
    else if (op == 'R')
    {
      int x, y;
      scanf("%d %d", &x, &y);
      x += K;
      S[x].f = y;
      for (int i = x / 2; i >= 1; i /= 2)
        S[i] = max(S[2 * i], S[2 * i + 1]);
    }
  }
  return 0;
}