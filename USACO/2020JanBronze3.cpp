// not full AC
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
  FILE *fp;
  fp = fopen("race.in", "r");
  long long k, n, x, o;
  long double output, temp, bruh;
  fscanf(fp, "%lld %lld", &k, &n);

  std::ofstream out("race.out");

  bruh = 1;
  
  for (int i = 0; i < n; i++)
  {
    fscanf(fp, "%lld", &x);
    output = abs(sqrt(x * x * bruh - x + (2.0 * k))) / sqrt(2.0 * bruh);
    temp = 2 * output - x;
    o = ceil(temp);
    out << o;
    if (i != (n - 1))
    {
      out << "\n";
    }
  }
}