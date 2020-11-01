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
  int l,r,min,gcd,minNum;
}seg[3*MX];

int N, M;

ll gcd (ll a, ll b){
  a = abs(a); b = abs(b);
  return b ? gcd(b, a%b) : a;
}

void build(int l, int r, int idx){
  seg[idx].l = l; seg[idx].r = r;
  if(l==r){
    int temp;
    scanf("%d", &temp);
    seg[idx].min = temp;
    seg[idx].gcd = temp;
    seg[idx].minNum = 1;
    return;
  }
  int mid = (l+r)/2;
  build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
  seg[idx].gcd = gcd(seg[2*idx].gcd, seg[2*idx+1].gcd);
  seg[idx].min = min(seg[2*idx].min, seg[2*idx+1].min);
  seg[idx].minNum = (seg[2*idx].min == seg[idx].min ? seg[2*idx].minNum : 0) + (seg[2*idx+1].min == seg[idx].min ? seg[2*idx+1].minNum : 0);
}

void update (int pos, int val, int idx){
  if(seg[idx].l == seg[idx].r){
    seg[idx].min = val;
    seg[idx].gcd = val;
    return;
  }
  int mid = (seg[idx].l+seg[idx].r)/2;
  if(pos<=mid)update(pos,val,2*idx);
  else update(pos,val,2*idx+1);
  seg[idx].gcd = gcd(seg[2*idx].gcd, seg[2*idx+1].gcd);
  seg[idx].min = min(seg[2*idx].min, seg[2*idx+1].min);
  seg[idx].minNum = (seg[2*idx].min == seg[idx].min ? seg[2*idx].minNum : 0) + (seg[2*idx+1].min == seg[idx].min ? seg[2*idx+1].minNum : 0);
}

//range minimum query
int queryMin(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].min;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return queryMin(l,r,2*idx);
  else if(l>mid) return queryMin(l,r,2*idx+1);

  return min(queryMin(l,mid,2*idx), queryMin(mid+1,r,2*idx+1));
}

//query the number of elements equal to the minimum
int queryMinNum(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].minNum;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return queryMinNum(l,r,2*idx);
  else if(l>mid) return queryMinNum(l,r,2*idx+1);
  
  int minL = queryMin(l,mid,2*idx), minR = queryMin(mid+1,r,2*idx+1);
  int minNumL = queryMinNum(l,mid,2*idx), minNumR = queryMinNum(mid+1,r,2*idx+1);
  if(minL < minR) return minNumL;
  else if(minL > minR) return minNumR;
  else return minNumL + minNumR;
}

//range GCD (greatest common denominator) query
int queryGCD(int l, int r, int idx){
  if(seg[idx].l == l && seg[idx].r == r)
    return seg[idx].gcd;

  int mid = (seg[idx].l+seg[idx].r)/2;
  if(r<=mid) return queryGCD(l,r,2*idx);
  else if(l>mid) return queryGCD(l,r,2*idx+1);
  
  return gcd(queryGCD(l,mid,2*idx), queryGCD(mid+1,r,2*idx+1));
}


int main()
{
  scanf("%d %d", &N, &M);
  build(1,N,1);

  for(int i = 1,x,y; i <= M; i++)
  {
    char op;
    scanf(" %c %d %d", &op, &x, &y);
    if(op=='C') update(x,y,1);
    if(op == 'M') printf("%d\n", queryMin(x,y,1));
    if(op == 'G') printf("%d\n", queryGCD(x,y,1));
    //"Number of elements between l and r that is equal to GCD"
    if(op == 'Q'){
      int gcd = queryGCD(x,y,1);
      int mi = queryMin(x,y,1);
      if(gcd == mi)printf("%d\n", queryMinNum(x,y,1));
      else printf("0\n");
    }
  }
  
  return 0;
}