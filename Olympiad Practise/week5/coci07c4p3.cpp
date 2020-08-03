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

const int MOD = 1e9 + 7, MX = 10000 + 5;

int main()
{
  string str;
  cin >> str;

  int len = str.length();

  string newstr;
  string a, b, c;
  bool first = true;
  string answer;
  for (int i = 1; i < len - 1; i++)
  {
    for (int j = 1; j + i < len; j++)
    {
      a = str.substr(0, i);
      b = str.substr(i, j);
      c = str.substr(j + i, len - j + i);

      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      reverse(c.begin(), c.end());
      newstr = a;
      newstr.append(b);
      newstr.append(c);

      // cout << newstr << endl;
      
      if (first || lexicographical_compare(newstr.begin(), newstr.end(), answer.begin(), answer.end()))
      {
        first = false;
        answer = newstr;
      }
    }
  } 


  cout << answer;

  return 0;
}