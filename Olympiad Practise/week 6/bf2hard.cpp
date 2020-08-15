#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
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

const int MOD = 1e9+7, MX = 1000000 + 5;

int K, len;
char str[MX];
ll hsh[MX];
ll p[MX];
int base = 131;

ll getSubStrHash(int i, int len)
{
  return hsh[i] - (hsh[i - len] * p[len]);
}


int lexicompare(int a, int b, int len){
  if(a==-1 || b==-1)return 0;
  if(getSubStrHash(a+len-1, len)==getSubStrHash(b+len-1, len)){
    printf("same hash\n");
    return len-1;
  }
  for (int i = 0; i < len; i++)
  {
    if((str[a  + i]) > (str[b+ i]))return -i - 1;
    else if((str[a + i]) < (str[b + i]))return i;
  }
  return len - 1;
}

int charcount[500];

int main()
{
  scanf("%s", str);
  scanf("%d", &K);
  len = strlen(str);

    p[0] = 1;
  for (int i = 1; i <= len; i++)
    hsh[i] = hsh[i - 1] * base + str[i - 1] - 'A';
  for (int i = 1; i <= len; i++)
    p[i] = p[i - 1] * base;

  for (int i = len - K; i < len; i++)
  {
    charcount[str[i]]++;
  }
  for (char c = 'b'; c < 'z'; c++)
  {
    charcount[c]+=charcount[c-1];
  }

  for (char c = 'a'; c <= 'z'; c++)
  {
    int minPos = -1;
    for (int i = 0; i < len - K + 1; i++)
    {
      if(str[i] == c){
        int temp = lexicompare(i, minPos, K);
        if(temp < 0){
          if(i < len - K * 2 + 1 || charcount[c-1] == 0)
            i-=(temp+1);
        }else{
          minPos = i;
          if(i < len - K * 2 + 1 || charcount[c-1] == 0)
            i+=temp;
        }
      }
    }

    if(minPos != -1){
      for (int i = 0; i < K; i++)
      {
        printf("%c", str[minPos + i]);
      }
      printf("\n");
      return 0;
    }
  }
  

  
  
  return 0;
}