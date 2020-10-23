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

const int MOD = 1e9+7, MX = 100000 + 5;
const int MAX = 1000000000;

int N, M, L;
int m[MX], l[MX];
int max1[MX], max2[MX];
int pos1[MX], pos2[MX];
int main()
{
  //I Hate implementation questions
  scanf("%d %d", &N, &M);
  L = min(M, N);
  M = max(M, N);
  if(M==N){
    for(int i = 1; i <= M; i++)
      scanf("%d", m+i);
    for(int i = 1; i <= L; i++)
      scanf("%d", l+i);
  }else{
    for(int i = 1; i <= L; i++)
      scanf("%d", l+i);
    for(int i = 1; i <= M; i++)
      scanf("%d", m+i);
  }
  sort(m+1, m+1+M);
  sort(l+1, l+1+L);
  int cur = 1;
  int maxdif1 = 0;
  for(int i = 1; i<=L; i++){
    int mindif = MAX;
    int correctCur;
    for (; cur <= M; cur++)
    {
      if(abs(l[i] - m[cur]) < mindif){
        mindif = abs(l[i] - m[cur]);
        correctCur = cur;
        pos1[cur] = i;
      }
      else
        break;
    }
    if(maxdif1 == MAX){
      maxdif1 = MAX;
      break;
    }
    max1[correctCur]=max(max1[correctCur], mindif);
    maxdif1 = max(maxdif1, mindif);
  }
  int maxdif2 = 0;
  cur = M;
  for(int i = L; i>=1; i--){
    int mindif = MAX;
    int correctCur;
    for (; cur >= 1; cur--)
    {
      if(abs(l[i] - m[cur]) < mindif){
        mindif = abs(l[i] - m[cur]);
        pos2[cur] = i;
        correctCur = cur;
      }
      else
        break;
    }
    if(mindif == MAX){
      maxdif2 = MAX;
      break;
    }
    max2[correctCur]=max(max2[correctCur], mindif);
    maxdif2 = max(maxdif2, mindif);
  }
  
  int output = MAX;

  for(int i = 1; i <= M; i++)
    max1[i]=max(max1[i-1], max1[i]);
  for (int i = M; i >= 1; i--)
    max2[i]=max(max2[i+1], max2[i]);
  
  for(int i = 1; i <= M-1; i++)
  {
    if(pos1[i]+1==pos2[i+1]){
      output = min(output, max(max1[i], max2[i+1]));
      // printf("yes %d\n", i);
    }
  }

  for(int i = 1; i <= M; i++)
  {
    // printf("%d %d %d %d\n", pos1[i], pos2[i], max1[i], max2[i]);
  }
  output = min(output, maxdif1);
  output = min(output, maxdif2);
  printf("%d\n", output);
  // printf("%d\n", maxdif1);
  // printf("%d\n", maxdif2);
  return 0;
}