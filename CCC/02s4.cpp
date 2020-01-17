#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int m, q, tempA, tempB, times[105], dp[105][2];
bool outputs[105] = {false};
string names[105];

int slowest(int n, int m)
{
  int temp = 0;
  for (int i = n; i <= m; i++)
  {
    temp = fmax(temp, times[i]);
  }
  return temp;
}

int main()
{
  dp[0][0] = 0;
  dp[0][1] = 0;
  times[0] = 0;

  scanf("%d", &m);
  scanf("%d", &q);

  for (int i = 1; i <= q; i++)
  {
    cin >> names[i];
    // scanf("%s", &names[i]);
    scanf("%d", &times[i]);
  }

  for (int i = 1; i <= q; i++)
  {
    tempA = INT_MAX;
    tempB = 0;
    for (int j = 1; j <= m; j++)
    {
      if (i - j >= 0)
      {
        if (dp[i - j][0] + slowest(i - j + 1, i) < tempA)
        {
          tempA = dp[i - j][0] + slowest(i - j + 1, i);
          tempB = i - j;
        }
      }
    }
    dp[i][0] = tempA;
    dp[i][1] = tempB;
  }

  // printf("\n\n\n");
  // for (int i = 1; i <= q; i++)
  // {
  //     printf("Total Time: %d\n", dp[i][0]);
  // }

  printf("Total Time: %d\n", dp[q][0]);

  tempA = q;
  while (tempA > 0)
  {
    tempA = dp[tempA][1];
    outputs[tempA] = true;
  }
  for (int i = 1; i <= q; i++)
  {
    // printf("%s", names[i]);
    cout << names[i];
    if (outputs[i])
      printf("\n");
    else
      printf(" ");
  }

  return 0;
}