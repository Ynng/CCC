//diagonal binary index tree

#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7, MX = 400000 + 5, MN = 2000+5;

int N;
ll bit[MN*2][MN];

ll getSum(int row, int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[row][r];
    r ^= (r & -r);
  }
  return sum;
}

void update(int row, int dif, int index)
{
  while (index <= MN)
  {
    bit[row][index] += dif;
    index += (index & -index);
  }
}

ll sum = 0;
int main()
{
  scanf("%d", &N);
  for(int i = 1, cmd; i <= N; i++)
  {
    scanf("%d", &cmd);
    int t,r,c, x;
    if(cmd == 1){
      scanf("%d %d %d", &r, &c, &t);
      update(r+c, t, r);
    }else{
      scanf("%d %d %d", &r, &c, &x);
      sum = (sum + getSum(r+c, r) - getSum(r+c, r-x-1) + MOD) % MOD;
    }
  }
  printf("%lld\n", sum);
  
  
  return 0;
}