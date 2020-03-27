#include <iostream>

int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if(a < (b + c) && c < (a + b) && b < (a + c))
    printf("yes");
  else
    printf("no");
  return 0;
}
