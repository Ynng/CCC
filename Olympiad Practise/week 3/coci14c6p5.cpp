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
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
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

const int MOD = 1e9 + 7, MX = 1005;

int R, S, m[MX][MX], m2[MX][MX];
stack<int> p, h;

int main()
{

  scanf("%d %d", &R, &S);
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= S; j++)
      scanf("%d", &m[i][j]);

  int answer = 0;
  for (int i = 1; i <= R - 1; i++)
  {
    for (int j = 1; j <= S; j++)
    {
      if (j <= S - 1 && m[i + 1][j + 1] + m[i][j] <= m[i + 1][j] + m[i][j + 1])
        m2[i][j] = m2[i-1][j] + 1;

      if (j <= S && (p.empty() || m2[i][j] > h.top()))
      {
        p.push(j);
        h.push(m2[i][j]);
      }
      else if (m2[i][j] < h.top())
      {
        int oldestPos, area;
        while (!p.empty() && m2[i][j] < h.top())
        {
          area = ((j - p.top()) + 1) * (h.top() + 1);
          if (area > answer)
            answer = area;
          h.pop();
          oldestPos = p.top();
          p.pop();
        }
        if (j <= S)
        {
          p.push(oldestPos);
          h.push(m2[i][j]);
        }
      }
    }
  }

  printf("%d", answer);

  return 0;
}