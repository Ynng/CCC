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

const int MOD = 1e9+7, MX = 5000 + 5;

int K, N;
pi S[MX];
int A[MX];

//Longest increasing subsequence (includes equal numbers)
int LIS(){
  int dp[MX];
  int ans = 0;
  for (int i = 1; i <= N; i++)
  {
    if(A[i]>=dp[ans])dp[++ans]=A[i];
    else dp[upper_bound(dp+1, dp+ans+1, A[i])-dp] = A[i];
  }
  return ans;
}

int main()
{
  scanf("%d %d", &N, &K);
  for(int i = 1, v; i <= N; i++){
    scanf("%d", &v); S[i] = {v,i};
  }
  sort(S+1, S+1+N);
  for(int i = 1; i <= N; i++)
    A[S[i].s]=((i-1)/K)+1;
  printf("\n%d\n", N-LIS());
  return 0;
}