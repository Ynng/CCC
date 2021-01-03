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

const int MOD = 1000000007, MX = 10000 + 5;

int L, N;
vector<string> v;
vector<string> in;

void solve(){
  v.clear();
  in.clear();
  scanf("%d", &N);

  for(int i = 0; i < N; i++)
  {
    string str;
    cin >> str;
    in.push_back(str);
  }

  int depth = 0;
  int maxDepth = 0;
  v.push_back(in[N-1]);
  for(int i = 0; i < N; i++)
  {
    if(v.size()>1 && v[v.size()-2] == in[i]){
      // printf("up %s %d\n", in[i].c_str(), v.size());
      //going back
      depth--;
      v.pop_back();
    }else{
      //going down
      // printf("down %s %d\n", in[i].c_str(), v.size());
      depth++;
      v.push_back(in[i]);
      maxDepth = max(maxDepth, depth);
    }
  }
  printf("%d\n", N*10 - maxDepth*20);
}

int main()
{
  scanf("%d", &L);
  for(int i = 1; i <= L; i++)
    solve();
  return 0;
}