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

const int MOD = 1000000007, MX = 10000000 + 5;



int N;
unordered_map<int, ll> dp;

ll recur(int w){
  if(w<=2)return 1;
    if(dp[w])return dp[w];
  ll sum = 0;
  int lmt = sqrt(w);
  for (int k = 2; k <= lmt; k++)
    sum += recur(w/k);
  

  //Still doesn't 100% get this part
  int last = lmt;
  for (int s = last; s >= 1; s--){
    sum += (w/s - last) * recur(s);
    last = w/s;
  }
  dp[w] = sum;
  return sum;
}

int main()
{
  scanf("%d", &N);
  printf("%lld", recur(N));
  return 0;
}