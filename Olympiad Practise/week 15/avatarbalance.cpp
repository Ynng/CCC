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

const int MOD = 1e9+7, MX = 10 + 5;

int N;
int a[MX];
int sum;

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
  scanf("%d", &N);
  for(int i = 0, temp; i < N; i++){
    scanf("%d", a+i);
    sum+=a[i];
  }
  double half = (double)sum/2;
  double dif = INF;
  int bestSum;
  int limit = powll(2,N);
  for (int i = 0; i < limit; i++)
  {
    int curSum = 0;
    for (int j = 0; j < N; j++)
    {
      int mask = 1<<j;
      if(i&mask)
        curSum+=a[j];
    }
    if(abs(curSum - half) < dif){
      dif = abs(curSum - half);
      bestSum = curSum;
    }
  }
  

  printf("%d\n", abs(sum-bestSum - bestSum));
  
  return 0;
}