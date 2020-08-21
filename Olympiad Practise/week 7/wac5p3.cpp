#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
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

const int MOD = 1e9+7, MX = 200000 + 5;

int N;
int a[MX];
int freq[MX];


int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
  {
    scanf("%d", a+i);
  }

  ll total = N;
  int temp;
  for (int i = 2; i*i <= N ; i++)
  {
    int len = i*i;
    int freq2 = 0;

    for (int j = 1; j < len; j++)
    {
      temp = freq[a[j]]++;
      if(temp == i)freq2--;
      if(temp+1 == i)freq2++;
    }
    
    for (int j = len; j <= N; j++)
    {
      temp = freq[a[j]]++;
      if(temp == i)freq2--;
      if(temp+1 == i)freq2++;

      if(freq2 == i){
        total++;
      }

      temp = freq[a[j-len+1]]--;
      if(temp == i)freq2--;
      if(temp-1 == i)freq2++;
    }

    for (int j = N - len + 1; j <= N; j++)
    {
      freq[a[j]] = 0;
    }
  }
  
  printf("%lld\n", total);
  
  return 0;
}