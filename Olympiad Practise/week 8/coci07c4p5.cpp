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

const int MOD = 1e9 + 7, MX = 100000 + 5, MXBIT =1000000 + 5 ;

int N;
pi sq[MX];
int bit[MXBIT];
bool cmp(pi a, pi b){return (a.f == b.f)?b.s < a.s : a.f < b.f;}
int dp[MX];
int point[MX];

#define DP(i) dp[N-i+1]

int query(int r)
{
  int mxid = 0;
  while (r > 0)
  {
    if(DP(bit[r]) > DP(mxid))
      mxid = bit[r];
    r ^= (r & -r);
  }
  return N-mxid+1;
}

void update(int id, int index)
{
  while (index <= MXBIT)
  {
    if(DP(id) > DP(bit[index]))
      bit[index] = id;
    index += (index & -index);
  }
}


int main()
{
  scanf("%d", &N);
  for (int i = 1, a, b; i <= N; i++)
  {
    scanf("%d %d", &a, &b);
    sq[i] = {a, b};
  }

  sort(sq + 1, sq + N + 1, cmp);

  int start = 1;
  for (int i = N, next; i >= 1; i--)
  {
    next = query(sq[i].s);
    dp[i]=dp[next]+1;
    point[i] = next;
    update(N-i+1, sq[i].s);
    if(dp[i]>dp[start])start=i;
  }

  printf("%d\n", dp[start]);
  while(start!=N+1){
    printf("%d %d\n", sq[start].f, sq[start].s);
    start = point[start];
  }

  return 0;
}