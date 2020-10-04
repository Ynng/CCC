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

const int MOD = 1e9+7, MX = 150000 + 5;

int N;
int a[MX];
ll psa[MX];

//binary indexed tree ll
//bit ll
ll bit[MX*2];

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
  while (index <= 2*MX)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}
int main()
{
  scanf("%d", &N);
  update(1, MX);
  ll answer=0;
  for(int i = 1, temp; i <= N; i++)
  {
    scanf("%d", &temp);
    if(temp == 1)a[i]=1;
    else a[i] = -1;
    psa[i] = a[i] + psa[i-1];
    answer+=query(psa[i]+MX-1);
    update(1, psa[i]+MX);
  }

  printf("%lld", answer);
  
  return 0;
}