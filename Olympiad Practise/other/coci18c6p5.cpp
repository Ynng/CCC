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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

#define MOD 1000000007
#define MAXN 10005

int R, S, N;
int a[305][305];
multiset<int> s[305][305];

#define C s[i][j]
#define CV a[i][j]
int main()
{
  scanf("%d %d %d", &R, &S, &N);
  for (int i = 1; i <= R; i++)
  {
    for (int j = 1; j <= S; j++)
    {
      scanf("%d", a[i] + j);

      if(i==1 && j == 1)
      C.insert(CV);
      // C.find()
    }
  }



  return 0;
}