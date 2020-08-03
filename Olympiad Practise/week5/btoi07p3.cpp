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

const int MOD = 1e9 + 7, MX = 10000 + 5;

int N, M, C;
deque<pi> mx, mi;
int counter = 0;
int main()
{
  scanf("%d %d %d", &N, &M, &C);
  for (int i = 1, cur; i <= N; i++)
  {
    scanf(" %d", &cur);
    while (!mx.empty() && mx.back().first < cur)
      mx.pop_back();
    mx.push_back({cur, i});
    if (mx.front().second < i + 1 - M)
      mx.pop_front();
    while (!mi.empty() && mi.back().first > cur)
      mi.pop_back();
    mi.push_back({cur, i});
    if (mi.front().second < i + 1 - M)
      mi.pop_front();

    if (i >= M && (mx.front().first - mi.front().first) <= C)
    {
      counter++;
      printf("%d\n", i - M + 1);
    }
  }

  if (counter == 0)
    printf("NONE\n");

  return 0;
}