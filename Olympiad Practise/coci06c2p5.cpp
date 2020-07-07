#include <iostream>
#define MAXN 405

int R, C;
int a[MAXN][MAXN];
int cur[MAXN][MAXN], maxi[MAXN][MAXN];

int main()
{
  scanf("%d %d", &R, &C);
  char input;
  for (int i = 1; i <= R; i++)
  {
    for (int j = 1; j <= C; j++)
    {
      scanf(" %c", &input);
      if(input == 'X')
        a[i][j] = 0;
      else
        a[i][j] = 1 + a[i - 1][j];
    }
  }

  int output = 0;
  int temp, last = 0;
  for (int i = 1; i <= R; i++)
  {
    last = 0;
    for (int j = 1; j <= C + 1; j++)
    {
      if (a[i][j] < last)
      {
        for (int k = last - 1; k >= a[i][j]; k--)
        {
          cur[i][k] += cur[i][k + 1];
          if (cur[i][k + 1] > maxi[i][k + 1])
            maxi[i][k + 1] = cur[i][k + 1];
          cur[i][k + 1] = 0;
        }
      }

      cur[i][a[i][j]]++;
      last = a[i][j];
    }

    for (int k = 1; k <= i; k++)
    {
      if (maxi[i][k] != 0)
      {
        temp = 2 * (maxi[i][k] + k) - 1;
        if (temp > output)
          output = temp;
      }
    }
  }
  printf("%d", output);
  return 0;
}