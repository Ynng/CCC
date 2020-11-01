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

const ull MOD = 1000000007;

ull N;

//matrix
struct matrix {
  ull d[2][2];
  matrix(){memset (d,0,sizeof(d));}
};

//matrix multiplication
matrix multi(matrix a, matrix b){
  matrix ans;
  for (int i = 0; i < 2; i++)
    for (int k = 0; k < 2; k++)
      for (int j = 0; j < 2; j++)
        ans.d[i][j] = (ans.d[i][j] + a.d[i][k]*b.d[k][j])%MOD;
  return ans;
}

//matrix power
matrix quick_pow(matrix x, ull exp){
  matrix ans;
  //generating identity matrix 
  for(int i = 0; i<2; i++)ans.d[i][i]=1;
  while(exp>0){
    if(exp%2!=0)ans = multi(ans,x);
    x=multi(x,x);
    exp/=2;
  }
  return ans;
}

int main()
{
  scanf("%llu", &N);

  matrix m;
  m.d[0][1]=1;
  m.d[1][0]=1;
  m.d[1][1]=1;
  m = quick_pow(m, N);

  matrix start;
  start.d[1][0]=1;

  matrix end; 
  end = multi(m,start);

  printf("%llu\n", end.d[0][0]);
  
  return 0;
}