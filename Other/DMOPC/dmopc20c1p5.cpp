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

const int MOD = 1e9+7, MX = 500000 + 5, MXA = 300000 + 5;

int N, K, M;
int C[MX];
int head[MX], tail[MX], depth[MX];
int bit[MX];
bool visited[MX];
vector<int> G[MX];
vector<int> etour;
vector<pi> inqueries;
vector<pair<pi,int>> queries;
vector<int> table[MX]; 
int traverser[MX]; 
int ans[MX];

//30 points... sort of works

ll query(int r)
{
  ll sum = 0;
  while (r > 0)
  {
    sum += bit[r];
    r ^= (r & -r);
  }
  return sum;
}

void update(ll dif, int index)
{
  while (index <= MX)
  {
    bit[index] += dif;
    index += (index & -index);
  }
}


void firstOccurrence()
{
  int tourLen = etour.size();
  for (int i = 1; i <= tourLen-1; i++)
  {
    table[etour[i]].push_back(i);
    if (table[etour[i]].size() == 1)
    {
        update(1, i);
        traverser[etour[i]]++;
    }
  }
}

void processQueries()
{
  int j = 1;
  for (int i = 0; i < queries.size(); i++)
  {
    for (; j < queries[i].first.first; j++)
    {
      int elem = etour[j];
      update(-1,table[elem][traverser[elem] - 1]);
      if (traverser[elem] < table[elem].size())
      {
        update(1,table[elem][traverser[elem]]);
        traverser[elem]++;
      }
    }
    ans[queries[i].second] = query(queries[i].first.second);
  }
}

void handleQueries(){
  for(pi q : inqueries)
    queries.push_back({{head[q.f],tail[q.f]},q.s});
  sort(queries.begin(),queries.end());
  firstOccurrence();
  processQueries();
  for(pi q : inqueries){
    printf("%d\n", ans[q.s]);
  }
  inqueries.clear();
  queries.clear();
  for(int i = 0; i<MXA; i++){
    table[i].clear();
    traverser[i]=0;
  }
  for(int i = 0; i < N*2+5; i++){
    bit[i] = 0;
  }
}

void dfs(int i, int d){
  head[i]=etour.size();
  etour.push_back(C[i]);
  depth[i]=d;
  for(int child : G[i]){
    if(depth[child]!=0&&depth[child]<d)continue;
    dfs(child, d+1);
  }
  tail[i]=etour.size();
  etour.push_back(C[i]);
}

int main()
{
  scanf("%d %d %d", &N, &K, &M);
  for(int i = 1; i <= N; i++)
    scanf("%d", C+i);
  for(int i = 1,a,b; i <= N-1; i++)
  {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  etour.push_back(1);
  dfs(1,1);
  for(int i = 1, cmd; i <= M; i++)
  {
    scanf("%d", &cmd);
    if(cmd==1){
      if(!inqueries.empty())handleQueries();
      int c, k;
      scanf("%d %d", &c, &k);
      C[c]=k;
      etour.clear();
      etour.push_back(1);
      dfs(1,1);
    }else{
      int u;
      scanf("%d", &u);
      inqueries.push_back({u,i});
    }
  }
  if(!inqueries.empty())handleQueries();
  return 0;
}