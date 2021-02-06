#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007, MX = 20 + 5;

int T, st, ed;
int shift[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int output[MX][MX];

int numberLength(int n)
{
  int length = n>0;
  while (n /= 10)
    length++;
  return length;
}

void solve()
{
  memset(output, 0, sizeof(output));
  scanf("%d %d", &st, &ed);

  int length = 0;
  int direction = 0;

  int row = 10, col = 10;
  int b = row, t = row;
  int l = col, r = col;
  int cur = st + 1;
  output[row][col] = st;

  while (cur <= ed)
  {
    direction = (direction + 1) % 4;
    if (direction % 2)
      length++;

    for (int j = 0; j < length && cur <= ed; j++)
    {
      row += shift[direction][0];
      col += shift[direction][1];
      output[row][col] = cur;
      output[0][col] = max(output[0][col], numberLength(cur));
      b = min(row, b); t = max(row, t); l = min(col, l); r = max(col, r);
      cur++;
    }
  }

  for (int i = b; i <= t; i++)
  {
    for (int j = l; j <= r; j++)
    {
      cur = output[i][j];
      for (int k = numberLength(cur); k < output[0][j]; k++)
        printf(" ");
      if(cur)printf("%d", cur);
      if(j!=r)printf(" ");
    }
    printf("\n");
  }
}

int main()
{
  scanf("%d", &T);
  while(T--){
    solve();
    if(T)printf("\n");
  }
  return 0;
}