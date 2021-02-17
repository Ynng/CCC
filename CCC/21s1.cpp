#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 10000 + 5;

int N;
int h[MX];
ll sum;
int main()
{
  scanf("%d", &N);
  for (int i = 0; i <= N; i++)
    scanf("%d", h + i);
  for (int i = 0, w; i < N; i++)
  {
    scanf("%d", &w);
    sum += (h[i] + h[i + 1]) * w;
  }
  printf("%lld", sum / 2);
  if (sum % 2)
    printf(".5");
  printf("\n");
  return 0;
}