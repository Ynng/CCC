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

const int MOD = 1e9 + 7, MX = 1e5 + 5;

int Q;
bool notprime[MX];
ll psa[MX];
int main()
{
  scanf("%d", &Q);
  for (int i = 2; i <= MX; i++)
  {
    if (notprime[i])
      continue;
    for (int j = 2; j * i <= MX; j++)
    {
      notprime[j * i] = true;
    }
  }
  notprime[1]=true;
  for (int i = 1; i <= MX; i++)
  {
    psa[i]=psa[i-1] + (notprime[i] ? 0 : i);
  }

  for(int i = 1, A, B; i <= Q; i++)
  {
    scanf("%d %d", &A, &B);
    printf("%lld\n", psa[B] - psa[A-1]);
  }

  return 0;
}