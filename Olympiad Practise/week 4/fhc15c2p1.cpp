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

const int MOD = 1e9 + 7, MX = 50005;

int T, N;

deque<int> messy;
deque<int> messy2;
int top, bot;

bool solve()
{
  messy.clear();
  messy2.clear();
  scanf("%d", &N);
  for (int i = 0, temp; i < N; i++)
  {
    scanf("%d", &temp);
    messy.push_back(temp);
    messy2.push_back(temp);
  }

  //left
  top = bot = messy.front();
  messy.pop_front();
  while (messy.size() > 0)
  {
    if (messy.front() == bot - 1)
    {
      bot--;
      messy.pop_front();
    }
    else if (messy.front() == top + 1)
    {
      top++;
      messy.pop_front();
    }
    else if (messy.back() == bot - 1)
    {
      bot--;
      messy.pop_back();
    }
    else if (messy.back() == top + 1)
    {
      top++;
      messy.pop_back();
    }
    else
    {
      //right
      top = bot = messy2.back();
      messy2.pop_back();
      while (messy2.size() > 0)
      {
        if (messy2.front() == bot - 1)
        {
          bot--;
          messy2.pop_front();
        }
        else if (messy2.front() == top + 1)
        {
          top++;
          messy2.pop_front();
        }
        else if (messy2.back() == bot - 1)
        {
          bot--;
          messy2.pop_back();
        }
        else if (messy2.back() == top + 1)
        {
          top++;
          messy2.pop_back();
        }
        else
        {
          return false;
        }
      }
      return true;
    }
  }

  return true;
}

int main()
{
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    printf("Case #%d: %s\n", t, solve() ? "yes" : "no");
  }

  return 0;
}