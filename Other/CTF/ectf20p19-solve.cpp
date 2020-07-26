#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
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

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
  return rtrim(ltrim(s));
}

//character of hex digit to their respective value
int toval(char c)
{
  if (c < 58)
    return c - 48;
  else if (c < 91)
    return c - 65 + 10;
  else
    return c - 97 + 10;
}

int main()
{

  // ofstream cout;
  // cout.open("example.txt");

  string input;
  cin >> hex >> input;
  input = trim(input);
  if (input.find("0x") == 0)
    input = input.substr(2);
  int len = input.length() / 2;

  //120 As
  for (int i = 0; i < 120; i++)
  {
    cout << "A";
  }

  for (int i = len - 1; i >= 0; i--)
  {
    char first = input.at(i * 2);
    char second = input.at(i * 2 + 1);
    int value = toval(first) * 16 + toval(second);

    char output;

    if (value > 127)
      value -= 256;

    output = value;
    cout << output;
  }

  // cout.close();

  // cout << input << " " << len;
  // FILE *f = fopen("input", "w");
  // char arr[5] = {-96, 17, 64};
  // fprintf(f, arr);
  return 0;
}