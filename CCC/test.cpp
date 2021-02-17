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

const int MOD = 1000000007, MX = 10000 + 5;

pi bit[MX];
int subway[MX];
int subwayR[MX];

pi queryMin(int r)
{
  pi mi = {MX+10, 0};
  while (r > 0)
  {
    mi=min(bit[r],mi);
    r ^= (r & -r);
  }
  return mi;
}

void update(int val, int idx)
{
  int oriIdx = idx;
  while (idx <= MX-4)
  {
    if(bit[idx].s == oriIdx){
      if(val > bit[idx].f){
        //find replacement
        int repIdx = idx - (idx & -idx)/2;
        bit[idx] = {val,oriIdx};
        pi rep = bit[repIdx];
        if(rep.f < val)bit[idx]=rep;
      }else{
        bit[idx] = {val,oriIdx};
      }
    }else{
      if(val < bit[idx].f || bit[idx].f==0){
        bit[idx] = {val,oriIdx};
      }
    }
    idx += (idx & -idx);
  }
}

int main()
{
  while(true){
    int val, idx;
    scanf("%d %d", &val, &idx);
    update(val, idx);
    printf("\n");
    for (int i = 1; i < 10; i++)
    {
      printf("%d ", bit[i]);
    }
    printf("\n");
  }
  
  
  return 0;
}