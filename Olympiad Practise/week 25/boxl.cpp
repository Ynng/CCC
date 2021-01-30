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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 200000 + 5;

int N, M, ans, bit[3*MX], cnt;

struct event{int x, yl, yh, val;};
bool cmp(event a, event b){
  if(a.x!=b.x)return a.x < b.x;
  else return a.val > b.val;
}

vector<event> events;
map<int,int> mp;

//BIT
//Binary indexed tree sum
int query(int r)
{
  int sum = 0;
  while (r > 0)
  {
    sum += bit[r];
    r ^= (r & -r);
  }
  return sum;
}

void update(int index, int dif)
{
  while (index <= cnt)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 1, r1, c1, r2, c2; i <= N; i++)
  {
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    if(r1 <= r2 && c1 <= c2){
      events.push_back({r1,c1,c2,1});
      events.push_back({r2,c1,c2,-1});
      mp[c1]=0;
      mp[c2]=0;
    }
  }

  for (int i = 1,x,y; i <= M; i++)
  {
    scanf("%d %d", &x, &y);
    events.push_back({x,y,y,0});
    mp[y]=0;
  }
  
  //Coordinate compression
  for(auto& e:mp)e.second = ++cnt;
  sort(events.begin(), events.end(), cmp);
  for(event e: events){
    if(e.val != 0){
      int lo = mp[e.yl], hi = mp[e.yh];
      update(lo, e.val); update(hi+1, -e.val);
    }else{
      if(query(mp[e.yl])) ans++;
    }
  }
  
  printf("%d\n", ans);

  return 0;
}