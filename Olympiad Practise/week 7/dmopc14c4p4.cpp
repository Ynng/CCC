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

const int MOD = 1e9+7, MX = 100000 + 5;

int N;
char msg[MX];
char key[30];
char keyI[30];
char H[10] = "HAILHYDRA";

vector<int> possible;

ll hsh[MX], hshH[MX];
int base = 131;
ll p[MX];
int len, lenH = 9;
int freq[1000];


ll getSubStrHashA(int i, int len)
{
  return hsh[i] - (hsh[i - len] * p[len]) ;
}

int main()
{
  scanf("%s", msg);
  scanf(" %d", &N);
  
  len = strlen(msg);

  p[0] = 1;

  for (int i = 1; i <= len; i++)
    hsh[i] = hsh[i - 1] * base + msg[i-1] - 'A';

  for (int i = 1; i <= max(len, 30); i++)
    p[i] = p[i-1]*base;

  for(int i = 0; i<lenH-1; i++)
    freq[msg[i]]++;
    
  for (int i = lenH-1; i < len; i++){
    freq[msg[i]]++;
    if(msg[i-lenH+1] == msg[i-lenH+5] && msg[i-lenH+2] == msg[i] && freq[msg[i-lenH+3]] == 1&& freq[msg[i-lenH+4]] == 1&& freq[msg[i-lenH+6]] == 1&& freq[msg[i-lenH+7]] == 1&& freq[msg[i-lenH+8]] == 1){
      possible.push_back(i+1);
    }
    freq[msg[i-lenH+1]]--;
  }


  bool keyValid = false;
  for(int k = 1; k <= N; k++)
  {
    scanf("%s", key);

    for (int i = 1; i <= lenH; i++)
      hshH[i] = hshH[i - 1] * base + key[H[i-1] - 'A']-'A';
    
    for (int i = 0; i < possible.size(); i++)
    {
      if(getSubStrHashA(possible[i], lenH) == hshH[lenH]){
        keyValid = true;
        break;
      }
    }
    if(keyValid)break;
  }

  if(!keyValid)printf("KeyNotFoundError");
  else{
    //reverting the key so we can use it revert the string
    for (int i = 0; i < 26; i++)
      keyI[key[i]-'A']=i+'A';
    
    for (int i = 0; i < len; i++)
      printf("%c", keyI[msg[i]-'A']);
  }
  printf("\n");
  
  return 0;
}