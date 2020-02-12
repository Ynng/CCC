#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char n[200005];
char h[200005];
int nLen, hLen;
long long output;
int main()
{
  scanf("%s", n);
  scanf("%s", h);
  nLen = strlen(n);
  hLen = strlen(h);
  output = 0;

  sort(n, n + nLen);
  do
  {
    // printf("%s\n", n);
    if (strstr(h, n))
      output++;
  } while (next_permutation(n, n + nLen));

  printf("%lld", output);
  return 0;
}
