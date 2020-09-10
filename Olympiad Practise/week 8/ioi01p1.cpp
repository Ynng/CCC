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

const int MOD = 1e9+7, MX = 1024 + 5;

int S, instruct;
uint32_t bit[MX][MX];

ll getSum(int x, int y)
{
  ll sum = 0;
  int origX = x;
  while(y > 0){
    x = origX;
    while (x > 0)
    {
      sum += bit[x][y];
      x -= (x & -x);
    }
    y -= (y & -y);
  }
  return sum;
}

void update(int x, int y, int diff){
  int origX = x;
  while(y <= S){
    x = origX;
    while (x <= S)
    {
      bit[x][y] += diff;
      x += (x & -x);
    }
    y += (y & -y);
  }
}

int main()
{
  scanf("%d %d", &instruct, &S);

  while(true){
    scanf("%d ", &instruct);
    switch(instruct){
      case 1:
        int x, y, a;
        scanf("%d %d %d", &x, &y, &a);
        update(x+1,y+1,a);
        break;
      case 2:
        int l, b, r, t;
        scanf("%d %d %d %d", &l, &b, &r, &t);
        printf("%lld\n", getSum(r+1, t+1) - getSum(r+1, b) - getSum(l, t+1) + getSum(l,b));
        break;
      case 3:
        return 0;
    }
  }
  
  
  return 0;
}