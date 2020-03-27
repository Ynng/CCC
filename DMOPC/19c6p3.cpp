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
#include <queue>
#include <unordered_map>

typedef long long ll;

int s, m, l, r;
bool number[500005];
char input[500005];
int jump[500005];


ll value = 0;
ll mod = 1e9 + 7;

// #define DEBUG

long long powll(long long base, long long exp)
{
  long long ans = 1;
  for (base %= mod; exp; exp >>= 1, base = (base * base) % mod)
    if (exp & 1)
      ans = (ans * base) % mod;
  return ans;
}
int main()
{
  scanf("%d %d", &s, &m);
  scanf("%s", input);
  memset(jump, 0, sizeof jump);

  #ifdef DEBUG
    printf("\n");
  #endif
  for (int i = 1; i <= s; i++)
  {
    number[i] = input[i-1] - '0';
    
    if (number[i])
      value = (value + powll(2, s-i) % mod + mod) % mod;
    #ifdef DEBUG
      printf("%d, value: %d\n", number[i], value);
    #endif
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &l, &r);
    for (int j = l; j <= r; j++)
    {
      if(jump[j]!=0){
        j=(jump[j]);
        continue;
      }
      if (number[j] == false)
      {
        number[j] = true;
        value = (value + powll(2, s-j) % mod + mod) % mod;
        jump[j] = r;
      }
    }
    #ifdef DEBUG
    for (int i = 0; i <= s-1; i++)
    {
      printf("%d", number[i]);
    }
    printf("value: %d\n",value);
    #endif
    printf("%lld\n", value);
  }
  return 0;
}