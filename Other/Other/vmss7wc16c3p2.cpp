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

const int MOD = 1000000007, MX = 2000 + 5;

int N, M, A, B;

vector<int> G[MX];
bool visited[MX];

bool dfs(int i){
  visited[i]=true;
  if(i==B)return true; //return true if reached target
  for(int neighbor : G[i]){
    if(!visited[neighbor])
      if(dfs(neighbor)) //return true if children reached target
        return true;
  }
  return false; //return false if no children reached target
}

int main()
{
  scanf("%d %d %d %d", &N, &M, &A, &B);
  for(int i = 1, X, Y; i <= M; i++)
  {
    scanf("%d %d", &X, &Y);
    G[X].push_back(Y);
    G[Y].push_back(X);
  }

  if(dfs(A)) printf("GO SHAHIR!\n");
  else printf("NO SHAHIR!\n");
  
  return 0;
}