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

int N, K;
int arr[MAXN];
multiset<int> s;
deque<int> smol, big;

int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", arr + i);
  }

  ll answer = 0;

  for (int i = 1, l = 0; i <= N; i++)
  {
    while (!smol.empty() && arr[i] < arr[smol.back()])
      smol.pop_back();
    while (!big.empty() && arr[i] > arr[big.back()])
      big.pop_back();
    smol.pb(i);
    big.pb(i);

    while (arr[big.front()] > arr[smol.front()] + K)
    {
      l++;
      if (smol.front() <= l)
        smol.pop_front();
      if (big.front() <= l)
        big.pop_front();
    }
    answer += i - l;
  }

  printf("%lld", answer);

  return 0;
}