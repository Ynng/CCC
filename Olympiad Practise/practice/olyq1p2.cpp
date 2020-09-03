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

const int MOD = 1e9+7, MX = 2*1e6 + 5;

int N;
int arr[MX];
int main()
{
  scanf("%d", &N);
  int thresh = 0;
  int len = 1;
  int lookingFor = 0;
  for (int i = 0; i < N; i++)
  {
    scanf("%d", arr+i);
    int cur = arr[i];

    if(i==0){
      thresh = cur;
      continue;
    }

    if(cur > thresh){
      thresh = cur;
      if(!lookingFor || lookingFor == 1){
        lookingFor = -1;
        len++;
      }
    }

    if(cur < thresh){
      thresh = cur;
      if(!lookingFor || lookingFor == -1){
        lookingFor = 1;
        len++;
      }
    }
  }
  
  printf("%d", len);
  
  return 0;
}