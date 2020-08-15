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

const int MOD = 1e9+7, MX = 100000 + 5;
const ll MAX_RANK = 10000000;
int N;
ll R[MX];
set<pi> s;
int main()
{
  scanf("%d", &N);
  for(int i = 1, temp; i <= N; i++){
    scanf("%lld", &temp);
    R[i] = -temp;
    if(s.empty())
      s.insert({R[i], 2});
    else{
      auto it = s.upper_bound({R[i], 0});
      if(it!=s.end()){
        pi parent = *it;
        s.erase(it);
        if(parent.second ==2){
          parent = {parent.first, 1};
          s.insert(parent);
        }
        pi child = {R[i], 2};
        s.insert(child);
      }else{
        printf("NO");
        return 0;
      }
    }
  }
  
  printf("YES");
    
  
  return 0;
}