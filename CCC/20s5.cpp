#include <iostream>

int n;
int favBurgers[1000005];
int burgers[1000005];
double chance = 100;
int maxBurger = 0;
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &favBurgers[i]);
    burgers[favBurgers[i]]++;
    if(favBurgers[i]>maxBurger)maxBurger = favBurgers[i];
  }
  chance*=
  for (int i = 0; i < n; i++)
  {
    
  }

  printf("%f", chance/100.0);
  return 0;
}
