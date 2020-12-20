#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define INF 0x3f3f3f3f // for int
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

const int MOD = 1000000007, MX = 2000 + 5;

int N;
int A[MX];
bool check[MX];

int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d", A+i);
  }

  int maxMEX = -1;
  int ansC = 0;
  for(int i = 1; i <= N; i++)
  {
    ms(check,false);
    int c = A[i];
    for(int j = 1; j <= N; j++)
    {
      int val = A[j]^c;
      if(val<=2000)check[val]=true;
    }
    int MEX = -1;
    for(int j = 0; j <= N; j++)
    {
      if(check[j])MEX = j;
      else break;
    }
    if(MEX >= maxMEX){
      if(MEX==maxMEX) 
        ansC = min(c, ansC);
      else
        ansC = c;
      maxMEX = MEX;
    }
  }

  printf("%d %d\n", maxMEX+1, ansC);
  
  
  return 0;
}