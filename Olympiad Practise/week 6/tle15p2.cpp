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

const int MOD = 1e9 + 7, MN = 100 + 5, MM = 100000 + 5;

int N, M, T;
pi people[MM];

ll microwave[MN];

int main()
{
  ll answer = -1;
  scanf("%d %d %d", &N, &M, &T);
  for (int i = 1, t, f; i <= M; i++)
  {
    scanf("%d %d", &t, &f);
    people[i] = {t, f};
  }
  sort(people + 1, people + M + 1);

  for (int i = 1, t, f; i <= M; i++)
  {
    ll mx = -1, mxPos;
    ll mi = -1, miPos;
    for (int j = 1; j <= N; j++)
    {
      if (microwave[j] <= people[i].first)
      {
        if (microwave[j] > mx)
        {
          mx = microwave[j];
          mxPos = j;
        }
      }
      else if (microwave[j] < mi || mi == -1)
      {
        mi = microwave[j];
        miPos = j;
      }
    }
    if (mx == -1)
      microwave[miPos] = mi + people[i].second;
    else
    {
      if ((people[i].first - mx) >= T && (answer == -1 || mx < answer))
      {
        answer = mx;
      }
      microwave[mxPos] = people[i].first + people[i].second;
    }
  }

  ll mi = microwave[1];
  for (int i = 2; i <= N; i++)
  {
    if (microwave[i] < mi)
      mi = microwave[i];
  }
  if (answer == -1)
    answer = mi + 1;

  printf("%lld\n", min(mi, answer));
  return 0;
}