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

const int MOD = 1e9 + 7, MX = 1000000 + 5;

int N, MXD;
pi in[MX];
ll bit[MX];

//binary indexed tree

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

void update(ll dif, int index)
{
  while (index <= MXD)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 1, d, p; i <= N; i++)
  {
    scanf("%d %d", &d, &p);
    in[i] = {d, p};
    MXD = max(MXD, d);
  }
  //lambda custom sorting
  sort(in + 1, in + N + 1, [](const pi & arr, const pi & b) {
    if(arr.s!=b.s)return arr.s>b.s;
    else return arr.f<b.f;
  });

  for (int i = 1; i <= N; i++)
    bit[i] = (i & -i);

  ll sum = 0;
  for (int i = 1; i <= N; i++)
  {
    pi cur = in[i];
    int l = 1;
    int r = cur.f;
    //binary search to find available spot
    //logN * logN
    int target = query(cur.f);
    if(target<=0)continue;
    //imagine, working binary search
    //finds the first number that's bigger or equal to target
    while(l<r){
      int m = (l+r)/2;
      int q = query(m);
      if(q<target)l=m+1;
      else r = m;
    }
    update(-1, l);
    sum+=cur.s;
  }

  printf("%lld\n", sum);

  return 0;
}