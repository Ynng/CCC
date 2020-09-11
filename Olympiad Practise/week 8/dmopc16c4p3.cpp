#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
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

const int MOD = 1e9 + 7, MX = 100000 + 5;

int N, S, Q;
int dist[MX];
int stand[MX];
set<pi> closest[105];
set<int> apples[MX];
int main()
{
  scanf("%d %d", &N, &S);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", dist + i);
  }
  for (int i = 1, s, a; i <= S; i++)
  {
    scanf("%d %d", &s, &a);
    closest[a].insert({dist[s], s});
    apples[s].insert(a);
  }

  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++)
  {
    char qtype;
    int x, k;
    scanf(" %c", &qtype);
    switch (qtype)
    {
    case 'A':
      scanf("%d %d", &x, &k);
      closest[k].insert({dist[x], x});
      apples[x].insert(k);
      break;
    case 'S':
      scanf("%d %d", &x, &k);
      closest[k].erase({dist[x], x});
      if(apples[x].count(k)) apples[x].erase(k);
      break;
    case 'E':
      scanf("%d %d", &x, &k);
      for(int a : apples[x])
        closest[a].erase({dist[x], x});
      apples[x].clear();
      dist[x] = k;
      break;
    case 'Q':
      scanf("%d", &k);
      if (closest[k].empty())
        printf("-1\n");
      else
        printf("%d\n", closest[k].begin()->second);
      break;
    }
  }

  return 0;
}