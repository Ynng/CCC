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

const int MOD = 10007, MX = 100000 + 5;

string s;
int n;
int dp[MX];
int last[26];
int main()
{
  cin >> s;
  n = s.size();
  for (int i = 1; i <= n; i++)
  {
    int id = s[i-1]-'a';
    if(last[id]){
      //TODO: think about how this works
      dp[i]=(2*dp[i-1] - dp[last[id]-1] + MOD)%MOD;
    }else{
      dp[i]=(2*dp[i-1]+1)%MOD;
    }
    last[id] = i;
  }

  printf("%d\n", dp[n]);
  
  return 0;
}