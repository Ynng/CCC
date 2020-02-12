#include <iostream>
#include <cmath>

#define CURRENT grid[row][col]

int m, n;
int grid[1005][1005];
bool visited[1000005];
bool finished = false;

void printGrid(){
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

void recursion(int row, int col){
  // printf("recursion on %d %d", row, col);
  if(row == m && col == n){
    finished = true;
    return;
  }
  if(visited[CURRENT]==true){
    return;
  }else{
    visited[CURRENT]=true;
  }
  for (int i = 1; i <= sqrt(CURRENT)+0.5 && (i <= n || i <= m); i++)
  {
    if(CURRENT%i==0){
      if(i<=m && (CURRENT / i)<=n){
        recursion(i,CURRENT / i);
      }
      if(i<=n && (CURRENT / i)<=m){
        recursion(CURRENT / i, i);
      }
      //Than we know the number can be divided by i
    }
  }
  
}

int main()
{
  scanf("%d", &m);
  scanf("%d", &n);
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &grid[i][j]);
    }
  }  

  recursion(1,1);

  if(finished){
    printf("yes");
  }else{
    printf("no");
  }
  return 0;
}
