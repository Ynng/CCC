#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char n[200005];
char h[200005];
int nLen, hLen;
long long output;
bool continueIt;
map<string, int> dp;
int charCount[200];
int needleCharCount[200];
int bad[200005];

void findString()
{
  for (int i = 0; i <= hLen - nLen; i++)
  {
    if (bad[i])
      continue;
    else
    {
      if (dp[string(h + i, nLen)] == 0)
      {
        // printf("%s\n", string(h + i, nLen).c_str());
        output++;
        dp[string(h + i, nLen)] = 1;
      }
    }
  }
}

int main()
{
  scanf("%s", n);
  scanf("%s", h);
  nLen = strlen(n);
  hLen = strlen(h);
  output = 0;

  if (nLen > hLen)
  {
    printf("0");
    return 0;
  }
  for (int i = 0; i < nLen; i++)
  {
    needleCharCount[n[i]]++;
  }
  for (int i = 0; i < nLen; i++)
  {
    charCount[h[i]]++;
  }
  for (int j = 97; j <= 122; j++)
  {
    if (charCount[j] != needleCharCount[j])
    {
      bad[0] = 1;
      break;
    }
  }
  for (int i = 1; i <= hLen - nLen; i++)
  {
    charCount[h[i - 1]]--;
    charCount[h[i + nLen - 1]]++;
    for (int j = 97; j <= 122; j++)
    {
      if (charCount[j] != needleCharCount[j])
      {
        bad[i] = 1;
        break;

      }
    }
    // if(charCount[h[i-1]]!=needleCharCount[h[i-1]] || charCount[h[i+nLen-1]]!=needleCharCount[h[i+nLen-1]]){
    //   bad[i] = 1;
    //   continue;
    // }
  }

  // for (int i = 0; i < hLen; i++)
  // {
  //   printf("bad: %d\n", bad[i]);
  // }

  // sort(n, n + nLen);
  // do
  // {

  //   if (continueIt)
  //     continue;
  //   // printf("%s\n", n);
  //   if (strstr(h, n))
  //     output++;
  // } while (next_permutation(n, n + nLen));

  findString();
  printf("%lld", output);
  return 0;
}
