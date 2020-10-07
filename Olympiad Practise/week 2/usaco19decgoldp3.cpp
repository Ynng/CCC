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
#define MAXN 100005

int N, M, K, dp[MAXN], psa[MAXN][30], best[MAXN][30];
char c[MAXN];
int dis[30][30];
int main()
{
  scanf("%d %d %d", &N, &M, &K);

  for (int i = 1; i <= N; i++)
    scanf(" %c", c + i);

  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      scanf(" %d", dis[i] + j);

  //Dijkstra on a loop to find?
  //floyd warshall
  //shortest point between all nodes
  //shortest point between all points
  //graph theory
  for (int k = 0; k < M; k++)
    //middle "transfer" node
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++)
        if (dis[i][j] > dis[i][k] + dis[k][j])
          dis[i][j] = dis[i][k] + dis[k][j];

  for (int i = 1; i <= N; i++)
    for (int j = 0; j < M; j++)
      psa[i][j] = dis[c[i] - 'a'][j] + psa[i - 1][j];

  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = K; i <= N; i++)
  {
    for (int p = 0; p < M; p++)
      //think about this part some more
      dp[i] = min(dp[i], best[i - K][p] + psa[i][p]);
    for (int p = 0; p < M; p++)
      best[i][p] = min(best[i - 1][p], dp[i] - psa[i][p]);
  }

  printf("%d", dp[N]);
  return 0;
}