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

const int MOD = 1000000007, MX = 100000 + 5;

int N, M;
int a[MX];
struct node{
  int l,r,max;
  ll sum;
}seg[3*MX];

void pushup(int idx){
  int lson = 2*idx, rson = 2*idx+1;
  seg[idx].max = max(seg[lson].max, seg[rson].max);
  seg[idx].sum = seg[lson].sum + seg[rson].sum;
}

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d ", &temp);
    seg[idx].max = temp;
    seg[idx].sum = temp;
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  pushup(idx);
}

//Range update
//squares and floors between l and r. 
void updateSquare(int l, int r, int idx){
  if(seg[idx].max <= 1)return; //This line is specific for this question
  if(seg[idx].l == seg[idx].r){
    seg[idx].max = seg[idx].sum = sqrt(seg[idx].sum);return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid)updateSquare(l,r,2*idx);
  else if(l>mid) updateSquare(l,r,2*idx+1);
  else updateSquare(l,mid,2*idx), updateSquare(mid+1, r, 2*idx+1);
  pushup(idx);
}

//Updates a single value
void update (int pos, int val, int idx){
  if(seg[idx].l == seg[idx].r){
    seg[idx].max = val;
    seg[idx].sum = val;
    return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(pos<=mid)update(pos,val,2*idx);
  else update(pos,val,2*idx+1);
  pushup(idx);
}

//range minimum query
int queryMax(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].max;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return queryMax(l,r,2*idx);
  else if(l>mid) return queryMax(l,r,2*idx+1);
  else return max(queryMax(l,mid,2*idx), queryMax(mid+1,r,2*idx+1));
}

ll querySum(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].sum;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return querySum(l,r,2*idx);
  else if(l>mid) return querySum(l,r,2*idx+1);
  else return querySum(l,mid,2*idx) + querySum(mid+1,r,2*idx+1);
}



int main()
{
  scanf("%d", &N);
  build(1,N,1);
  scanf("%d", &M);
  for(int i = 1, op, l, r; i <= M; i++)
  {
    scanf("%d %d %d", &op, &l, &r);
    if(op==1)printf("%lld\n", querySum(l,r,1));
    else updateSquare(l,r,1);
  }
  
  return 0;
}