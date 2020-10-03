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

const int MOD = 1e9 + 7, MX = 10000000 + 5;

ll A, B;
bool notprime[MX];
vector<ll> primes;
ll L, R;

bool isPrimeLarge(ll num){
  ll goodEnough = sqrt(num+10);
  for(ll prime : primes){
    if(num==prime)return true;
    if(num%prime==0)return false;
    if(prime>goodEnough)break;
  }
  return true;
}
vector<ll> output;
int main()
{
  scanf("%lld %lld", &A, &B);
  ll N = sqrt(max(A, B)+10);
  for (int i = 2; i < N; i++)
  {
    if(notprime[i])continue;
    for (int m = 1; m*i<N; m++)
      notprime[m*i]=true;
    primes.push_back(i);
  }
  L = min(A, B);
  R = max(A, B);
  bool flipped = L==B;
  output.push_back(L);
  bool nope = false;

  if(isPrimeLarge(R-L)){
    output.push_back(R);
  }else if(L == 3 && R == 7){
      output.push_back(5);
      output.push_back(7);
  }else{
    if(L!=2){
      if(isPrimeLarge(L-2)){
        output.push_back(2);
      }else if(isPrimeLarge(L+2)){
        output.push_back(L+2);
        output.push_back(2);
      }else{
        printf("-1\n");
        return 0;
      }
    }
    if(isPrimeLarge(R-2)){
      output.push_back(R);
    }else if(isPrimeLarge(R+2)){
      output.push_back(R+2);
      output.push_back(R);
    }else
    {
      printf("-1\n");
      return 0;
    }
  }

  if(flipped)reverse(output.begin(), output.end());
  printf("%d\n", output.size());
  for(ll num : output){
    printf("%lld ", num);
  }
  printf("\n");


  return 0;
}