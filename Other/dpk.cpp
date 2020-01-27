#include <iostream>

int firstWin[100005] = {0};
int n, k, sum = 0;
int a[105];

bool recursion(int count, bool me)
{
  bool win = false;
  if(firstWin[count]!=0){
    if(firstWin[count]==1)return true;
    else return false;
  }
  for (int i = 0; i < n; i++)
  {
    if (count - a[i] >= 1)
    {
      if(!(recursion(count - a[i], !me))){
        //if the next person loses
        win=true;
        break;
      }
    }else{
      if(count - a[i] == 0){
        //then current player wins
        win=true;
        break;
      }
    }
  }
  //if "I" will win
  if(win)firstWin[count]=1;
  else firstWin[count]=-1;
  return win;
}

int main()
{

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  if(recursion(k, true)){
    printf("First");
  }else{
    printf("Second");
  }

  return 0;

}