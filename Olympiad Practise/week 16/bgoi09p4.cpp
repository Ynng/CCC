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

const int MAX = 1000000007, MX = 1000000 + 5;

int N;
int H[MX];
int J[MX];
int ans[MX];
int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", H + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", J + i);

  deque<int> deck;
  for (int i = N, pos; i >= 1; i--)
  {
    while(!deck.empty() && deck.front() <= H[i]) deck.pop_front();
    deck.push_front(H[i]);
    if(deck.size() <= J[i])ans[i]=-1;
    else ans[i] = *(deck.begin() + J[i]);
  }

  for (int i = 1; i <= N; i++)
    printf("%d ", ans[i]);

  return 0;
}