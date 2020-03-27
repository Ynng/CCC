#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
// #define DEBUG

using namespace std;
typedef long long ll;

char n[200005];
char h[200005];
int nLen, hLen;
ll output;
ll hsh[200005];
ll hsh2[200005];
int charCount[200];
int needleCharCount[200];
int base = 131, base2 = 7919;
ll diff, diff2;
ll mod = 1e9 + 7;
set<pair<ll,ll>> ans;

bool checkSubstr()
{
  for (int i = 'a'; i <= 'z'; i++)
  {
    if (charCount[i] != needleCharCount[i])
      return false;
  }
  return true;
}

ll getHash(int i)
{
  return (hsh[i]% mod - (hsh[i - nLen] * diff) % mod +mod)%mod;
}

ll getHash2(int i)
{
  return (hsh2[i]% mod - (hsh2[i - nLen] * diff2) % mod +mod)%mod;
}

long long powll(long long base, long long exp)
{
    long long ans = 1;
    for (base %= mod; exp; exp >>= 1, base = (base * base) % mod)
        if (exp&1)
            ans = (ans * base) % mod;
    return ans;
}

int main()
{
  scanf("%s", n);
  scanf("%s", h);
  nLen = strlen(n);
  hLen = strlen(h);
  output = 0;

  diff = powll(base, nLen);
  diff2 = powll(base2, nLen);

#ifdef DEBUG
  printf("diff is %lld", diff);
#endif

  if (nLen > hLen)
  {
    printf("0");
    return 0;
  }
  for (int i = 0; i < nLen; i++)
  {
    needleCharCount[n[i]]++;
    charCount[h[i]]++;
  }
  hsh2[0] = hsh[0] = h[0] - 'a' + 1;
  for (int i = 1; i < hLen; i++)
  {
    hsh[i] = ((hsh[i - 1] * base + h[i] - 'a' + 1) % mod + mod) % mod;
    hsh2[i] = ((hsh2[i - 1] * base2 + h[i] - 'a' + 1) % mod + mod) % mod;
    #ifdef DEBUG
    printf("\nhash[%d] is %lld", i, hsh[i]);
    #endif
  }

  if (checkSubstr())
  {
    ans.insert({hsh[nLen - 1], hsh2[nLen - 1]});
    #ifdef DEBUG
    printf("\nadded %lld to ans", hsh[nLen - 1]);
    #endif
  }
  for (int i = nLen; i < hLen; i++)
  {
    charCount[h[i - nLen]]--;
    charCount[h[i]]++;

    #ifdef DEBUG
    printf("\n %c %c", h[i - nLen], h[i]);
    #endif

    if (checkSubstr())
    {
      ans.insert({getHash(i), getHash2(i)});
      #ifdef DEBUG
      printf("\nadded %lld to ans, i = %d", getHash(i), i);
      #endif
    }
  }
  std::cout << ans.size();
  return 0;
}
