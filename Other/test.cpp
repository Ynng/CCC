#include <iostream>
using namespace std;
int n, m;
const int M = 1e5;
long long int bit[M + 1];
long long int ar[M + 1];
long long int freq[M + 1];

long long int sum(int start, int end)
{
  long long int sum = 0, sumstart =0, sumend = 0;
  while (start > 0)
  {
    sumstart += bit[start];
    start -= (start & -start);
  }
  while (end > 0)
  {
    sumend += bit[end];
    end -= (end & -end);
  }
  sum = sumend - sumstart;
  return sum;
}
void freqc(long long int ind)
{
  // int freqval = ar[ind];
  while (ind <= M)
  {
    freq[ind]++;
    ind += (ind & -ind);
  }
  return;
}
void change(long long int ind, long long int val)
{
  long long dif = val - ar[ind];
  long long first = ar[ind];
  while (first <= M)
  {
    freq[first]--;
    first += first & -first;
  }
  //    if (val > ar[ind-1]){
  //        change = -1;
  //    } else if (val == ar[ind-1]){
  //        change =0;
  //    } else {
  //        change = 1;
  //    }
  ar[ind] = val;
  freqc(val);
  while (ind <= n)
  {
    bit[ind] += dif;
    // the left most 1 (LSB)
    ind += (ind & -ind);
  }
  return;
}
long long int freqcount(long long int ind)
{
  long long int sum = 0;
  while (ind > 0)
  {
    sum += freq[ind];
    ind -= (ind & -ind);
  }
  return sum;
}
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
  {
    cin >> ar[i];
  }
  for (int i = 1; i <= n; ++i)
  {
    int ind = i;
    while (ind <= n)
    {
      bit[ind] += ar[i];
      ind += (ind & -ind);
    }
    long cur = ar[i];
    while (cur <= M)
    {
      freq[cur]++;
      cur += (cur & -cur);
    }
  }
  for (int i = 0; i < m; ++i)
  {
    char cur;
    long long int x, y;
    cin >> cur >> x;
    if (cur == 'S')
    {
      cin >> y;
      cout << sum(x - 1, y) << endl;
    }
    else if (cur == 'C')
    {
      cin >> y;
      change(x, y);
      // freqc(x);
    }
    else
    {
      cout << freqcount(x) << endl;
    }
  }
  return 0;
}