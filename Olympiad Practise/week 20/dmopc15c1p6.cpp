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

const int MOD = 1000000007, MX = 200000 + 5;

int M,N,Q;

struct node{
  int l,r;
  ll sum, lz;//lz -> lazy propagation
}seg[3*MX];

void pushup(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[idx].sum = seg[lson].sum + seg[rson].sum;
}

void pushdown(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[lson].lz += seg[idx].lz;
  seg[rson].lz += seg[idx].lz;
  seg[lson].sum += seg[idx].lz * (seg[lson].r - seg[lson].l+1);
  seg[rson].sum += seg[idx].lz * (seg[rson].r - seg[rson].l+1);
  seg[idx].lz = 0;
}

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d", &temp);
    seg[idx].sum = temp;
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  pushup(idx);
}

//Updates a single value
void update (int pos, int val, int idx){
  if(seg[idx].l == seg[idx].r){
    seg[idx].sum = val;
    return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(pos<=mid)update(pos,val,2*idx);
  else update(pos,val,2*idx+1);
  pushup(idx);
}

//ranged update with lazy propagation
void updateRange (int l, int r, int val, int idx){
  if(seg[idx].l == l && seg[idx].r==r){
    seg[idx].lz += val;
    seg[idx].sum += (ll)val*(r-l+1);
    return;
  }
  if(seg[idx].lz)pushdown(idx);
  int mid = (seg[idx].l+seg[idx].r)/2;

  if(r<=mid) updateRange(l,r,val,2*idx);
  else if(l>mid) updateRange(l,r,val,2*idx+1);
  else{
    updateRange(l,mid,val,2*idx);
    updateRange(mid+1,r,val,2*idx+1);
  }
  pushup(idx);
}

ll querySum(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].sum;
  if(seg[idx].lz)pushdown(idx);
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return querySum(l,r,2*idx);
  else if(l>mid) return querySum(l,r,2*idx+1);
  else return querySum(l,mid,2*idx) + querySum(mid+1,r,2*idx+1);
}

int main()
{
  scanf("%d %d %d", &M, &N, &Q);
  build(1,N,1);
  for(int i = 1, op, l,r,x; i <= Q; i++)
  {
    scanf("%d", &op);
    if(op==1){
      scanf("%d %d %d", &l, &r, &x);
      updateRange(l, r, x, 1);
    }else if(op==2){
      scanf("%d %d", &l, &r);
      printf("%lld\n", querySum(l, r, 1)%M);
    }
  }
  
  
  return 0;
}