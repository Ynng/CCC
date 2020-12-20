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

const int MX = 10000 + 5;
int MOD = 1000000007;

struct node{
  int l,r;
  ll sum, lzAdd, lzMulti = 1;//lz -> lazy propagation
}seg[3*MX];

void pushup(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[idx].sum = (seg[lson].sum + seg[rson].sum)%MOD;
}

void pushdown(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[lson].lzAdd += seg[idx].lzAdd;
  seg[rson].lzAdd += seg[idx].lzAdd;
  seg[lson].sum = (seg[lson].sum + seg[idx].lzAdd * (seg[lson].r - seg[lson].l+1))%MOD;
  seg[rson].sum = (seg[rson].sum + seg[idx].lzAdd * (seg[rson].r - seg[rson].l+1))%MOD;
  seg[idx].lzAdd = 0;

  seg[lson].lzMulti *= seg[idx].lzMulti;
  seg[rson].lzMulti *= seg[idx].lzMulti;

  seg[lson].sum = (seg[lson].sum * seg[idx].lzMulti)%MOD;
  seg[rson].sum = (seg[rson].sum * seg[idx].lzMulti)%MOD;

  seg[idx].lzMulti = 1;
}

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d", &temp);
    seg[idx].sum = temp%MOD;
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  pushup(idx);
}

//ranged update with lazy propagation
void updateRangeAdd (int l, int r, int val, int idx){
  if(seg[idx].lzAdd || seg[idx].lzMulti != 1)pushdown(idx);
  if(seg[idx].l == l && seg[idx].r==r){
    seg[idx].lzAdd = (seg[idx].lzAdd+val)%MOD;
    seg[idx].sum = (seg[idx].sum + (ll)val*(r-l+1))%MOD;
    return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;

  if(r<=mid) updateRangeAdd(l,r,val,2*idx);
  else if(l>mid) updateRangeAdd(l,r,val,2*idx+1);
  else{
    updateRangeAdd(l,mid,val,2*idx);
    updateRangeAdd(mid+1,r,val,2*idx+1);
  }
  pushup(idx);
}

//ranged update with lazy propagation
void updateRangeMulti (int l, int r, int val, int idx){
  if(seg[idx].lzAdd || seg[idx].lzMulti != 1)pushdown(idx);
  if(seg[idx].l == l && seg[idx].r==r){
    seg[idx].lzMulti = (seg[idx].lzMulti * val)%MOD;
    seg[idx].sum = (seg[idx].sum * (ll)val) % MOD;
    return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;

  if(r<=mid) updateRangeMulti(l,r,val,2*idx);
  else if(l>mid) updateRangeMulti(l,r,val,2*idx+1);
  else{
    updateRangeMulti(l,mid,val,2*idx);
    updateRangeMulti(mid+1,r,val,2*idx+1);
  }
  pushup(idx);
}

ll querySum(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].sum;
  if(seg[idx].lzAdd || seg[idx].lzMulti != 1)pushdown(idx);
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return querySum(l,r,2*idx);
  else if(l>mid) return querySum(l,r,2*idx+1);
  else return querySum(l,mid,2*idx) + querySum(mid+1,r,2*idx+1);
}

int N, M;
int main()
{
  scanf("%d %d", &N, &MOD);
  build(1,N,1);
  scanf("%d", &M);
  for(int i = 1, op, L, R, x; i <= M; i++)
  {
    scanf("%d", &op);
    if(op==1){
      scanf("%d %d %d", &L, &R, &x);
      updateRangeMulti(L, R, x, 1);
    }else if(op==2){
      scanf("%d %d %d", &L, &R, &x);
      updateRangeAdd(L, R, x, 1);
    }else if(op == 3){
      scanf("%d %d", &L, &R);
      printf("%lld\n", querySum(L, R, 1)%MOD);
    }
  }

  return 0;
}