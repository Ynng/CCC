#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int grid[2005][2005];
vector<int> output;
int main()
{
  int n, maxRow, maxCol, maxRCount, maxCCount;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &grid[i][j]);
      grid[0][j]+=grid[i][j];
      grid[i][0]+=grid[i][j];
    }
  }

  while(true){
    maxRCount = maxCCount = (int)(ceil(n/2.0)-0.5);
    maxRow = maxCol = -1;
    for (int i = 1; i <= n; i++)
    {
      if(grid[i][0] > maxRCount){
        maxRCount=grid[i][0];
        maxRow = i;
      }
      if(grid[0][i] > maxCCount){
        maxCCount=grid[0][i];
        maxCol = i;
      }
    }
    if(maxCol == -1 && maxRow == -1)break;
    if(maxRCount > maxCCount){
      output.push_back(maxRow);
      grid[maxRow][0] = n-grid[maxRow][0];
      for (int i = 1; i <= n; i++)
      {
        if(grid[maxRow][i]){
          grid[0][i]--;
          grid[maxRow][i] = 0;
        }else{
          grid[0][i]++;
          grid[maxRow][i] = 0;
        }
      }
      
    }else{
      output.push_back(10000 + maxCol);
      grid[0][maxCol] = n-grid[0][maxCol];
    }
  }


  if(output.size() == 0){
    printf("-1");
    return 0;
  }
  printf("%d", output.size());
  for (int i = 0; i < output.size(); i++)
  {
    if(output[i] > 10000){
      printf("\nC %d", output[i]-10000);
    }else{
      printf("\nR %d", output[i]);
    }
  }
  


  return 0;
}
