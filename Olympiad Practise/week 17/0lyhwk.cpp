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

const int MOD = 1000000007, MX = 100 + 5;

int N, M, T;
int W[MX];
double V[MX];
double dp[8640+5];
int alreadySatisfied;
int main()
{
  scanf("%d %d %d", &N , &M, &T);
  for(int i = 1; i <= N; i++)
    scanf("%d", W+i);
  for(int i = 1, A; i <= M; i++){
    scanf("%d", &A);
    if(A==0){
      alreadySatisfied++;
      continue;
    }
    double inc = 1.0/A;
    for(int j = 1, temp; j <= A; j++)
    {
      scanf("%d", &temp);
      V[temp]+=inc;
    }
  }

  for(int i = 1; i <= N; i++){
    for (int j = T; j >= W[i]; j--)
      dp[j] = max(dp[j], dp[j-W[i]]+V[i]);
  }
  
  //remember max_element returns a pointer, not the value
  printf("%.2f", *max_element(dp+1, dp+T+1)+alreadySatisfied);  

  return 0;
}