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

int main(int argc, const char **argv)
{

  int n;
  scanf("%d", &n);
  if(n % 4 == 0){
    printf("Yes");
  }else if(n % 2 != 0 && ((n + 1) / 2) % 2 == 0){
    printf("Yes");
  }else
  {
    printf("No");
  }
  return 0;
}