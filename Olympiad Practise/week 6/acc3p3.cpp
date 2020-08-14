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

int N;
string str[MX];
int cutOffPos[MX];
string answer = "";
int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    cin >> str[i];
  }

  for (char i = 'z'; i >= 'a'; i--)
  {
    bool existInAll = true;
    int minLength = 10000000;
    for(int j = 1; j <= N; j++)
    {
      bool found = false;
      int foundCount = 0;
      int strlen = str[j].length();
      for (int k = 0; k < strlen; k++)
      {
        if(str[j].at(k) == i){
          if(!found)
            cutOffPos[j] = k;
          foundCount++;
          found = true;
        }else if(found){
          break;
        }
      }
      if(found){
        minLength = min(minLength, foundCount);
      }

      if(!found){
        existInAll = false;
        break;
      }
    }
    if(existInAll){
      for(int j = 1; j <= N; j++){
        int cutoffIndex = cutOffPos[j]+minLength;
        if(cutoffIndex >= str[j].length())
          str[j] = "";
        else
          str[j] = str[j].substr(cutoffIndex);
      }
      while(minLength > 0){
        answer += i;
        minLength--;
      }
      i++;
    }
  }

  if(answer.length() > 0){
    cout << answer << endl;
  }else{
    printf("-1\n");
  }
  
  
  return 0;
}