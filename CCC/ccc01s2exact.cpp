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
#define sz(st) (int)(st).size()
#define ms(st, ed) memset(st, ed, sizeof(st))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(st) st.begin(), st.end()
#define ins insert

const int MOD = 1000000007, MX = 20 + 5;

int T, st, ed;
pi shift[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int output[MX][MX];

int numberLength(int n)
{
  int length = n>0;
  while (n /= 10)
    length++;
  return length;
}

void solve()
{
  memset(output, 0, sizeof(shift));
  scanf("%d %d", &st, &ed);

  int length = 0;
  int direction = 0;

  int row = 10, col = 10;
  int b = row, t = row;
  int l = col, r = col;
  int cur = st + 1;
  output[row][col] = st;

  while (cur <= ed)
  {
    direction = (direction + 1) % 4;
    if (direction % 2)
      length++;

    for (int j = 0; j < length && cur <= ed; j++)
    {
      row += shift[direction].f;
      col += shift[direction].s;
      output[row][col] = cur;
      output[0][col] = max(output[0][col], numberLength(cur));
      b = min(row, b); t = max(row, t); l = min(col, l); r = max(col, r);
      cur++;
    }
  }

  for (int i = b; i <= t; i++)
  {
    for (int j = l; j <= r; j++)
    {
      cur = output[i][j];
      for (int k = numberLength(cur); k < output[0][j]; k++)
        printf(" ");
      if(cur)printf("%d", cur);
      if(j!=r)printf(" ");
    }
    printf("\n");
  }
}

int main()
{
  scanf("%d", &T);
  while(T--){
    solve();
    if(T)printf("\n");
  }
  return 0;
}