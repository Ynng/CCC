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

const int MOD = 1e9 + 7, MX = 1000000 + 5;

//Hashing example

char A[MX], B[MX];
ll hshA[MX], hshB[MX];
int base = 131;
ll p[MX];
int alen, blen;
ll getSubStrHashA(int i, int len)
{
  return hshA[i] - (hshA[i - len] * p[len]);
}
ll getSubStrHashB(int i, int len)
{
  return hshB[i] - (hshB[i - len] * p[len]);
}

int main()
{
  scanf("%s", A);
  scanf("%s", B);
  alen = strlen(A);
  blen = strlen(B);
  int minlen = min(alen, blen);
  int maxlen = max(alen, blen);

  p[0] = 1;

  for (int i = 1; i <= alen; i++)
    hshA[i] = hshA[i - 1] * base + A[i - 1] - 'a';
  for (int i = 1; i <= blen; i++)
    hshB[i] = hshB[i - 1] * base + B[i - 1] - 'a';
  for (int i = 1; i <= maxlen; i++)
    p[i] = p[i - 1] * base;

  int count = 0;
  for (int i = blen; i <= alen; i++)
    if (getSubStrHashA(i, blen) == hshB[blen])
      count++;

  printf("%d\n", count);

  return 0;
}