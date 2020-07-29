#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

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

const int MOD = 1e9 + 7, MX = 30;

int N, Q;
char arr[MX][MX];
bool used[MX][MX];

char str[100];
int len;

#define CHECK                             \
  if (arr[i][j] == str[x] && !used[i][j]) \
  {                                       \
    if (recur(i, j, x + 1))               \
    {                                     \
      used[orii][orij] = false;           \
      return true;                        \
    }                                     \
  }

bool recur(int i, int j, int x)
{
  if (x == len)
    return true;
  int orii = i, orij = j;
  used[orii][orij] = true;

  i--;
  j--;
  CHECK
  j++;
  CHECK
  j++;
  CHECK
  i++;
  CHECK
  i++;
  CHECK
  j--;
  CHECK
  j--;
  CHECK
  i--;
  CHECK

  used[orii][orij] = false;
  return false;
}

int main()
{
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      scanf(" %c", &arr[i][j]);

  // for (int i = 1; i <= N; i++)
  // {

  //   for (int j = 1; j <= N; j++)
  //     printf("%c ", arr[i][j]);
  //   printf("\n");
  // }

  for (int i = 1; i <= Q; i++)
  {
    memset(str, 0, sizeof(str));
    scanf(" %s", str);
    len = strlen(str);
    bool answer = false;

    for (int j = 1; j <= N; j++)
    {
      for (int k = 1; k <= N; k++)
      {
        if (arr[j][k] == str[0])
          if (recur(j, k, 1))
            answer = true;
        if (answer)
          break;
      }
      if (answer)
        break;
    }

    if (answer)
      printf("good puzzle!\n");
    else
      printf("bad puzzle!\n");
  }
  return 0;
}