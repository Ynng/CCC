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

const int MOD = 1000000007, MX = 1000 + 5;

int N, x[MX], y[MX];
char dir[MX];
bool stop[MX];
int blame[MX];

struct inter{
  int a,b,x,y;
};

bool compareInter(inter a, inter b)
{
  if(a.x != b.x)return a.x < b.x;
  return a.y < b.y;
}

vector<inter> interList;

int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
    scanf(" %c %d %d", dir+i, x+i, y+i);
  
  for(int i = 1; i <= N; i++)
  {
    for(int j = i+1; j <= N; j++)
    {
      if(dir[i] == dir[j])continue;
      int ex = x[i], ey = y[i], nx = x[i], ny = y[i];
      if(dir[i] == 'E'){nx = x[j]; ny = y[j];}
      else{ex = x[j]; ey = y[j];}

      if(ex < nx && ey > ny) interList.push_back({i, j, max(ex, nx), max(ey, ny)});
    }
  }  
  
  sort(interList.begin(), interList.end(), compareInter);

  for(inter e : interList){
    int ta = e.x - x[e.a] + e.y - y[e.a];
    int tb = e.x - x[e.b] + e.y - y[e.b];
    if(ta == tb || stop[e.a] || stop[e.b])continue;
    if(ta < tb){stop[e.b] = true; blame[e.a] += blame[e.b] + 1; }
    else if(ta > tb){ stop[e.a] = true; blame[e.b] += blame[e.a] +1; }
  }

  for(int i = 1; i <= N; i++)
  {
    printf("%d\n", blame[i]);
  }

  return 0;
}