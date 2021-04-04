#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

#define INF 0x3f3f3f3f            // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define sz(x) (int)(x).size()
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 40 + 5, LINEMX = 820 + 5;

int N;
pi P[MX];

// Doesn't work

bool findInteresect(pi p1, pi q1, pi p2, pi q2)
{
  if(p1==p2 || p1 == q2 || q1 == p2 || q1 == q2)
  return false;
  int rise1 = q1.s - p1.s;
  int run1 = q1.f - p1.f;
  int rise2 = q2.s - p2.s;
  int run2 = q2.f - p2.f;

  int l1 = min(p1.f, q1.f);
  int r1 = max(p1.f, q1.f);
  int l2 = min(p2.f, q2.f);
  int r2 = max(p2.f, q2.f);

  if (run1 == 0 && run2 == 0)
    return false;
  if (run1 == 0)
  {
    int x = l1;
    if (l2 < x && r2 > x)
      return true;
    return false;
  }
  if (run2 == 0)
  {
    int x = l2;
    if (l1 < x && r1 > x)
      return true;
    return false;
  }

  double m1 = rise1 / run1;
  double m2 = rise2 / run2;
  if (m1 == m2)
    return false;
  double x = (p2.s - p1.s + m1 * p1.f - m2 * p2.f) / (m1 - m2);
  if (l1 < x && r1 > x && l2 < x && r2 > x)
    return true;
  return false;
}

int main()
{
  // while (true)
  // {
  //   int px1, py1, qx1, qy1, px2, py2, qx2, qy2;
  //   scanf("%d %d %d %d %d %d %d %d", &px1, &py1, &qx1, &qy1, &px2, &py2, &qx2, &qy2);
  //   printf("%d\n", findInteresect({px1, py1}, {qx1, qy1}, {px2, py2}, {qx2, qy2}));
  // }

  scanf("%d", &N);
  for (int i = 1, x, y; i <= N; i++)
  {
    scanf("%d %d", &x, &y);
    P[i] = {x, y};
  }

  sort(P + 1, P + 1 + N);
  ll count = 0;
  do
  {
    // for (int i = 1; i <= N; i++)
    // {
    //   pi point = P[i];
    //   printf("%d %d\n", point.f, point.s);
    // }
    // printf("------\n");

    bool connected[N + 1][N + 1];
    ms(connected, 0);
    connected[1][2] = true;
    connected[2][1] = true;
    connected[2][3] = true;
    connected[3][2] = true;
    connected[3][1] = true;
    connected[1][3] = true;

    vector<pair<pi, pi>> lines;
    lines.pb({P[1], P[2]});
    lines.pb({P[2], P[3]});
    lines.pb({P[3], P[1]});

    bool match = true;

    //Add point
    for (int i = 4; i <= N; i++)
    {
      int connectionCount = 0;
      //Adding 3 lines for this point
      for (int j = 1; j <= N; j++)
      {
        if (j == i)
          continue;
        if (connected[i][j])
          continue;
        bool intersect = false;
        //Checking if this line can be drawn
        for (auto line : lines)
        {
          if (findInteresect(line.f, line.s, P[i], P[j]))
          {
            intersect = true;
            break;
          }
        }
        if (intersect)
          continue;
        connectionCount++;
        connected[i][j] = true;
        connected[j][i] = true;
        lines.pb({P[i], P[j]});
      }
      //If not 3 line, break;
      if (connectionCount != 3)
      {
        match = false;
        break;
      }
    }
    if (match)
      count++;

  } while (next_permutation(P + 1, P + 1 + N));

  printf("%lld\n", count);

  return 0;
}