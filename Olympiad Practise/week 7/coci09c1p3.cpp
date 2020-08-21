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

const int MOD = 1e9 + 7, MX = 100 + 5;

char str[MX];
int arr[MX];
int len;
int _count;

bool checkValid(int *tri){
  int Lcount = 0, count = 0;
  if(arr[0] == 2 || arr[1] == 2)Lcount++;
  int last = -10, last2 = -10;
  for (int i = 0; i < len; i++)
  {
    int cur = arr[i];
    if(cur < 0){
      cur = tri[count];
      count++;
    }
    if(cur == 2){
      Lcount++;
      cur = 1;  
    }

    if(cur == last && last == last2)return false;

    last2 = last;
    last = cur;
  }
  if(Lcount == 0)return false;
  return true;
}

ll getCombination(int* tri){
  ll comb = 1;
  for (int i = 0; i < _count; i++)
  {
    if(tri[i] == 1)comb*=20;
    else if(tri[i] == 0)comb*=5;
  }
  return comb;
}

int main()
{
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
      arr[i] = 0;
    else if (str[i] == 'L')
      arr[i] = 2;
    else if (str[i] == '_')
    {
      arr[i] = -1;
      _count++;
    }
    else
      arr[i] = 1;
  }

  int bruteForce = pow(3, _count) - 1;
  ll total = 0;
  while (bruteForce >= 0)
  {
    int num = bruteForce;
    int tri[15];
    int o = 0;
    memset(tri, 0, sizeof(tri));
    while (num > 0)
    {
      tri[o] = num % 3;
      num = num / 3;
      o++;
    }

    if(checkValid(tri)){
      total+=getCombination(tri);
    }

    bruteForce--;
  }


  printf("%lld", total);
}