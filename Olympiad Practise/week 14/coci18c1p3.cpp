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

const int MOD = 1e9+7, MX = 100000 + 5;
const int MAX = 1000000000;

int N, M;
int l[MX], r[MX];

//Fast to check
//binary search the answer

bool check(int limit){
  int count = 0;
  for(int i = 1, j= 1; i<=N&&j<=M;){
    if(abs(l[i]-r[j])<=limit){
      count++; i++; j++;
    }else if(l[i]<r[j]){
      i++;
    }else if(l[i]>r[j]){
      j++;
    }
  }
  return count == min(N,M);
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++)
    scanf("%d", l+i);
  for(int i = 1; i <= M; i++)
    scanf("%d", r+i);
  sort(l+1, l+1+N);
  sort(r+1, r+1+M);
  int lo = 0, hi = MAX, ans = 0;

  while(lo<=hi){
    int mid = (lo + hi)/2;
    if(check(mid)){ans = mid; hi=mid-1;}
    else lo = mid+1;
  }

  printf("%d\n", ans);
  return 0;
}