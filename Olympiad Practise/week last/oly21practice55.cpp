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

const int MOD = 1000000007, MX = 500 + 5;

char str[MX];
vi revmap[256];

bool freq[256];
int freqc;

int main()
{
  scanf("%s", str);
  int slen = strlen(str);
  for (int i = 0; i < slen; i++)
  {
    char c = str[i];
    revmap[c].push_back(i);
  }

  int len = 1;
  for (int c = 'a'; c <= 'z'; c++)
  {
    if(revmap[c].empty()){
      printf("%c\n", c);
      return 0;
    }
  }

  for (int c = 'a'; c <= 'z'; c++){
    freqc = 0;
    for (int c2 = 'a'; c2 <= 'z'; c2++)
      freq[c2] = 0;
    
    for(int idx : revmap[c]){
      if(idx == slen-1)continue;
      if(!freq[str[idx+1]])
        freqc++;
      freq[str[idx+1]] = true;
      if(freqc==26)break;
    }
    if(freqc==26)continue;
    printf("%c", c);
    for (int c2 = 'a'; c2 <= 'z'; c2++)
    {
      if(!freq[c2]){
        printf("%c", c2);
        break;
      }
    }
    break;
  }

  printf("\n");

  return 0;
}