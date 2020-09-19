#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7, MX = 100000  + 5, MXL = 3000+5;

int N;
struct building{
  int l;
  int w;
  int h;
  ll p;
  int id;
};
bool bsorter(building const &a, building const &b)
{
  if (a.l != b.l)
    return a.l < b.l;
  if (a.w != b.w)
    return a.w < b.w;
  if (a.h != b.h)
    return a.h < b.h;
  return a.p < b.p;
}
building b[MX];
ll bit[MXL][MXL];
int biti[MXL][MXL];
ll a[MXL][MXL];
ll dp[MX];
int link[MX];

pli getMax(int x, int y)
{
  ll mx = 0;
  int id = 0;
  int origX = x;
  while(y > 0){
    x = origX;
    while (x > 0)
    {
      if(bit[x][y] > mx){
        mx = bit[x][y];
        id = biti[x][y];
      }
      x -= (x & -x);
    }
    y -= (y & -y);
  }
  return {mx, id};
}

void update(int x, int y, ll target, int id){
  int origX = x;
  while(y <= MXL){
    x = origX;
    while (x <= MXL)
    {
      if(target > bit[x][y]){
        bit[x][y] = target;
        biti[x][y] = id;
      }
      x += (x & -x);
    }
    y += (y & -y);
  }
}


int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    int l, w, h;
    ll p;
    scanf("%d %d %d %lld", &l, &w , &h, &p);
    //Li <= Lj, Wi <= Wj, Hi <= Hj
    //Dp state: dp[i] = maximum people u can house
    //dp[i] = max(dp[j] + p[i]);
    //j is 0...i-1
    if(l>w){
      l+=w;
      w = l-w;
      l-=w;
    }
    building temp = {l,w,h,p,i};
    b[i] = temp;
  }

  sort(b+1, b+N+1, bsorter);

  //   for(int i = 1; i <= N; i++)
  // {
  //   printf("%d %d %d %d %lld\n", b[i].l, b[i].w, b[i].h, b[i].id, b[i].p);
  // }

  ll mx = 0;
  int startId;

  for(int i = 1; i <= N; i++)
  {
    pli qresult = getMax(b[i].w, b[i].h);
    ll val = qresult.f + b[i].p;
    if(val > mx){
      mx = val;
      startId = b[i].id;
    }
    update(b[i].w, b[i].h, val, b[i].id);
    link[b[i].id] = qresult.s;
    a[b[i].w][b[i].h] = val;
  }

  printf("%lld\n", mx);
  int i = 1;
  int output[MX];
  output[0] = startId;
  while(link[startId]!=0){
    startId = link[startId];
    output[i] = startId;
    i++;
  }
  printf("%d\n", i);
  for (int j = 0; j < i; j++)
  {
    printf("%d ", output[j]);
  }

  //sort by L, if L same use W, etc.
  //Current block j;
  //find out max do[i] from range (1,1) to (Wj, Hj)
  
  
  return 0;
}