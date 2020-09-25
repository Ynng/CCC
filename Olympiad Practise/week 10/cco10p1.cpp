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
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

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

const int MOD = 1e9 + 7, MX = 5 + 5;

int D, wait[MX], F, T, barked[MX], waiting[MX];
vector<int> hear[MX];
vector<int> bark[MX];
int main()
{
  scanf("%d", &D);
  for (int i = 1; i <= D; i++)
    scanf("%d", wait + i);
  scanf("%d", &F);
  for (int i = 1, a, b; i <= D; i++){
    scanf("%d %d", &a,&b);
    hear[a].push_back(b);
  }
  scanf("%d", &T);

  bark[0].push_back(1);
  for (int i = 0; i <= T; i++)
  {
    for(int d : bark[i]){
      barked[d]++;
      for(int h : hear[d]){
        if(waiting[h])continue;
        bark[wait[d]+i].push_back(h);
        waiting[h]=true;
      }
    }
    for(int d : bark[i]){
        waiting[d]=false;
    }
  }
  
  for(int i = 1; i <= D; i++)
  {
    printf("%d\n", barked[i]);
  }
  return 0;
}