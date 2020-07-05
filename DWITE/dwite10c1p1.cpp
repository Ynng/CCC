#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
// #define DEBUG

using namespace std;
typedef long long ll;

int d, m, y;

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 5; i++)
  {
    int age;
    scanf("%d %d %d", &d, &m, &y);
    age = 2010 - y;
    if(m > 10 || (m == 10 && d > 27)){
      age--;
    }
    if(age >= 13){
      printf("old enough\n");
    }else{
      printf("too young\n");
    }
  }
  return 0;
}
