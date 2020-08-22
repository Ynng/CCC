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

const int MOD = 1e9 + 7, MX = 3000 + 5;

int H, W, N;
int a[MX][MX];
deque<pair<int, int>> mi, mx;
int mxa[MX][MX], mia[MX][MX];
int main()
{
  scanf("%d %d %d", &H, &W, &N);
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  for (int j = 1; j <= W; j++)
  {
    mx.clear();
    mi.clear();
    for (int i = 1; i <= H; i++)
    {
      while (!mx.empty() && mx.back().first < a[i][j])
        mx.pop_back();
      while (!mi.empty() && mi.back().first > a[i][j])
        mi.pop_back();

      mx.push_back({a[i][j], i});
      mi.push_back({a[i][j], i});

      while (!mx.empty() && mx.front().second <= i - N)
        mx.pop_front();
      while (!mi.empty() && mi.front().second <= i - N)
        mi.pop_front();

      mxa[i][j] = mx.front().first;
      mia[i][j] = mi.front().first;
    }
  }

  int answer = -1;
  for (int i = N; i <= H; i++)
  {
    mx.clear();
    mi.clear();
    for (int j = 1; j <= W; j++)
    {
      while (!mx.empty() && mx.back().first < mxa[i][j])
        mx.pop_back();
      while (!mi.empty() && mi.back().first > mia[i][j])
        mi.pop_back();

      mx.push_back({mxa[i][j], j});
      mi.push_back({mia[i][j], j});

      while (!mx.empty() && mx.front().second <= j - N)
        mx.pop_front();
      while (!mi.empty() && mi.front().second <= j - N)
        mi.pop_front();
      
      int diff = mx.front().first - mi.front().first;
      if(j >= N)
        if(answer == -1 || diff < answer)
        answer = diff;
    }
  }
  printf("%d\n", answer);
  return 0;
}