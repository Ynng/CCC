#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7, MXN = 1e5+5, MXM = 1e4+5;

int N, M;
bool appeared[MXM];
int main()
{
  scanf("%d %d", &N, &M);

  int fullset = M;
  int len = 1;
  for(int i = 1, cur; i <= N; i++)
  {
    scanf("%d", &cur);
    if(!appeared[cur])
      fullset--;
    appeared[cur] = true;
    if(fullset == 0){
      len++;
      fullset = M;
      memset(appeared, 0, sizeof appeared);
    }
  }
  
  printf("%d\n", len);
  
  return 0;
}