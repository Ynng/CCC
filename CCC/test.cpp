#include <iostream>
using namespace std;
int dp[17][500000];
int val[17];
int n;
int v;
int main()
{
  for (int i = 0; i < 500000; i++)
  {
    cout << dp[0][i] << endl;
  }

  cin >> n >> v;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> val[i];
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - val[i]];
      cout << dp[i][j] << " ";
    }
  }
  cout << dp[n][v];
  return 0;
}