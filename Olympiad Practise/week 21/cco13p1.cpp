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

const int MOD = 1000000007;

int X;
vector<int> ans;

bool check(int x,int b){
  vector<int> a;
  while(x!=0){
    a.push_back(x%b);
    x/=b;
  }
  for (int l = 0, r = a.size() - 1; l < r; l++, r--)
    if(a[l]!=a[r])return false;
  return true;  
}

int main()
{
  scanf("%d", &X);
  int b = 0;
  for (b = 2; b*b <= X; b++)
    if(check(X,b))
      ans.push_back(b);
  while(b*b+b >= X)b--;
  for(;b>=1;b--)
    if(X%b==0)
      ans.push_back(X/b-1);

  for(int v : ans)
    printf("%d\n", v);
  return 0;
}