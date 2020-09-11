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

int N, Q;
int a[MX];
ll bit[MX];

//bad code, actually bad

namespace std {
  template <> struct hash<pi> {
      inline size_t operator()(const pi &v) const {
          std::hash<int> int_hasher;
          return int_hasher(v.first) ^ int_hasher(v.second);
      }
  };
}

unordered_map<pi, ll> qans;

int query[MX][3];
pi bitquery[2 * MX];

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
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    scanf("%d", a+i);
  }

  scanf("%d", &Q);

  int temp = 0;

  for(int i = 0; i < Q; i++){
    scanf("%d %d %d", &query[i][0], &query[i][1], &query[i][2]);
    query[i][0]++;
    query[i][1]++;
    
    bitquery[2*i]={query[i][0]-1, query[i][2]};
    bitquery[2*i+1]={query[i][1], query[i][2]};
  }

  sort(bitquery, bitquery + Q * 2);

  temp = 0;
  while(bitquery[temp].first == 0){
    qans[bitquery[temp]] = 0;
    temp++;
  }
  ll sum = 0;
  for(int i = 1; i <= N; i++){
    update(a[i], a[i]);
    sum+=a[i];

    while(bitquery[temp].first == i){
      ll smaller = getSum(bitquery[temp].second-1);
      qans[bitquery[temp]] = sum-smaller;
      temp++;
    }
  }

  for(int i = 0, l, r, k; i < Q; i++)
    printf("%lld\n", qans[{query[i][1], query[i][2]}] - qans[{query[i][0]-1, query[i][2]}]);
  
  return 0;
}