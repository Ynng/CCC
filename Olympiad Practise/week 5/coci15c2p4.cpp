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

const int MOD = 1e9+7, MX = 50000 + 5;


bool endswith (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}
bool startswith (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (0, ending.length(), ending));
    } else {
        return false;
    }
}



int N;
string arr[MX];
pi info[MX];
vector<int> children[MX];
int mx = 1;
bool skip[MX];

void recurseSetSkip(int cur){
  if(skip[cur])return;
  skip[cur] = true;
  for (int i = 0; i < children[cur].size(); i++)
    if(!skip[children[cur][i]])
      recurseSetSkip(children[cur][i]);
}


int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
  {
    cin >> arr[i];
    if(info[i].first == 0)info[i] = {1,i};

    if(i==0)continue;

    memset(skip, 0, sizeof skip);
    for (int j = 0; j < i; j++)
    {
      if(skip[j])continue;
      bool success = false;
      if(startswith(arr[i], arr[j]))
        if(endswith(arr[i], arr[j]))
          success = true;
      if(success){
        children[j].push_back(i);
        if(info[j].first >= info[i].first){
            info[i] = {info[j].first+1, j};
            if(info[i].first > mx)mx= info[i].first;
        }
      }
      else{
        recurseSetSkip(j);
      }
    }
    
  }

  printf("%d", mx);

  
  return 0;
}