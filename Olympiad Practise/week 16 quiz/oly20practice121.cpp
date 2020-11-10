#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define INF 0x3f3f3f3f            // for int
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

const int MOD = 1000000007, MX = 200000 + 5;

int N;
pi L[MX];
pi R[MX];
int smd[MX];//suffix max difference
int pmd[MX];//prefix max difference
int ans[MX];
int main()
{
  scanf("%d", &N);
  for (int i = 1, x; i <= N+1; i++){
    scanf("%d",&x);
    L[i]={x,i};
  }
  for (int i = 1, x; i <= N; i++){
    scanf("%d", &x);
    R[i]={x,i};
  }

  //I hate off by ones
  sort(L+1, L+N+2);
  sort(R+1, R+N+1);
  for(int i = N+1; i >= 2; i--)
    smd[i] = max(smd[i+1], L[i].f-R[i-1].f);
  for(int i = 1; i <= N+1; i++)
  {
    pmd[i]=max(pmd[i-1], L[i-1].f-R[i-1].f);
    ans[L[i].s]=max(pmd[i], smd[i+1]);
  }

  for (int i = 1; i <= N+1; i++)
    printf("%d ", ans[i]);
  

  return 0;
}