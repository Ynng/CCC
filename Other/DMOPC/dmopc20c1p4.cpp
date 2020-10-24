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

const int MX = 100 + 5;

ll MOD = 1000000007;

int C,K,T;
ll N;
ll A;
deque<ll> children;

//matrix
struct matrix {
  ll d[MX][MX];
  matrix(){memset (d,0,sizeof(d));}
};

//matrix multiplication
matrix multi(matrix a, matrix b){
  matrix ans;
  for (int i = 0; i <= T; i++)
    for (int k = 0; k <= T; k++)
      for (int j = 0; j <= T; j++)
        ans.d[i][j] = (ans.d[i][j] + a.d[i][k]*b.d[k][j])%MOD;
  return ans;
}

//matrix power
matrix quick_pow(matrix x, ll exp){
  matrix ans;
  for(int i = 0; i<=T; i++)ans.d[i][i]=1;
  while(exp>0){
    if(exp%2!=0)ans = multi(ans,x);
    x=multi(x,x); exp/=2;
  }
  return ans;
}

//power of ll
ll powll(ll base, ll exp)
{
  ll ans = 1;
  for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
    if (exp & 1)
      ans = (ans * base) % MOD;
  return ans;
}

int main()
{
  scanf("%lld %d %d %d", &N, &K, &T, &C);
  matrix x;
  x.d[0][T]=K;
  x.d[T][T]=1;
  for (int i = 1; i <= T; i++)
    x.d[i][i-1] = 1;
  x = quick_pow(x,N-1);

  ll ans = 2*C*x.d[T][T]%MOD;
  for (int i = 0; i < T; i++)
    ans = (ans + C*x.d[i][T]%MOD)%MOD;
  printf("%lld", ans);
  
  return 0;
}