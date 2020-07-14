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
#include <list>
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
#define MAXN 105

int N;
list<double> stream;
list<double>::iterator it;
int main()
{
  scanf("%d", &N);
  for (int i = 0, temp; i < N; i++)
  {
    scanf("%d", &temp);
    stream.push_back(temp);
  }

  int input;
  int split;
  int percent;
  int merge;
  double sum;
  while (true)
  {
    it = stream.begin();
    scanf("%d", &input);
    if (input == 77)
      break;
    if (input == 99)
    {
      scanf("%d", &split);
      scanf("%d", &percent);
      split--;
      advance(it, split);
      stream.insert(it, *it * (0.01 * percent));
      stream.insert(it, *it * (0.01 * (100 - percent)));
      stream.erase(it);
    }
    if (input == 88)
    {
      scanf("%d", &merge);
      merge--;
      advance(it, merge);
      sum = *it + *(++it);
      it--;
      stream.insert(it, sum);
      it = stream.erase(it);
      stream.erase(it);
    }
  }


  for (it = stream.begin(); it != stream.end(); it++)
    printf("%d ", (int)round(*it));

  return 0;
}