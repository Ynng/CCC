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
#include <stack>
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
#define MAXN 1005

int K, M, N;
int a[MAXN][MAXN];
void solve()
{
  stack<int> p, h;
  memset(a, 0, sizeof a);
  scanf("%d %d", &M, &N);
  char input;
  int answer = 0;
  for (int i = 1; i <= M; i++)
  {
    for (int j = 1, area; j <= N + 1; j++)
    {
      if (j <= N)
      {
        scanf(" %c", &input);
        if (input == 'R')
          a[i][j] = 0;
        else
          a[i][j] = 1 + a[i - 1][j];
      }

      if (j <= N && (p.empty() || a[i][j] > h.top()))
      {
        p.push(j);
        h.push(a[i][j]);
      }
      else if (a[i][j] < h.top())
      {
        int oldestPos;
        while (!p.empty() && a[i][j] < h.top())
        {
          area = (j - p.top()) * h.top();
          if (area > answer)
            answer = area;
          h.pop();
          oldestPos = p.top();
          p.pop();
        }
        if (j <= N)
        {
          p.push(oldestPos);
          h.push(a[i][j]);
        }
      }
    }
  }

  printf("%d\n", 3 * answer);
}

int main()
{
  scanf("%d", &K);
  for (int i = 0; i < K; i++)
    solve();

  return 0;
}