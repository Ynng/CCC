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

const int MOD = 1e9 + 7, MX = 10005;

int variables;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Returns LCM of array elements
ll findlcm(int arr[], int n)
{
  // Initialize result
  ll ans = arr[0];

  // ans contains LCM of arr[0], ..arr[i]
  // after i'th iteration,
  for (int i = 1; i < n; i++){

    ans = (((arr[i] * ans)) /
           (gcd(arr[i], ans)));
    if (ans < 0)
      printf("LL OVERFOW: %d, %lld\n", i + 1, ans);
  }

  return ans;
}

int main()
{
  int shuf[48] = {30, 19, 4, 3, 20, 41, 9, 23, 18, 7, 15, 8, 26, 34, 45, 29, 39, 6, 1, 13, 22, 16, 2, 42, 40, 0, 33, 17, 32, 46, 27, 5, 24, 36, 47, 11, 25, 31, 28, 43, 12, 38, 35, 44, 21, 37, 14, 10};

  int iter[48];

  for (int i = 0; i < 48; i++)
  {
    int start = i;
    int cur = shuf[start];
    int counter = 1;
    while (true)
    {
      cur = shuf[cur];
      counter++;
      if (cur == start)
        break;
    }
    iter[i] = counter;
    printf("%d, ", counter);
  }

  printf("LCM: %lld", findlcm(iter, 48));

  scanf("%d");
  return 0;
}