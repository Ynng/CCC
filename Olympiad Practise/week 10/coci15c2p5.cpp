#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define INF 0x3f3f3f3f // for int
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

const int MOD = 1e9+7, MX = 1000000 + 5;

int N;
ll P;
ll a[MX];
ll psa[MX];
vector<ll> input;
ll bit[MX];
unordered_map<ll, int> mmap;//too much ram

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
  while (index <= N+1 )
  {
    bit[index] += dif;
    index += (index & -index);
  }
}
int main()
{
  scanf("%d",&N);
  for(int i = 1; i <= N; i++)
    scanf("%lld", a+i);
  scanf("%lld",&P);
  for(int i = 1; i <= N; i++){
    psa[i] = a[i] + psa[i-1]-P;
    input.push_back(psa[i]);
  }
  input.push_back(0);

  //low memory coordinate compression
  sort(input.begin(), input.end());
  input.resize(unique(input.begin(), input.end()) - input.begin());

  // memcpy(spsa, psa+1, (N+1)*sizeof(ll));
  // sort(spsa, spsa+N+1);
  // int uniqueSize = unique(spsa, spsa+N+1)-spsa;
  //[0,0,1,1,2,2,3,4]
  //after unique: [0,1,2,3,0,1,2]
  //returns pointer to     ⬆
  //pointer - pointer to original array = size of unique array

  ll ans = 0;
  for(int i = 0; i<=N; i++){
    int rk = lower_bound(input.begin(), input.end(), psa[i]) - input.begin() +1;
    ans+=query(rk);
    update(1,rk);
  }
  printf("%lld", ans);
  return 0;
}