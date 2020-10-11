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

const int MX = 10000 + 5;

ll MOD = 1000000007;

int C,K,T;
ll N;
ll A;
deque<ll> children;
int main()
{
  scanf("%lld %d %d %d", &N, &K, &T, &C);
  A = C;
  children.push_back(0);
  for (int i = 2; i <= N; i++)
  {
    children.push_back((A*K)%MOD);
    if(children.size()>T){
      A+=children.front();
      A%=MOD;
      children.pop_front();
    }
    // printf("A: %lld K:", A);
    // for(ll j : children){
    //   printf("%lld ", j);
    // }
    // printf("\n");
  }
  ll childrenCount = 0;
  while(!children.empty()){
    childrenCount+=children.front();
    children.pop_front();
  }
  printf("%lld\n", (childrenCount + A*2)%MOD);
  // printf("%lld %lld\n", A,childrenCount);
  
  return 0;
}