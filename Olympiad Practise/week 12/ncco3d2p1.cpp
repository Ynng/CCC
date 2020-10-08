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

const int MOD = 1e9 + 7, MX = 50000 + 5, MXLOG = 20;

int N, Q;
int logN;
int a[MX];
int stmin[MXLOG][MX];
int stmax[MXLOG][MX];

//sparse table query (inclusive)(minimum)
int queryMin(int l, int r){
  int k = log2(r-l+1);
  return min(stmin[k][l], stmin[k][r-(1<<k)+1]);
}
//sparse table query (inclusive)(maximum)
int queryMax(int l, int r){
  int k = log2(r-l+1);
  return max(stmax[k][l], stmax[k][r-(1<<k)+1]);
}

int main()
{
  //classic sparse table min/max range
  //sparse table range mininum
  //sparse table range maximum
  //static range minimum query (RMQ)
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  memcpy(stmin, a, sizeof(int) * (N+1));
  memcpy(stmax, a, sizeof(int) * (N+1));

  logN = ceil(log2(N)) + 0.5;
  //initializing sparse table (minimum)
  for (int k = 1; k <= logN; k++)
    for (int i = 1; i <= N - (1 << k) + 1; i++)
      stmin[k][i] = min(stmin[k - 1][i], stmin[k - 1][i + (1 << (k - 1))]);

  //printing sparse table
  /*for (int k = 1; k <= logN; k++){
    for (int i = 1; i <= N - (1 << k) + 1; i++)
      printf("%d ", stmin[k][i]);
    printf("\n");
  }*/

  //initializing sparse table (maximum)mpe
  for (int k = 1; k <= logN; k++)
    for (int i = 1; i <= N - (1 << k) + 1; i++)
      stmax[k][i] = max(stmax[k - 1][i], stmax[k - 1][i + (1 << (k - 1))]);

  for(int i = 1, a, b; i <= Q; i++)
  {
    scanf("%d %d", &a, &b);
    printf("%d\n", queryMax(a,b)-queryMin(a,b));
  }
  return 0;
}