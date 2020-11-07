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

const int MOD = 1000000007, MX = 1000000 + 5;

//disjoint set
int N, Q;
int P[MX];
int Size[MX];
ll Val[MX];
stack<int> q;

int find(int i){
  while(P[i]!=0)
    i = P[i];
  return i;
}

int main()
{
  scanf("%d %d", &N, &Q);
  for(int i = 1; i <= N; i++)
    scanf("%d", Val+i);
  for(int i = 1, cmd, a, b; i <= Q; i++)
  {
    scanf("%d", &cmd);
    if(cmd == 1){
      scanf("%d %d", &a, &b);
      int fa = find(a);
      int fb = find(b);
      if(fa!=fb){
        if(Size[fa] > Size[fb])swap(fa, fb);
        P[fa] = fb;
        Size[fb]+=Size[fa]+1;
        Val[fb]+= Val[fa];
      }
    }else if(cmd == 2){
      scanf("%d", &a);
      printf("%d\n", Size[find(a)]+1);
    }else if(cmd == 3){
      scanf("%d", &a);
      printf("%lld\n", Val[find(a)]);
    }
  }
  
  return 0;
}