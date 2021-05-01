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

const ll MOD = 1000000007, MX = 1000000000000 + 5;

ll K;
vi numbers;
ll sum;
int main()
{
  scanf("%lld", &K);
  K++;
  while (!(K % 2))
  {
    sum+=1;
    numbers.pb(1);
    K = K / 2;
  }
  for (int i = 3; i <= sqrt(K); i = i + 2)
  {
    while (!(K % i))
    {
      sum+=i - 1;
      numbers.pb(i - 1);
      K = K / i;
    }
  }
  if (K > 2){
    sum+=K-1;
    numbers.pb(K - 1);
  }

  if(sum>100000){
    printf("Sad Chris\n");
    return 0;
  }

  printf("%lld\n", sum);
  int num = 1;
  for(auto time : numbers){
    for (int i = 0; i < time; i++)
      printf("%d ", num);
    num++;
  }

  return 0;
}