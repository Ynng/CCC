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

const int MOD = 1e9+7, MX = 10000 + 5;

int N;
string arr[3];
int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    sort(arr, arr+3, [](const string & a, const string & b){
      return a.length() < b.length();
    });
    //check prefix with stl std string
    //check suffix with stl std string
    if(arr[2].rfind(arr[1],0)==0
      || arr[2].rfind(arr[0],0)==0
      || arr[1].rfind(arr[0],0)==0
      || arr[2].rfind(arr[1])==arr[2].length() - arr[1].length()
      || arr[2].rfind(arr[0])==arr[2].length() - arr[0].length()
      || arr[1].rfind(arr[0])==arr[1].length() - arr[0].length())
      printf("No\n");
    else
      printf("Yes\n");
  }
  
  
  return 0;
}