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

const int MOD = 1e9 + 7, MAXN = 100005;

int N, K, R, answer = 0;
bool house[MAXN];
deque<int> dq;
int main()
{
  scanf("%d %d %d", &N, &K, &R);
  for (int i = 1, temp; i <= K; i++)
  {
    scanf("%d", &temp);
    house[temp] = true;
  }

  for (int i = 1; i <= R - 1; i++)
  {
    if (house[i])
      dq.push_back(i);
  }

  for (int i = R; i <= N; i++)
  {
    if (!dq.empty())
      if (dq.front() <= i - R)
        dq.pop_front();
    if (house[i])
      dq.push_back(i);
    if (dq.size() == 1)
    {
      if (house[i])
        dq.push_front(i - 1);
      else
        dq.push_back(i);
      answer++;
    }
    else if (dq.empty())
    {
      dq.push_back(i - 1);
      dq.push_back(i);
      answer+=2;
    }
  }

  printf("%d\n", answer);

  return 0;
}