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
ll hsh[200005];
int charCount[200];
int needleCharCount[200];
int base = 131;
ll p[200005];
set<ll> ans;

bool checkSubstr()
{
  for (int i = 'a'; i <= 'z'; i++)
  {
    if (charCount[i] != needleCharCount[i])
      return false;
  }
  return true;
}

ll getSubStrHash(int i)
{
  return hsh[i] - (hsh[i - nLen] * p[nLen]) ;
}

int main()
{
  scanf("%s", n);
  scanf("%s", h);
  nLen = strlen(n);
  hLen = strlen(h);

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

  p[0] = 1;
  hsh[0] = h[0] - 'a';

  for (int i = 1; i < hLen; i++)
  {
    p[i] = p[i-1]*base;
    hsh[i] = hsh[i - 1] * base + h[i] - 'a';
  }

  if (checkSubstr())
    ans.insert(hsh[nLen - 1]);
  for (int i = nLen; i <= hLen; i++)
  {
    charCount[h[i - nLen]]--;
    charCount[h[i]]++;

    if (checkSubstr())
      ans.insert(getSubStrHash(i));
  }
  std::cout << ans.size();
  return 0;
}
