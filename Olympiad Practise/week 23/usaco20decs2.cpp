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

const int MOD = 1000000007, MX = 2500 + 5;

int N, x[MX], y[MX], id[MX], rk, psa[MX][MX];
map<int, int> cx, cy; //coordinate compression
ll ans;

int get(int r1, int c1, int r2, int c2){
  if(c1 > c2)return 0;
  r1--, c1--;
  return psa[r2][c2] - psa[r1][c2] - psa[r2][c1] + psa[r1][c1];
}

int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d %d", &x[i], &y[i]);
    cx[x[i]] = 0;
    cy[y[i]] = 0;
  }
  rk = 0; for(auto& e : cx)e.second = ++rk;
  rk = 0; for(auto& e : cy)e.second = ++rk;
  
  for(int i = 1; i <= N; i++)
  {
    x[i] = cx[x[i]]; y[i] = cy[y[i]];
    psa[x[i]][y[i]]++;
    id[x[i]]=i;
  }
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];

  for(int i = 1; i <= N; i++)
    for(int j = i; j <= N; j++){
      int a = id[i], b=id[j];
      int lft = min(y[a], y[b]), rit=max(y[a], y[b]);
      ll cowleft = get(i, 1, j, lft-1), cowright = get(i, rit+1, j, N);
      ans += (cowleft+1) * (cowright+1);
    }

  printf("%lld", ans+1);
  return 0;
}