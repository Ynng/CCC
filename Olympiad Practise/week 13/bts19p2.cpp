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

const int MOD = 1e9 + 7, MX = 10000 + 5;

int X, Y, H, V, T;
int main()
{
  scanf("%d %d %d %d %d", &X, &Y, &H, &V, &T);
  bool found = false;
  int mx, mi;
  int tx, ty;
  for (int i = X; i < X + H; i++)
  {
    int temp = min(Y + V -1, 2*i);
    for (int j = max(Y, (i+1)/2); j <= temp; j++)
      if ((i + j) % 3 == 0)
      {
        tx = i;
        ty = j;
        found = true;
        break;
      }
    if(found)break;
  }
  if(tx==0){
    printf("NO\n");
    return 0;
  }
  if((tx+ty)/3>=T){
    printf("NO\n");
    return 0;
  }

  printf("YES\n");

  return 0;
}