#include <iostream>
void SomeFunctionWithSideEffects(){
}
void foo()
{
  // doesn’t this infinite loop look suspicious to you?
  for (;;)
  {
    SomeFunctionWithSideEffects();
  }
}
int main()
{
  foo();
  return 0;
}