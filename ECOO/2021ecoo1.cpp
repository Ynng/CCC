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

int start, interval, sent;
int main()
{
  scanf("%d %d %d", &start, &interval, &sent);
  if(sent <= start + interval){
    printf("%d", start + interval);
  }else if(sent <= start + 2*interval){
    printf("%d", start + 2*interval);
  }else if(sent <= start + 3*interval){
    printf("%d", start + 3*interval);
  }else{
    printf("Who knows...\n");
  }
  
  
  return 0;
}