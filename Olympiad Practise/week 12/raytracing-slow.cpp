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

const int MOD = 1e9 + 7, MX = 8192 + 5;

int N, Q;
int H[MX];
short bit[MX][MX];
//2d binary indexed tree (int)(short)
//ask about this question
int query(int x, int y)
{
  int val = 0;
  for (int yi = y; yi > 0; yi -= (yi & -yi))
    for (int xi = x; xi > 0; xi -= (xi & -xi))
      val += bit[xi][yi];
  return val;
}

void update(int x, int y, short diff)
{
  for (int yi = y; yi <= MX; yi += (yi & -yi))
    for (int xi = x; xi <= MX; xi += (xi & -xi))
      bit[xi][yi] += diff;
}

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++){
    scanf("%d", H + i);
    H[i]++;
    update(i, H[i], 1);
  }
  // for (int i = N; i > 0; i--){
  //   for (int j = 1; j <= N; j++){
  //     printf("%lld ", query(j, i) - query(j-1,i) - query(j,i-1) + query(j-1,i-1));
  //   }
  //   printf("\n");
  // }


  scanf("%d", &Q);
  for (int q = 1, c; q <= Q; q++)
  {
    scanf("%d", &c);
    if(c==1){
      int i,j,a,b;
      scanf("%d %d %d %d", &i, &j, &a, &b);
      i++;
      j++;
      a++;
      b++;
      printf("%d\n", query(j, b) - query(i-1,b) - query(j,a-1) + query(i-1,a-1));
    }else{
      int i,h;
      scanf("%d %d", &i, &h);
      i++;
      h++;
      update(i, H[i], -1);
      H[i] = h;
      update(i, H[i], 1);
    }
  }

  return 0;
}