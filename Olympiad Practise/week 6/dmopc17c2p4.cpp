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

const int MOD = 1e9 + 7, MX = 100000 + 5;

ll hsh[MX], hshi[MX];
ll p[MX];
int base = 131;
int len;
char S[MX];

ll getSubStrHash(int i, int len)
{
  return hsh[i] - (hsh[i - len] * p[len]);
}

ll getSubStrHashI(int i, int len)
{
  return hshi[i] - (hshi[i + len] * p[len]);
}

int main()
{
  scanf("%s", S);
  len = strlen(S);

  p[0] = 1;
  for (int i = 1; i <= len; i++)
    hsh[i] = hsh[i - 1] * base + S[i - 1] - 'A';
  for (int i = len; i >= 1; i--)
    hshi[i] = hshi[i + 1] * base + S[i - 1] - 'A';
  for (int i = 1; i <= len; i++)
    p[i] = p[i - 1] * base;

  for (int i = len - 1; i > 0; i--)
  {
    //palindrome check
    if (getSubStrHash(i, i) == getSubStrHashI(1, i))
    {
      ll temp = getSubStrHash(i, i);
      for (int j = i + 1; j <= len; j++)
      {
        if (getSubStrHash(j, i) == temp)
        {
          printf("%d", i);
          return 0;
        }
      }
    }
  }

  printf("0");

  return 0;
}