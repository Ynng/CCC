#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7, MX = 100000 + 5;

int t;
ll a[MX], bit[MX];
ll sorted[MX];
unordered_map<ll, ll> c;

ll getSum(int r)
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
  while (index <= MX-2)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}

int main()
{
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    scanf("%lld", a+i);
    sorted[i] = a[i];
  }

  sort(sorted+1, sorted+t+1);
  for(int i = 1; i <= t; i++)
    c[sorted[i]] = i;

  ll rankSum = 0;
  for(int i = 1; i <= t; i++){
    update(1, c[a[i]]);
    rankSum += i - getSum(c[a[i]]) + 1;
  }

  printf("%.2f\n", rankSum * 1.0 / t);
  
  
  return 0;
}