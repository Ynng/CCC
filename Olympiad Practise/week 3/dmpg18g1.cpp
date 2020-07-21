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

const int MOD = 1e9 + 7, MAXN = 1000005;

int N, K;
stack<int> s;
bool chair[MAXN];
int student[MAXN];

int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 1, temp; i <= K; i++)
  {
    scanf("%d", &temp);
    chair[temp] = true;
  }
  for (int i = 1, temp; i <= K + 1; i++)
  {
    scanf("%d", &temp);
    student[temp] = i;
  }

  int chairCount = K;
  int i = 0;
  while (chairCount > 0 || s.empty())
  {
    i++;
    if (i > N)
      i -= N;
    if (student[i] != 0)
    {
      s.push(student[i]);
      student[i] = 0;
    }
    if (chair[i] && !s.empty())
    {
      chair[i] = false;
      chairCount--;
      s.pop();
    }
  }

  printf("%d", s.top());

  return 0;
}