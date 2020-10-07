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

const int MOD = 1e9+7, MX = 6000 + 5;
int N, Q;
vector<pi> in[MX];
int m[MX];
ll psa[MX];
int main()
{
  scanf("%d", &N);
  
  for(int i = 1,a,b,w; i <= N-1; i++)
  {
    scanf("%d %d %d", &a, &b, &w);
    a++;
    b++;
    in[a].push_back({b,w});
    in[b].push_back({a,w});
  }
  int cur;
  for(int i = 1; i <= N; i++)
  {
    if(in[i].size()==1){
      cur = i;
      break;
    }
  }

  //TODO

  int c = 0;
  while(c==0||in[cur].size()>1){
    c++;
    pi next;
    if(c==1){
      next = in[cur][0];
    }else{
      if(m[in[cur][0].f]!=0)
        next = in[cur][1];
      else
        next = in[cur][0];
    }
    printf("next: %d\n", next.f);
    m[cur]=c;
    m[next.f]=c+1;
    psa[c+1]=next.s + psa[c];
    cur = next.f;
  }
  
  scanf("%d", &Q);
  for(int i = 1,u,v; i <= Q; i++)
  {
    scanf("%d %d", &u, &v);
    u++;
    v++;
    int a = m[u];
    int b = m[v];
    if(a>b){
      int temp = a;
      a = b;
      b = temp;
    }
    printf("%lld\n", psa[b]-psa[a]);
  }
  return 0;
}