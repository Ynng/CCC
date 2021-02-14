#include <iostream>
void foo(int *data)
{
  delete data;
}
int main()
{
  delete foo(new int);
  return 0;
}