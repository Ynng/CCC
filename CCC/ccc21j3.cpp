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

char str[6];
bool l;
int main()
{
  while (true)
  {
    scanf("%s", str);
    bool end = true;
    for (int i = 0; i < 5; i++)
    {
      if (str[i] != '9')
      {
        end = false;
        break;
      }
    }
    if (end)
      break;

    int sum = str[0] + str[1] - 2 * '0';
    if (sum % 2)
      l = true;
    else if (sum != 0)
      l = false;
    if (l)
      printf("left ");
    else
      printf("right ");
    printf("%s\n", str + 2);
  }

  return 0;
}