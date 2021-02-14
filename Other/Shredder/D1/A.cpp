#include <iostream>
int foo()
{
  std::cout << "foo" << std::endl;
  return 1;
}
int bar()
{
  std::cout << "bar" << std::endl;
  return 2;
}
int main()
{
  // Think about if which one of foo() and bar() will be called first.
  // Is it in the C++ standard?
  std::cout << foo() + bar() << std::endl;
  return 0;
}
