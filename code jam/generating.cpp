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

char input[100];
int N;
int main(){
  scanf("%s", input);
  scanf("%d", &N);
  int l, r;
  int t1, t2;
  for (int n = 0; n < N; n++)
  {
    t1 = rand() % strlen(input);
    t2 = rand() % strlen(input);
    l = t1<t2?t1:t2;
    r = t1>t2?t1:t2;
    for (int i = 0; i < l; i++)
    {
      printf("%c", input[i]);
    }
    printf("*");
    for (int i = r; i < strlen(input); i++)
    {
      printf("%c", input[i]);
    }
    printf("\n");
    
  }
  
  scanf("%d", &N);
  
  
}