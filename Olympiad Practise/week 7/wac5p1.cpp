#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
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

const int MOD = 1e9+7, MX = 1000 + 5;

int N;
int arr[MX];
int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    scanf("%d", arr+i);
  sort(arr, arr+N);
  
  int total = N;
  ll cost = 0;
  while(total > 0){
    int mx = -1;
    for (int i = N-1; i >= 0; i--)
    {
      if(arr[i] == 0)continue;
      if(mx==-1 || arr[i] < mx){
        if(mx==-1)cost+=arr[i];
        mx = arr[i];
        arr[i] = 0;
        total--;
      }
    }
  }

  printf("%lld\n", cost);
  return 0;
}