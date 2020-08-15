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
#include <time.h>
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

const int MOD = 1e9+7, MX = 5000 + 5;

char brackets[MX];
int b[MX];
int psa[MX];
int main()
{
  clock_t t;
  t = clock();
  scanf("%s", brackets);
  int len = strlen(brackets);

  for (int i = 0; i < len; i++)
  {
    if(brackets[i] == '(')b[i + 1] = 1;
    else b[i + 1] = -1;
    psa[i+1] = b[i + 1]+ psa[i];
    // printf("%d\n", psa[i+1]);
  }
  
  
  for (int i = 1; i <= len; i++)
  {
    for (int j = i-1; j <= len; j++)
    {
      int count = 0;
      bool working = true;
      int finalValue = psa[i - 1] - (psa[j] - psa [i - 1]) + psa[len] - psa[j];
      if(finalValue!=0)working = false;
      for (int k = 1; k < i; k++)
      {
        if(!working)break;
        count+=b[k];
        if(count<0)working = false;
      }
      for (int k = i; k <= j; k++)
      {
        if(!working)break;
        count-=b[k];
        if(count<0)working = false;
      }
      for (int k = j + 1; k <= len; k++)
      {
        if(!working)break;
        count+=b[k];
        if(count<0)working = false;
      }
      if(working || (clock() > t + 575000)){
        printf("possible");
        return 0;
      }
    }
  }
  printf("impossible\n");
  return 0;
}