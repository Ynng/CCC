#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
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

#define MOD 1000000007
#define MAXN 1000005

int N, T, K, V;
bool arr[MAXN];
int upper = 0;
int sum, diff;
int answer = 0;
int main()
{
  scanf("%d %d %d %d", &N, &T, &K, &V);
  for (int i = 0, temp; i < V; i++)
  {
    scanf("%d", &temp);
    arr[temp]=true;
    if(temp > upper)upper = temp;
  }
  sum = 0;
  for (int i = 1; i <= T; i++)
    sum+=arr[i];
  
  int temp = T;
  while(sum < K){
    if(!arr[temp]){
      arr[temp] = true;
      sum++;
      answer++;
    }
    temp--;
  }

  for (int i = T+1; i <= N; i++)
  {
    sum-=arr[i-T];
    sum+=arr[i];
    diff = K - sum;
    if(diff > 0){
      answer+=diff;
      sum+=diff;
      arr[i]+=diff;
    }
  }
  
  printf("%d", answer);

  return 0;
}