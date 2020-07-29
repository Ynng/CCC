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

const int MOD = 1e9+7, MX = 500005;

ll N, M;
deque<ll> dq;
int main()
{
  scanf("%lld %lld", &N, &M);
  ll sum = 0;
  int ans = MX;
  for(int i = 1, temp; i <= N; i++)
  {
    scanf("%d", &temp);
    dq.push_back(temp);
    sum+=temp;
    if(sum >= M){
      while(dq.front() <= sum - M ){
        sum-=dq.front();
        dq.pop_front();
      }
      if(dq.size() < ans)ans = dq.size();
    }
  }
  if(ans==MX)ans = -1;
  printf("%d", ans);
  
  
  return 0;
}