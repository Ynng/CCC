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

//segment tree
struct node{
  int l,r,val;
}seg[3*MX];

int N, M;

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d ", &temp);
    seg[idx].val = temp;
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  seg[idx].val = min(seg[2*idx].val, seg[2*idx+1].val);
}

void update (int pos, int val, int idx){
  if(seg[idx].l == seg[idx].r){
    seg[idx].val = val; return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(pos<=mid)update(pos,val,2*idx);
  else update(pos,val,2*idx+1);
  seg[idx].val = min(seg[2*idx].val, seg[2*idx+1].val);
}

//range minimum query
int query(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].val;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return query(l,r,2*idx);
  else if(l>mid) return query(l,r,2*idx+1);
  else return min(query(l,mid,2*idx), query(mid+1,r,2*idx+1));
}

int main()
{
  scanf("%d %d", &N, &M);
  build(1,N,1);

  for(int i = 1,x,y; i <= M; i++)
  {
    char op;
    scanf(" %c %d %d", &op, &x, &y);
    if(op=='M') update(x+1,y,1);
    if(op == 'Q') printf("%d\n", query(x+1,y+1,1));
  }
  
  return 0;
}