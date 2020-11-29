//brute force
//4^4 = 256 possibilities for each case
//Try all permutations next_permutation()

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

const int MOD = 1000000007, MX = 10000 + 5;

int N, card[4], ans;

void check(int val){
  if(val<=24)ans = max(val, ans);
}

void fun(int cur, int nxt, int idx){
  if(idx==3){
    check(cur+nxt);
    check(cur-nxt);
    check(cur*nxt);
    if(nxt!=0&&cur%nxt==0)check(cur/nxt);
    return;
  }

  fun(cur+nxt, card[idx+1], idx+1);
  fun(cur-nxt, card[idx+1], idx+1);
  fun(cur*nxt, card[idx+1], idx+1);
  if(nxt!=0 && cur%nxt == 0) fun(cur/nxt, card[idx+1], idx+1);
  fun(cur, nxt+card[idx+1], idx+1);
  fun(cur, nxt-card[idx+1], idx+1);
  fun(cur, nxt*card[idx+1], idx+1);
  if(card[idx+1] != 0 && nxt%card[idx+1] == 0) fun(cur, nxt/card[idx+1], idx+1);
}

int main()
{
  scanf("%d ", &N);
  for(int i = 1; i <= N; i++)
  {
    ans = 0;
    for(int j = 0; j <= 3; j++)
      scanf("%d ", &card[j]);
    sort(card, card+4);
    do{
      fun(card[0], card[1], 1);
    }
    while(next_permutation(card, card+4));

    printf("%d\n", ans);
  }
  
  return 0;
}