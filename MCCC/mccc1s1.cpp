#include <iostream>

int n, battleCount;
int cards[1000][2];
bool battleing;
int main()
{
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&cards[i][0]);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&cards[i][1]);
  }
  battleing = false;
  for (int i = 0; i < n; i++)
  {
    if(cards[i][0]==cards[i][1]){
      if(!battleing){
        battleCount++;
        battleing = true;
      }
    }else{
      battleing = false;
    }
  }

  printf("%d", battleCount);


  return 0;
}
