#include <string>

using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


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

const int MOD = 1000000007, MX = 10000 + 5;

int main()
{
  string S;
  string T;

  int shift = 0;

  for(int i = 0; i < sizeT; i++)
  {
    if(S[i + shift] != T[i]){
        if(shift){
            return "IMPOSSIBLE";
        }
        shift++;
        i--;
    }
  }
  
  return 0;
}
