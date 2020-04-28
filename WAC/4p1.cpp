#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <fstream>
#include <queue>
#include <unordered_map>

int N, Q;
int a[205];
int main(){
  scanf("%d %d", &N, &Q);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &a[i+1]);
  }
  

  int op, l, r;
  for (int i = 0; i < Q; i++)
  {
    scanf("%d %d %d", &op, &l, &r);
    if(op==2)//desceing order
      std::sort(std::begin(a)+l, std::begin(a)+r+1, std::greater<int>());
    else
      std::sort(std::begin(a)+l, std::begin(a)+r+1, std::less<int>());
  }

  
  for (int i = 0; i < N-1; i++)
  {
    printf("%d ", a[i+1]);
  }
  printf("%d\n", a[N]);
}