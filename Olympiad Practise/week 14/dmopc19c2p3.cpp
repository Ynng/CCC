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

const int MOD = 1e9+7, MX = 300000 + 5;

int N, M;
int A[MX];
int bit[MX][21];

ll query(int r, int g)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[r][g];
    r ^= (r & -r);
  }
  return sum;
}

void update(int dif, int index, int g)
{
  while (index <= N)
  {
    bit[index][g] += dif;
    index += (index & -index);
  }
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++){
    scanf("%d", A+i);
    update(1, i, A[i]);
  }

  for(int i = 1, q,a,b,l,r,c; i <= M; i++)
  {
    scanf("%d", &q);
    if(q==1){
      scanf("%d %d", &a, &b);
      update(-1, a, A[a]);
      A[a] = b;
      update(1, a, A[a]);
    }else{
      scanf("%d %d %d", &l, &r, &c);
      for (int j = 20; j >= 0; j--)
      {
        c-=(query(r,j)-query(l-1,j));
        if(c<=0){
          printf("%d\n", j);
          break;
        }
      }
    }
  }  
  
  return 0;
}