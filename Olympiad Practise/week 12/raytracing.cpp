#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt"
//fancy compiler stuffs that makes the program run so much faster???
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

const int MOD = 1e9 + 7, MX = 8192 + 5;

int N, Q;
int H[MX];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%d", H + i);
  }
  scanf("%d", &Q);
  int i,j,a,b,h,c;
  int cnt, rng;
  while(Q--)
  {
    scanf("%d", &c);
    if(c==1){
      scanf("%d %d %d %d", &i, &j, &a, &b);
      cnt = 0, rng = b - a;
      while(i<=j)cnt+=(unsigned)(H[i++]-a)<=rng;
      printf("%d\n", cnt);
    }else{
      scanf("%d", &i);
      scanf(" %d", H+i);
    }
  }

  return 0;
}