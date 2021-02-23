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
int sizes[3];
int arr[4];
int main()
{
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    if (str[i] == 'L')
      str[i] = 0;
    if (str[i] == 'M')
      str[i] = 1;
    if (str[i] == 'S')
      str[i] = 2;

    sizes[str[i]]++;
  }


  for (int i = 0; i <= len; i++)
  {
    if (i < sizes[0])
    {
      if (str[i] == 1)
        arr[0]++;
      if (str[i] == 2)
        arr[1]++;
    }
    else if (i < sizes[0] + sizes[1])
    {
      if (str[i] == 2)
        arr[2]++;
    }
    else
    {
      if (str[i] == 1)
        arr[3]++;
    }
  }

  #ifdef DEBUG
  printf("%d %d %d\n", sizes[0], sizes[1], sizes[2]);
  printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
  #endif

  printf("%d\n", arr[0] + arr[1] + arr[2] + arr[3] - min(arr[2], arr[3]));
  return 0;
}