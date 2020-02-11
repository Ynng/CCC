#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int grid[2005][2005];
int n;
vector<int> output;
void printGraph(){
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int maxRow, maxCol, maxRCount, maxCCount;
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

  for (int i = 1; i <= n; i++)
  {
    if(grid[i][0] >= n/2.0){
      output.push_back(i);
      grid[i][0] = 1;
    }else{
      grid[i][0] = 0;
    }
    grid[0][i] = 0;
  }

  printGraph();

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      grid[0][j]+=grid[i][j] ^ grid[i][0];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if(grid[0][i] >= n/2.0){
      output.push_back(10000 + i);
      grid[0][i] = 1;
    }else{
      grid[0][i] = 0;
    }
  } 

  

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if((grid[i][j] ^ grid[i][0]) ^ grid[0][j]){
        printf("-1");
        return 0;
      }
    }
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
