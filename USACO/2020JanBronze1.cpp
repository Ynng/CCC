#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

int main()
{
  FILE *fp;

  int n, k, charCount;
  char tmp[20];
  std::string tmpStr, output;

  fp = fopen("word.in", "r");

  fscanf(fp, "%d %d", &n, &k);

  charCount = 0;
  fscanf(fp, "%s", &tmp);
  tmpStr = tmp;
  output = tmpStr;
  charCount += tmpStr.length();
  for (int i = 1; i < n; i++)
  {
    fscanf(fp, "%s", &tmp);
    tmpStr = tmp;
    if ((charCount + tmpStr.length()) > k)
    {
      output = output + "\n" + tmpStr;
      charCount = tmpStr.length();
    }
    else
    {
      output = output + " " + tmpStr;
      charCount += tmpStr.length();
    }
  }
  std::ofstream out("word.out");
  out << output;
  out.close();
  return 0;
}