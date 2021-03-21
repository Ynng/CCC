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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007, MX = 1000000 + 5;

struct node{
  int l,r;
  ll mi, lz;//lz -> lazy propagation
}seg[3*MX];

void pushup(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[idx].mi = min(seg[lson].mi, seg[rson].mi);
}

void pushdown(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[lson].lz += seg[idx].lz;
  seg[rson].lz += seg[idx].lz;
  seg[lson].mi -= seg[idx].lz;
  seg[rson].mi -= seg[idx].lz;
  seg[idx].lz = 0;
}

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d", &temp);
    seg[idx].mi = temp;
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  pushup(idx);
}

//Updates a single value
void update (int pos, int val, int idx){
  if(seg[idx].l == seg[idx].r){
    seg[idx].mi = val;
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
    seg[idx].mi -= val;
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

ll queryMin(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].mi;
  if(seg[idx].lz)pushdown(idx);
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return queryMin(l,r,2*idx);
  else if(l>mid) return queryMin(l,r,2*idx+1);
  else return min(queryMin(l,mid,2*idx), queryMin(mid+1,r,2*idx+1));
}

int N, M, A[MX];
int main()
{
  scanf("%d %d", &N, &M);
  build(1, N, 1);

  // for (int i = 1; i <= N; i++)
  // {
  //   scanf("%d", A + i);
  // }
  for (int i = 1, v, s, t; i <= M; i++)
  {
    scanf("%d %d %d", &v, &s, &t);
    updateRange(s,t,v,1);
    if(queryMin(s,t,1) < 0){
      printf("-1\n%d", i);
      return 0;
    }
  }
  printf("0\n");

  return 0;
}