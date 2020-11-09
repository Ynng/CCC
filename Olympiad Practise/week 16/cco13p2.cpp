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

const int MOD = 1000000007, MX = 1048576 + 5;

int N,M;
int S[MX];

//quick power
ll quickpow(ll base, ll exp)
{
  ll ans = 1;
  for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
    if (exp & 1)
      ans = (ans * base) % MOD;
  return ans;
}

//segment tree
struct node{
  int l,r;
  pi max;
}seg[3*MX];

int inputCount;

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d ", &temp);
    inputCount++;
    seg[idx].max = {temp, inputCount};
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  seg[idx].max = max(seg[2*idx].max, seg[2*idx+1].max);
}

void update (int pos, pi val, int idx){
  if(seg[idx].l == seg[idx].r){
    seg[idx].max = val; return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(pos<=mid)update(pos,val,2*idx);
  else update(pos,val,2*idx+1);
  seg[idx].max = max(seg[2*idx].max, seg[2*idx+1].max);
}

//range minimum queryMax
pi queryMax(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].max;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return queryMax(l,r,2*idx);
  else if(l>mid) return queryMax(l,r,2*idx+1);
  else return max(queryMax(l,mid,2*idx), queryMax(mid+1,r,2*idx+1));
}


//range minimum queryMax
int queryDepth(int i, int depth, int idx){
  if(seg[idx].max.second == i)
    return depth;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(i<=mid) return queryDepth(i,depth+1,2*idx);
  else return queryDepth(i,depth+1,2*idx+1);
}


int main()
{
  scanf("%d %d", &N, &M);
  build(1, quickpow(2,N), 1);

  for (int i = 1; i <= M; i++)
  {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'R')
    {
      int idx, s;
      scanf("%d %d", &idx, &s);
      update(idx,{s, idx},1);
    }
    if (cmd == 'W')
    {
      printf("%d\n", seg[1].max.s);
    }
    if (cmd == 'S')
    {
      int idx;
      scanf("%d", &idx);
      printf("%d\n", N - queryDepth(idx, 0, 1));
    }
  }

  return 0;
}