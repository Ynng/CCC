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
#define MAXN 1414220

int N, Q;
int houses[MAXN];
int main()
{
  scanf("%d %d", &N, &Q);
  for (ll i = 0, x, y; i < N; i++)
  {
    scanf("%lld %lld", &x, &y);
    houses[(int)ceil(sqrt(x * x + y * y))]++;
  }

  for (int i = 1; i < MAXN; i++)
    houses[i] += houses[i - 1];

  for (int i = 0, temp; i < Q; i++)
  {
    scanf("%d", &temp);
    printf("%d\n", houses[temp]);
  }
  

  return 0;
}