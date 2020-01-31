/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <functional>

std::vector<std::function<bool()>> auton;

class TestingClass
{
private:
  bool value;

public:
  TestingClass(bool a)
  {
    value = a;
  }

  bool get()
  {
    return value;
  }

  void invert()
  {
    value = !value;
  }
};

bool printStuffs(){
  printf("I printed stuffs and return false\n");
  return false;
}

int main()
{
  TestingClass test(false);

  auton.push_back([&] {
    return true || false;
  });
  auton.push_back([&] {
    return test.get();
  });
  auton.push_back([&] {
    return printStuffs();
  });
  printf("Length:%d\n", auton.size());
  if (auton[0]())
  {
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }

  if (auton[1]())
  {
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }

  test.invert();

  printf("invertted\n");

  if (auton[1]())
  {
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }

  
  if (auton[2]())
  {
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }

  return 0;
}
