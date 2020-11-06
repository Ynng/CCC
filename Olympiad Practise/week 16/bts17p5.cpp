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

const int MOD = 1000000007, MX = 100000 + 5, MN = 1000 + 5;

int N, M;
char str[MN];
pair<int, pi> q[MX];
int freq[256];
vector<pair<int, char>> dontuse;
int nope[256];


//TODO: ask bruce
int main()
{
  scanf("%d %d", &N, &M);
  char c;
  int count,pos;
  for(int i = 1; i <= M; i++)
  {
    scanf(" %c %d %d", &c, &count, &pos);
    q[i] = {pos, {count, c}};
  }

  sort(q+1, q+M+1);
  pos = 0;
  for(int i = 1; i <= M; i++)
  {
    int increment = q[i].s.f - freq[q[i].s.s];
    for(int j = 1; j <= increment; j++){
      str[pos] = q[i].s.s;
      pos++;
    }
    // pos= pos + (q[i].s.f - freq[q[i].s.s]);
    if(pos > q[i].f){
      printf("-1\n");
      return 0;
    }
    freq[q[i].s.s] = max(q[i].s.f, freq[q[i].s.s]);
    nope[q[i].s.s]++;
    dontuse.push_back({pos})
  }

  while(pos < N){
    str[pos] = 'a';
    pos++;
  }

  printf("%s\n", str);
  
  return 0;
}