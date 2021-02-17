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

const int MOD = 1000000007, MX = 200000 + 5;

int N,W,D;
vi G[MX];
vi RG[MX];
int distArr[MX];
multiset<int> totalTime;

int dist(int i){
  if(i==N)return 0;
  if(distArr[i])return distArr[i];
  return MX;
}

void bfs()
{
  queue<pi> q;
  q.push({N,0});
  while(!q.empty()){
    for(int n : RG[q.front().f]){
      if(distArr[n])continue;
      distArr[n] = q.front().s+1;
      q.push({n, distArr[n]});
    }
    q.pop();
  }
}

// pi bit[MX];
int subway[MX];
int subwayR[MX];

// pi queryMin(int r)
// {
//   pi mi = {MX+10, 0};
//   while (r > 0)
//   {
//     mi=min(bit[r],mi);
//     r ^= (r & -r);
//   }
//   return mi;
// }

// void update(int val, int idx)
// {
//   while (idx <= MX-4)
//   {
//     if(bit[idx].s == idx){
//       if(val > bit[idx].f){
//         //find replacement
//         pi rep = queryMin(idx-1);
//         if(rep.f < val)bit[idx]=rep;
//       }else{
//         bit[idx] = {val,idx};
//       }
//     }else{
//       if(val < bit[idx].f || bit[idx].f==0){
//         bit[idx] = {val,idx};
//       }
//     }
//     idx += (idx & -idx);
//   }
// }

int main()
{
  scanf("%d %d %d", &N, &W, &D);
  for(int i = 1, A, B; i <= W; i++)
  {
    scanf("%d %d", &A, &B);
    G[A].pb(B);
    RG[B].pb(A);
  }

  //Find distance to N only walking
  bfs();
  //Find train + walking best time each day
  for (int i = 1, temp; i <= N; i++)
  {
    scanf("%d", &temp);
    subway[temp] = i;
    subwayR[i] = temp;
  }
  for (int i = 1; i <= N; i++){
    totalTime.insert(dist(i) + subway[i]-1);
    // printf("%d\n",dist(i) + subway[i]);
    // update(dist(i) + subway[i], i);
  }
  
  // for (int i = 1; i <= N; i++){
  //   printf("%d\n", queryMin(i).f);
  // }

  for(int i = 1, u, v; i <= D; i++)
  {
    scanf("%d %d", &u, &v);
    
    auto it = totalTime.find(dist(subwayR[u]) + u-1);
    if (it != totalTime.end())
      totalTime.erase(it);
    it = totalTime.find(dist(subwayR[v]) + v-1);
    if (it != totalTime.end())
      totalTime.erase(it);

    int temp = subwayR[u];
    subwayR[u] = subwayR[v];
    subwayR[v] = temp;


    totalTime.insert(dist(subwayR[u]) + u-1);
    totalTime.insert(dist(subwayR[v]) + v-1);

    // update(dist(subwayR[u]) + u, subwayR[u]);
    // update(dist(subwayR[v]) + v, subwayR[v]);
    
    printf("%d\n", *totalTime.begin());
  }
  
  return 0;
}