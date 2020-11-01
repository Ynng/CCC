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

const int MOD = 1000000007, MX = 50 + 5;
ll N,K;

//matrix
struct matrix {
  ll d[MX][MX];
  matrix(){memset (d,0,sizeof(d));}
};

//matrix multiplication
matrix multi(matrix a, matrix b){
  matrix ans;
  for (int i = 1; i <= N; i++)
    for (int k = 1; k <= N; k++)
      for (int j = 1; j <= N; j++)
        ans.d[i][j] = (ans.d[i][j] + a.d[i][k]*b.d[k][j])%MOD;
  return ans;
}

//matrix power
matrix quick_pow(matrix x, ll exp){
  matrix ans;
  //generating identity matrix 
  for(int i = 1; i<=N; i++)ans.d[i][i]=1;
  while(exp>0){
    if(exp%2!=0)ans = multi(ans,x);
    x=multi(x,x);
    exp/=2;
  }
  return ans;
}

int main()
{
  scanf("%lld %lld", &N, &K);
  matrix m;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      scanf("%d", &m.d[i][j]);
  
  m = quick_pow(m, K);

  ll sum = 0;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      sum=(sum+m.d[i][j])%MOD;
  
  printf("%lld", sum);
  return 0;
}