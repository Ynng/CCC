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

const int MOD = 1000000007, MX = 100000 + 5;

int N;
int A[MX];
int sorted[MX];
int mism[10];
int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d", A+i);
    sorted[i] = A[i];
  }
  sort(sorted+1, sorted + N + 1);
  int occur = 0;
  for(int i = 1; i <= N; i++)
  {
    if(sorted[i]!=A[i]){
      occur++;
      mism[occur] = i;
      if(occur == 2){
        if(A[mism[1]] == sorted[i] && sorted[mism[1]] == A[i]){

        }else{
          printf("NO\n");
          return 0;
        }
      }else if(occur > 2){
                  printf("NO\n");
          return 0;
      }
    }
  }

  printf("YES\n");
  
  
  return 0;
}