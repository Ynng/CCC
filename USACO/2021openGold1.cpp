#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

#define INF 0x3f3f3f3f            // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define sz(x) (int)(x).size()
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 200000 + 5, MXLOG = 18;

int N;
int b[MX];

int occurNum[MX];
vector<int> idx[MX];
pi q[MX];
int bit[MX];
int last_visit[MX];

bool cmp(pi x, pi y)
{
  return x.s < y.s;
}

ll query(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[r];
    r ^= (r & -r);
  }
  return sum;
}

void update(int index, int dif)
{
  while (index <= MX - 5)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}
int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", b + i);
    occurNum[i] = idx[b[i]].size();
    idx[b[i]].push_back(i);
  }

  for (int i = 1; i <= N; i++)
  {
    idx[i].push_back(N);
  }

  //Generating queries
  for (int i = 1; i <= N; i++)
  {
    int l = i, r = idx[b[i]][occurNum[i] + 1];
    // printf("%d:%d\n", l, r);
    q[i] = {l, r};
  }
  sort(q + 1, q + N + 1, cmp);

  ll cnt = 0;
  int curQ = 1;
  for (int i = 1; i <= N; i++)
  {
    //if visited before, remove from bit
    if (last_visit[b[i]])
      update(last_visit[b[i]], -1);

    //adding to bit
    last_visit[b[i]] = i;
    update(i, 1);

    while (curQ <= N && q[curQ].s == i)
    {
      int ans = (query(q[curQ].s) - query(q[curQ].f - 1) - 1);
      // printf("%d:%d - %d\n", q[curQ].f, q[curQ].s, ans);
      cnt += ans;
      curQ++;
    }
  }
  printf("%lld\n", cnt);

  return 0;
}