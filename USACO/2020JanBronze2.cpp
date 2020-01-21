#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <string.h>

int main()
{
  FILE *fp;

  int n, temp, last, maxA, minA, maxB, minB, memA, memB;
  int max, min, output, tempB;
  maxA = 0;
  minA = 0;
  maxB = 0;
  minB = 0;
  memA = 0;
  memB = 0;
  bool A = true;
  int input[1005];
  int diff[1005];
  bool checked[1005] = {false}, wrong;

  last = 0;
  fp = fopen("photo.in", "r");
  fscanf(fp, "%d", &n);

  for (int i = 0; i < n - 1; i++)
  {
    fscanf(fp, "%d", &temp);
    input[i] = temp;
    diff[i] = temp - last;
    last = temp;
    if (i != 0)
    {
      if (A)
      {
        memA += diff[i];
        if (memA > maxA)
          maxA = memA;
        if (memA < minA)
          minA = memA;
      }
      else
      {
        memB += diff[i];
        if (memB > maxB)
          maxB = memB;
        if (memB < minB)
          minB = memB;
      }
      A = !A;
    }
  }

  max = n;
  if (max > n - maxA)
    max = n - maxA;
  if (max > input[0] - minB)
    max = input[0] - minB;

  min = 1;
  if (min < 1 - minA)
    min = 1 - minA;
  if (min < (n - maxB) - input[0])
    min = (n - maxB) - input[0];

  for (int i = min; i <= max; i++)
  {
    wrong = false;
    memset(checked, false, sizeof(checked));  
    temp = i;
    checked[temp] = true;
    for (int j = 1; j < n - 1; j += 2)
    {
      temp += diff[j];
      if (checked[temp])
      {
        wrong = true;
        break;
      }
      checked[temp] = true;
    }
    if (wrong)
      continue;
    temp = input[0] - i;
    if (checked[temp])
      continue;
    else
      checked[temp] = true;
    for (int j = 2; j < n - 1; j += 2)
    {
      temp += diff[j];
      if (checked[temp])
      {
        wrong = true;
        break;
      }
      checked[temp] = true;
    }
    if (wrong)
      continue;
    else
    {
      output = i;
      break;
    }
  }

  std::ofstream out("photo.out");

  temp = output;
  tempB = input[0] - output;
  out << temp << " " << tempB;
  for (int i = 1; i < n - 1; i++)
  {
    if (i % 2 == 1)
    {
      temp += diff[i];
      out << " " << temp;
    }else{
      tempB += diff[i];
      out << " " << tempB;
    }
  }
  out.close();
  return 0;
}