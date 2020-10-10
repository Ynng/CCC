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

const int MOD = 1e9 + 7, MX = 200000 + 5;

ll N, M, K, X;
pi freq[MX];
int ans[MX];
ll psa[MX];
int idx;//index
int main()
{
  scanf("%lld %lld %lld %lld", &N, &M, &K, &X);
  for (int i = 1, f; i <= N; i++){
    scanf("%d", &f);
    freq[i] = {f, i};
  }
  sort(freq + 1, freq + N + 1);
  for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + freq[i].f;
  int lft = 0, rit = N;
  while(lft <= N && psa[lft]<K)lft++;
  while(rit >= 1 && psa[N]-psa[rit]<K)rit--;
  if (lft < X || N - rit > X)
  {
    printf("-1\n");
    return 0;
  }
  for(int i = X; i <= N; i++)
  {
    if(psa[i]-psa[i-X]>=K){
      for(int j = i-X+1; j<= i; j++){
        ans[freq[j].s] = ++idx;
      }
      for(int j = 1; j <= N; j++){
        if(!ans[j])ans[j]= ++idx;
        printf("%d ", ans[j]);
      }
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}