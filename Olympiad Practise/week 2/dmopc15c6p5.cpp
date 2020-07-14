#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
#define MAXN 3000005
// #define DEBUG

ll N, K;
ll arr[MAXN];
ll ansr = 0;
multiset<ll> s;

#define ARR(i) (arr[i] * N + (N - i))
#define POS(i) (N - ((i) % N))
void removeBefore(int last, int l)
{
  for (int i = last + 1; i <= l; i++)
    s.erase(s.find(ARR(i)));
}

void prints()
{
  printf("Set: ");
  for (multiset<ll>::iterator it = s.begin(); it != s.end(); ++it)
    printf("%lld|%lld, ", POS(*it), *it / N);
  printf("\n");
}

int main()
{
  scanf("%lld %lld", &N, &K);
  for (int i = 1; i <= N; i++)
  {
    scanf("%lld", arr + i);
  }

  ansr = 1;

  s.insert(ARR(1));

  ll l = 0, last = 0;
  for (ll i = 2; i <= N; i++)
  {

    while (s.size() > 0 && *s.begin() / N < arr[i] - K)
    {
      l = POS(*s.begin());
      // l = POS(*s.lower_bound((arr[i] - K) * N + N));
      removeBefore(last, l);
      last = l;
    }

    while (s.size() > 0 && *(--s.end()) / N > arr[i] + K)
    {
      l = POS(*(--s.end()));
      // l = POS(*s.upper_bound((arr[i] + K) * N - 1));
      removeBefore(last, l);
      last = l;
    }

    s.insert(ARR(i));
    ansr += i - l;

    #ifdef DEBUG
    prints();
    printf("sum: %lld ", ansr);
    #endif

  }
  scanf("%lld %lld", &N, &K);

  printf("%lld", ansr);

  return 0;
}