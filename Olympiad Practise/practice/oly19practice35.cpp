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

const int MOD = 1e9 + 7, MX = 100 + 5;

char A[MX], B[MX];
int alen, blen;
ll sum = 0;
int main()
{
  scanf("%s %s", A, B);
  alen = strlen(A);
  blen = strlen(B);

  for (int i = 0; i < alen; i++)
    for (int j = 0; j < blen; j++)
      sum += (A[i] - '0') * (B[j] - '0');

  printf("%lld", sum);
  return 0;
}