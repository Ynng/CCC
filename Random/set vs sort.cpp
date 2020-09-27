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
#include <random>
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

const int MOD = 1e9 + 7, MX = 1e5 + 5;

const int MM = 1000000;
set<ll> s;
unordered_set<ll> us;
map<int, ll> m;
unordered_map<int, int> um;
vector<int> v;
ll a[MM];
int main()
{
  mt19937 gen(rand());
  uniform_int_distribution<int> dis(1, 1e8);

  int input;
  scanf("%d", &input);

  for (int i = 0; i < MM; i++)
  {
    if (input == 0)
      dis(gen);
    if (input == 1)
      s.insert(dis(gen));
    if (input == 2)
      v.push_back(dis(gen));
    if (input == 3)
      a[i] = dis(gen);
    if (input == 4)
      us.insert(dis(gen));
    if (input == 5)
      m[i] = dis(gen);
    if (input == 6)
      um[i] = dis(gen);
    if (input == 7)
      um[dis(gen)] = i;
    if (input == -10)
      v.push_back(dis(gen));
  }

  if (input == 2)
    sort(v.begin(), v.end());
  if (input == 3)
    sort(a, a + MM);
  if (input == -10)
  {
    sort(v.begin(), v.end());
    ll last;
    int counter = 0;
    for (int i : v)
    {
      if(i!=last){
        counter++;
        um[i] = counter;
      }
      last=i;
    }
  }
  // if(input==1)
  // for(int i : s){
  //   printf("%d\n", i);
  // }
  // if(i==2)
  // for(int i : v){
  //   printf("%d\n", i);
  // }
  //   if(i==3)
  // for(int i : a){
  //   printf("%d\n", i);
  // }

  return 0;
}