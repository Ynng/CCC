#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char n[400005];
char h[400005];
int nLen, hLen;
long long output;
map<string, int> dp;
bool continueIt, breakIt;
bool letters[50];
int table[125];
int a,b,shift;
int main()
{
  scanf("%s", n);
  scanf("%s", h);
  nLen = strlen(n);
  hLen = strlen(h);
  output = 0;

  for (int i = 0; i < hLen; i++)
  {
    if (letters[h[i]] == false)
      letters[h[i]] = true;
  }
  for (int i = 0; i < nLen; i++)
  {
    if (letters[n[i]] == false)
    {
      printf("0");
      return 0;
    }
  }

  sort(n, n + nLen);

  do
  {
    // printf("%s\n", n);
    continueIt = false;
    for (int i = 1; i <= nLen; i++)
    {
      // printf("%s\n",string(n,i).c_str());
      if (dp[string(n, i)] == -1)
      {
        continueIt = true;
        break;
      }
      else if (dp[string(n, i)] == 0)
      {
        dp[string(n, i)] = strstr(h, string(n, i).c_str()) ? 1 : -1;
      }
    }
    if (continueIt)
      continue;

    for (int i = 0; i < 125; i++)
    {
      table[i] = nLen;
    }
    for (int i = 0; i < nLen - 1; i++)
    {
      table[n[i]] = nLen - i - 1;
    }
    shift = table[n[nLen - 1]];
    table[n[nLen - 1]] = 0;
    memset(h + hLen, n[nLen - 1], nLen);


    a = 0;
    while (a < hLen)
    {
      b = table[h[a + nLen - 1]];
      while (b != 0)
      {
        a += b;
        b = table[h[a + nLen - 1]];
        a += b;
        b = table[h[a + nLen - 1]];
        a += b;
        b = table[h[a + nLen - 1]];
        a += b;
        b = table[h[a + nLen - 1]];
        a += b;
        b = table[h[a + nLen - 1]];
      }
      if (memcmp(n, h + a, nLen - 1) == 0 && a < hLen){
        output++;
        break;
      }
      a += shift;
    }
  } while (next_permutation(n, n + nLen));

  printf("%lld", output);
  return 0;
}
