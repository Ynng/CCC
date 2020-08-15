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

//Random Number example

int N, M;
unordered_map<ll, int> freq;
ll answer, sum, psa, w[MX];

int main()
{
  scanf("%d %d", &N, &M);
  mt19937_64 gen(rand());
  uniform_int_distribution<ll> dis(1, 1e12);

  for(int i = 1; i <= M; i++)
  {
    w[i] = dis(gen);
    sum+=w[i];
  }
  
  freq[0] = 1;
  for (int i = 1, x; i <= N; i++){
    scanf("%d", &x);
    psa = (psa + w[x]) % sum;
    answer += freq[psa];
    freq[psa]++;
  }

  printf("%lld", answer);

  return 0;
}