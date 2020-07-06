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

int m;

int main(int argc, const char** argv) {
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &m);
    int sum = ((m+1) * (m+2))/2;
    for (int j = 0; j < m; j++)
    {
      int temp;
      scanf("%d", &temp);
      sum-=temp;
    }
    printf("%d\n", sum);
  }  
  return 0;
}