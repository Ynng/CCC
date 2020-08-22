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

const int MOD = 1e9 + 7, MX = 200000 + 5;

char S[MX], T[MX];
int len;
int main()
{
  scanf("%s %s", S, T);
  len = strlen(S);

  for (int i = 1; i < len; i++)
    if ((S[i - 1] == S[i]) != (T[i - 1] == T[i]))
    {
      printf("No\n");
      return 0;
    }

  printf("Yes\n");

  return 0;
}