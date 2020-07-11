#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAXN 100005
// #define DEBUG

int N, Q;
ll score[MAXN];
ll freq[MAXN];
int main()
{
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%lld", score + i);

  for (int i = 0, start, end; i < Q; i++)
  {
    scanf("%d %d", &start, &end);
    freq[start]++;
    freq[end + 1]--;
  }

  for (int i = 0; i <= N; i++)
    freq[i] += freq[i - 1];

  sort(score + 1, score + N + 1);
  sort(freq + 1, freq + N + 1, greater<int>());

  ll sum = 0;
  for (int i = 1; i <= N; i++)
    sum += score[i] * freq[i];

  printf("%lld", sum);

  return 0;
}