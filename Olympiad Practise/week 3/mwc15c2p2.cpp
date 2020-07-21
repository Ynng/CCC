#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <stack>
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

const int MOD = 1e9 + 7, MAXN = 1e6 + 5;

int N;
stack<int> t, p;
int main()
{
  scanf("%d", &N);
  t.push(MAXN);
  p.push(1);

  for (int i = 1, h; i <= N; i++)
  {
    scanf("%d", &h);

    while (t.top() <= h && !t.empty())
    {
      t.pop();
      p.pop();
    }
    printf("%d ", i - p.top());
    t.push(h);
    p.push(i);
  }

  return 0;
}