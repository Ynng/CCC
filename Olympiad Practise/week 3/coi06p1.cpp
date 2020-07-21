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

const int MOD = 1e9 + 7, MAXN = 500005;

int N;
ll answer = 0;
stack<pl> s;
int main()
{
  scanf("%d", &N);
  ll h;
  for (int i = 1; i <= N; i++)
  {
    int count = 1;
    scanf("%lld", &h);

    while (!s.empty())
    {
      if (h < s.top().f)
      {
        answer++;
        break;
      }
      else if (h == s.top().f)
      {
        answer += s.top().s;
        count = 1 + s.top().s;
        s.pop();
      }
      else if (h > s.top().f)
      {
        answer += s.top().s;
        s.pop();
      }
    }
    s.push({h, count});
  }

  printf("%lld", answer);

  return 0;
}