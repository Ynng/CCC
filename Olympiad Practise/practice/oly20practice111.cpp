#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
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

const int MOD = 1e9 + 7, MX = 1e9 + 5;

#define ISNUM(x) ('0' <= x && x <= '9')

int operation(int op, int a, int b)
{
  switch (op)
  {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '%':
    return a % b;
  }
  printf("error");
  return 0;
}

void solve()
{
  bool prefix;
  bool first = true;
  vector<int> s;
  bool last = false;
  while (true)
  {
    char c;
    scanf("%c", &c);
    if (c == ' ')
      continue;
    if (c == '\n')
      last = true;

    if (!last)
      if (ISNUM(c))
        s.push_back(c - '0');
      else
        s.push_back(c + MX);

    if (first)
    {
      if (ISNUM(c))
        prefix = false;
      else
        prefix = true;
      first = false;
    }

    while (s.size() >= 3)
    {
      int op, a, b;
      if (prefix)
      {
        b = s[s.size() - 1];
        a = s[s.size() - 2];
        op = s[s.size() - 3];
      }
      else
      {
        op = s[s.size() - 1];
        b = s[s.size() - 2];
        a = s[s.size() - 3];
      }
      if (op > MX && a <= MX && b <= MX)
      {
        s.pop_back();
        s.pop_back();
        s.pop_back();
        s.push_back(operation(op - MX, a, b));
      }else{
        break;
      }
    }

    if (last)
      break;
  }
  printf("%d\n", s[0]);
}

int main()
{
  for (int i = 0; i < 5; i++)
    solve();

  return 0;
}