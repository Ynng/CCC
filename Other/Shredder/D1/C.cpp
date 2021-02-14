#include <iostream>
int isPositive(int *num)
{
  return *num > 0; // is this defined all the time?
}
int main()
{
  // invocation of ::isPositive not shown
  int t;
  scanf("%d", &t);
  printf("%d", isPositive(&t));
}
