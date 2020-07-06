// Doesn't work, useless

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

int a[20];


void generate()
{
  for (int i = 0; i < 20; i++)
  {
    a[i] = std::rand() % 100;
  }
}

int main(int argc, char const *argv[])
{

  generate();
  std::sort(a, a+20);
  
  for (int i = 0; i < 20; i++)
  {
    printf("%d " , a[i]);
  }

  int i = 2;
  int last = a[0];
  int sum = 0;
  int highest;
  int interval = 2;
  for (; i < 20; i+=interval)
  {
    sum+=(last - a[i]) * (last - a[i]);
    last = a[i];
    highest = 1;
  }
  i = 19;
  if(highest == 19)
    i = 18;
  sum+=(last - a[i]) * (last - a[i]);
  last = a[i];
  for (; i > 0; i-=interval)
  {
    sum+=(last - a[i]) * (last - a[i]);
    last = a[i];
  }
  printf("\n sum = %d", sum);
  
  int bruh;
  scanf("%d", &bruh);

  return 0;
}
