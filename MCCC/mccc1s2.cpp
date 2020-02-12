#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int grid[2005][2005];
bool alreadyDone[20000];
vector<int> output;
int n;
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
  bool done;
  scanf("%d", &n);
  done = true;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &grid[i][j]);
      if(grid[i][j])done = false;
      grid[0][j]+=grid[i][j];
      grid[i][0]+=grid[i][j];
    }
  }
  if(done){
    printf("0");
    return 0;
  }
  done = false;
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
    else done = true;
    if(maxRCount > maxCCount){
      if(alreadyDone[maxRow]){
        done = false;
        break;
      }
      alreadyDone[maxRow] = true;
      output.push_back(maxRow);
      grid[maxRow][0] = n-grid[maxRow][0];
      for (int i = 1; i <= n; i++)
      {
        if(grid[maxRow][i]){
          grid[0][i]--;
          grid[maxRow][i] = 0;
        }else{
          grid[0][i]++;
          grid[maxRow][i] = 1;
          done = false;
        }
      }
    }else{
      if(alreadyDone[maxCol + 10000]){
        done = false;
        break;
      }
      alreadyDone[maxCol + 10000] = true;
      output.push_back(10000 + maxCol);
      grid[0][maxCol] = n-grid[0][maxCol];
      for (int i = 1; i <= n; i++)
      {
        if(grid[i][maxCol]){
          grid[i][0]--;
          grid[i][maxCol] = 0;
        }else{
          grid[i][0]++;
          grid[i][maxCol] = 1;
          done = false;
        }
      }
    }
  }


  if(!done){
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
