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

const int MOD = 1000000007, MX = 200000 + 5;

int N, M, K;
pi best[MX];
int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 1, A, B, C; i <= K; i++)
  {
    scanf("%d %d %d", &A, &B, &C);
    if(best[B].f < C)best[B] = {C, A};
  }
  for(int i = 1; i <= N; i++)
    printf("%d ", best[i].f?best[i].s : -1);
  
  
  return 0;
}