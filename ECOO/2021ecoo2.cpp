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

const int MOD = 1000000007, MX = 100000 + 5;

char str[MX];
int len;
int main()
{
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len-1; i++)
  {
    printf("%c", str[i]);
    if(str[i]=='A'){
      if(str[i+1]=='A')
        printf(" ");
    }else{
      if(str[i+1]!='A')
        printf(" ");
    }
  }
  printf("%c", str[len-1]);
  
  
  return 0;
}