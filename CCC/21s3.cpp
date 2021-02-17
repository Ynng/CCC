#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LIMIT = 1000000000, MX = 200000 + 5;

int N;
int P[MX];
int W[MX];
int D[MX];
//Binary search for answer
//nlogn overall

//linear time
ll getAnswer(int pos)
{
  ll sum = 0;
  for (int i = 1; i <= N; i++)
  {
    ll diff = abs(pos - P[i]);
    if (diff <= D[i])
      continue;
    sum += (diff - D[i]) * W[i];
  }
  return sum;
}

int l = LIMIT, r = 0;
int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d %d %d", P + i, W + i, D + i);
    l = P[i] < l ? P[i] : l;
    r = P[i] > r ? P[i] : r;
  }

  int m = -1;
  ll prv, cur = 0, nxt;
  while (l < r)
  {
    m = (l + r) / 2;
    prv = getAnswer(m - 1), cur = getAnswer(m), nxt = getAnswer(m + 1);
    if (prv > cur && cur > nxt) //move right
      l = m;
    else if (prv < cur && cur < nxt) //move left
      r = m;
    else //found answer
      break;
  }

  printf("%lld\n", cur);

  return 0;
}