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

const int MOD = 1e9 + 7, MX = 20 + 5;

int R, C;
char arr[MX][MX];
int main()
{
  scanf("%d %d", &R, &C);
  for (int i = 1; i <= R; i++)
  {
    for (int j = 1; j <= C; j++)
    {
      scanf(" %c", &arr[i][j]);
      // if(temp == '#')arr[i][j] = -1;
      //   arr[i][j] = temp-'a'+1;
    }
  }
  string answer = "";
  string str;
  bool first = true;
  for (int i = 1; i <= R; i++)
  {
    for (int j = 1; j <= C; j++)
    {

      if (arr[i][j] == '#')
        continue;
      if (arr[i - 1][j] == '#' || i == 1)
      {
        str.clear();
        for (int k = i; k <= R; k++)
        {
          if (arr[k][j] == '#')
            break;
          str.push_back(arr[k][j]);
        }

        if (str.length() > 1)
          if (first || lexicographical_compare(str.begin(), str.end(), answer.begin(), answer.end()))
          {
            answer = str;
            first = false;
          }
      }

      if (arr[i][j - 1] == '#' || j == 1)
      {
        str.clear();
        for (int k = j; k <= C; k++)
        {
          if (arr[i][k] == '#')
            break;
          str.push_back(arr[i][k]);
        }

        if (str.length() > 1)
          if (first || lexicographical_compare(str.begin(), str.end(), answer.begin(), answer.end()))
          {
            first = false;
            answer = str;
          }
      }
    }
  }

  cout << answer;

  return 0;
}