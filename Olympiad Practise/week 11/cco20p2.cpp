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

const int MOD = 1e9 + 7, MX = 200000 + 5;

int N;
int D[MX];
int D2[MX];
int bit[MX];
vector<int> T[MX];
priority_queue<int> q;

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

void update(int dif, int index)
{
  while (index <= MX - 2)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 1, d; i <= N; i++){
    scanf("%d", &d);
    T[d].push_back(i);
  }
  ll ans = 0;
  for(int i = N; i > 0; i--){
    for(int e : T[i])
      q.push(e);
    if(q.empty()){
      printf("-1\n");
      return 0;
    }
    D[i] = q.top();
    q.pop();
    ans+=query(D[i]);
    update(1, D[i]);
  }

  printf("%lld\n", ans);
  return 0;
}