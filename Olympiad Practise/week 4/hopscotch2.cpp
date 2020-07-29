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

const int MOD = 1e9 + 7, MX = (1 << 23) + 5;

struct rock{
  ll temp;
  ll i;
};

int N, K;
ll temp;
deque<rock> dq;
ll pre[MX], path[MX];
int main()
{
  scanf("%d %d", &N, &K);
  dq.push_back({0, 0});
  pre[0]=-1;
  for (int i = 1; i <= N; i++)
  {
    scanf("%lld", &temp);
    ll ans = temp + dq.front().temp;
    pre[i] = dq.front().i;
    while (!dq.empty() && dq.back().temp >= ans)
      dq.pop_back();
    dq.push_back({ans, i});
    if (dq.front().i < i - K + 1)
      dq.pop_front();
  }
  
  ll cur = dq.front().i;
  
  int i = -1;
  while(cur != 0){
    i++;
    path[i] = cur;
    cur = pre[cur];
  }

  printf("%lld\n", dq.front().temp);

  while(i >= 0){
    printf("%lld ", path[i]);
    i--;
  }
  return 0;
}