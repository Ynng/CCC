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

const int MOD = 1000000007, MX = 10000 + 5;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeLists(ListNode *A, ListNode *B){
  ListNode *m;
  while(A || B){
    if(A->val < B->val){
      m->next = A;
      A = A->next;
    }else{
      m->next = B;
      B = B->next;
    }
  }
  if(A)
}


// your function
ListNode *mergeKLists(vector<ListNode *> &lists)
{
  int len = lists.size();
  for (int i = 1; i < len; i++)
  {
    ListNode *A = lists[0];
    ListNode *B = lists[i];
    
    lists[0] = mergeLists(A, B);
  }
}

int main()
{
  ListNode c1(5), b1(4, &c1), a1(1, &b1);
  ListNode c2(4), b2(3, &c2), a2(1, &b2);
  ListNode b3(6), a3(2, &b3);

  vector<ListNode *> lists;
  lists.push_back(&a1);
  lists.push_back(&a2);
  lists.push_back(&a3);

  ListNode* answer = mergeKLists(lists);
  while(answer){
    printf("%d ", answer->val);
    answer = answer->next;
  }
  
  return 0;
}