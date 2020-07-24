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

const int MOD = 1e9 + 7, MX = 10005;

int variables;
char temp;
int main()
{
  char str[38] = "?PB~a6?KILEHEJC&bT6?QP5>H6O(fO!bw$4A|";
  // for (int i = 37 - 1; i >= 0; i--)
  // {
  //   temp = str[i];
  //   str[i] = str[36 - i];
  //   str[36 - i] = temp;
  // }

  for (int i = 0; i < 37; i++)
  {
    if (str[i] < 43)
      printf("_");
    else if (str[i] < 58)
      printf("%c", 105 - str[i]);
    else if (str[i] < 87)
      printf("%c", 36 + str[i]);
    else if (str[i] < 120)
      printf("%c", str[i] - 29);
    else if (str[i] == 124)
      printf("}");
    else if (str[i] == 126)
      printf("{");
  }

  scanf("%d");

  return 0;
}