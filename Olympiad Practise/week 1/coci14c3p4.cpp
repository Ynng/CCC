#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
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

#define MOD 1000000007
#define MAXN 655

int N;
int a[MAXN][MAXN];
int input[MAXN][MAXN];
pi contestants[500005];

int main()
{
  scanf("%d", &N);
  for (int i = 0, x, y; i < N; i++)
  {
    scanf("%d %d", &x, &y);
    x++;
    y++;
    input[x][y]++;
    contestants[i] = {x, y};
  }

  for (int i = 1; i <= 652; i++)
  {
    for (int j = 1; j <= 652; j++)
    {
      a[i][j] = input[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
    }
  }

  for (int i = 0, h, l; i < N; i++)
  {
    h = 1 + a[652][652] - a[652][contestants[i].s] - a[contestants[i].f][652] + a[contestants[i].f][contestants[i].s];
    l = N - a[contestants[i].f - 1][contestants[i].s - 1];
    if(contestants[i].f==651)l-=input[1][contestants[i].s];
    if(contestants[i].s==651)l-=input[contestants[i].f][1];
    printf("%d %d\n", h, l);
  }

  return 0;
}