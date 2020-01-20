#include <iostream>
#include <vector>
int main()
{
  std::vector<int> cars;
  std::vector<int> side;
  int t, n, temp, counter, cur;
  bool tempOutput;
  bool output[100] = {false};
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    cars.clear();
    side.clear();
    scanf("%d", &n);
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &temp);
      cars.push_back(temp);
    }
    counter = 1;
    tempOutput = true;
    while (cars.size() > 0 || side.size() > 0)
    {
      if (cars.size() > 0)
      {
        cur = cars.back();
        if (cur == counter)
        {
          cars.pop_back();
          counter++;
        }
        else if (cur < counter)
        {
          tempOutput = false;
          break;
        }
        else if (cur > counter)
        {
          if (side.size() > 0 && side.back() == counter)
          {
            side.pop_back();
            counter++;
          }
          else
          {
            cars.pop_back();
            side.push_back(cur);
          }
        }
      }
      else
      {
        cur = side.back();
        side.pop_back();
        if (cur == counter)
        {
          counter++;
        }
        else
        {
          tempOutput = false;
          break;
        }
      }
    }
    output[i] = tempOutput;
  }

  for (int i = 0; i < t - 1; i++)
  {
    if (output[i])
    {
      printf("Y\n");
    }
    else
    {
      printf("N\n");
    }
  }
  if (output[t - 1])
  {
    printf("Y");
  }
  else
  {
    printf("N");
  }
  return 0;
}