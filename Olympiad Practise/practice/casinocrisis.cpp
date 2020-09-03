#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9 + 7, MX = 2000 + 5;

int N, Q;
int arr[MX];
vector<pi> answer;
list<int> sorted;
int main()
{
  scanf("%d %d", &N, &Q);

  for (int i = 1; i <= N; i++)
    scanf("%d", arr + i);

  sorted.push_back(arr[1]);
  for (int i = 2; i <= N; i++)
  {
    if (arr[i] > sorted.back()){
      sorted.push_back(arr[i]);
      continue;
    }

    int iloc = 0;

    for (auto it = sorted.begin(); it != sorted.end(); it++)
    {
      iloc++;
      if ((*it) > arr[i])
      {
        sorted.insert(it, arr[i]);
        break;
      }
    }

    answer.push_back({iloc, i});
    if (iloc != i - 1)
      answer.push_back({iloc, i - 1});
  }

  printf("%d\n", answer.size());
  for (int i = 0; i < answer.size(); i++)
  {
    printf("%d %d\n", answer[i].f, answer[i].s);
  }

  return 0;

  int sorting[MX];
  //Self checking
  printf("\n");
  for (int i = 0; i < answer.size(); i++)
  {
    int a = answer[i].f, b = answer[i].s;
    int sortinglen = b-a+1;
    memset(sorting, 0, sizeof(sorting));
    memcpy(sorting, arr + a, sortinglen * sizeof(int));
    sort(sorting, sorting+b-a+1);
    for (int j = 0; j < sortinglen/2; j++)
    {
      int ai, bi;
      for (int k = a; k <= b; k++)
      {
        if(arr[k] == sorting[j]){
          ai = k;
        }
        if(arr[k] == sorting[sortinglen - j - 1]){
          bi = k;
        }
      }
      
      int temp = arr[ai];
      arr[ai] = arr[bi];
      arr[bi] = temp;
    }

    for (int j = 1; j <= N; j++)
    {
      printf("%d ", arr[j]);
    }
    printf("\n");
  }
  
}