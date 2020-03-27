#include <iostream>
#include <map>
#include <vector>

#include <math.h>

int a, b;
int counter = 0;
int n;
int temp;
std::map<int, int> primes;
// std::map<int, int> primeCounter;
int maxPossible = -1;
int main()
{
  scanf("%d %d", &a, &b);
  n = a;
  while (n % 2 == 0)
  {
    primes[2]++;
    n = n / 2;
  }

  for (int i = 3; i <= sqrt(n); i = i + 2)
  {
    // While i divides n, print i and divide n
    while (n % i == 0)
    {
      primes[i]++;
      n = n / i;
    }
  }

  if (n > 2)
    primes[n]++;

  for (std::map<int, int>::iterator iter = primes.begin(); iter != primes.end(); ++iter)
  {
    temp = iter->first;
    counter = 0;
    while (temp <= b)
    {
      counter += b / temp;
      temp *= iter->first;
    }
    // printf("prime is %d and temp is %d\n", iter->first, temp);
    // printf("counter is %d\n", counter);
    // printf("there are %d %ds\n", iter->second, iter->first);


    if (maxPossible == -1 || counter / iter->second < maxPossible)
    {
      maxPossible = counter / iter->second;
    }

    //ignore value
    //Value v = iter->second;
  }

  printf("%d", maxPossible);
}
