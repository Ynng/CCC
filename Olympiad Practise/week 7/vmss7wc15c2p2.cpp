#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
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

const int MOD = 1e9 + 7, MX = 25000 + 5;

int N;
ll hsh[MX], hshi[MX];
ll p[MX];
int base = 131;
char S[MX];

ll getSubStrHash(int i, int len)
{
  return hsh[i] - (hsh[i - len] * p[len]);
}

ll getSubStrHashI(int i, int len)
{
  return hshi[i] - (hshi[i + len] * p[len]);
}

int main()
{
  scanf("%d", &N);
  scanf("%s", S);

  p[0] = 1;
  for (int i = 1; i <= N; i++)
    hsh[i] = hsh[i - 1] * base + S[i - 1] - 'A';
  for (int i = N; i >= 1; i--)
    hshi[i] = hshi[i + 1] * base + S[i - 1] - 'A';
  for (int i = 1; i <= N; i++)
    p[i] = p[i - 1] * base;

  int longest = 0;
  int l, r;
  for(int i = 1; i <= 2*N; i++){
    int j=0;
    int fi = ceil(i/2.0), ii = i/2;
    while(ii-j>=1 && fi+j<=N){
      //palindrome check
      if (getSubStrHash(ii, j+1) == getSubStrHashI(fi, j+1)){
        int length = (fi+j) - (ii-j) + 1;
        if(length > longest){
          longest = length;
          l = ii-j;
          r = fi+j;
        }
        j++;
      }else{
        break;
      }

    }
  }

  for (int i = l-1; i < r; i++)
  {
    printf("%c", S[i]);
  }
  
  printf("\n%d\n", longest);

  return 0;
}