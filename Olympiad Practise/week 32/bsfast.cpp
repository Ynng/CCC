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

const int MOD = 1000000007, MX = 1000000 + 5;

struct node{
  int l,r;
  ll mi, lz;//lz -> lazy propagation
}seg[3*MX];
int N, Q, A[MX];

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

int tempBuild = 1;
void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    seg[idx].mi = A[tempBuild];
    tempBuild++;
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

int main()
{
  scanf("%d %d", &N, &Q);
  for(int i = 1; i <= N; i++)
    scanf("%d", A+i);
  build(1,N,1);

  int lastAns = 0;
  for(int i = 1; i <= Q; i++)
  {
    int op;
    scanf("%d", &op);
    if(op==1){
      int p, x;
      scanf("%d %d", &p, &x);
      p^=lastAns;
      x^=lastAns;
      A[p] = x;
      update(p, x, 1);
    }else if(op==2){
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      l^=lastAns;
      r^=lastAns;
      k^=lastAns;

      int m = -1;
      while(l < r){
        m = (l+r)/2;
        int mi = queryMin(l, m, 1);
        if(mi < k){
          r = m;
        }else{
          l = m+1;
        }
      }
      m = (l+r)/2;
      printf("%d\n", m);
      lastAns = m;
      // for (int i = l; i <= r; i++)
      // {
      //   if(A[i]<k){
      //     printf("%d\n", i);
      //     lastAns = i;
      //     break;
      //   }
      // }
    }
  }

  return 0;
}