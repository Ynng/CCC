#include <stdio.h>
#include <map>
#include <cmath>
using namespace std;
int n;
long long complexity = 0;
long long dp[10000000] = {0};

long long node(int weight)
{
	int nodeWeight;
	long long d = 0, temp = 0;
	//i = number of nodes
	for (int i = 2; i <= weight / 3; i++)
	{
		//nodeWeight = (weight - (weight%i)) / i;
		nodeWeight = weight / i;
		if (nodeWeight<10000000 && dp[nodeWeight])
		{
			d += dp[nodeWeight];
		}
		else
		{
			temp = node(nodeWeight);
			if(nodeWeight<10000000)dp[nodeWeight] = temp;
			d += temp;
		}
		complexity++;
	}
	d += (weight - weight / 3);

	return d;
}

int main()
{
	scanf("%d", &n);
	if (n == 1 || n == 2)
	{
		printf("%d", 1);
		return 0;
	}
	// dp[1] = 1;
	// dp[2] = 1;
	// for (int i = 3; i<=n; i++)
	// {
	// 	dp[i] = 0;
	// 	for (int j = 2; j <= i / 2; j++)
	// 	{
	// 		dp[i] += dp[i / j];
	// 	}
	// 	dp[i]+=i/2+i%2;
	// }
	printf("%lld", node(n));
	// for (int i = 0; i <= n; i++)
	// {
	// 	if (dp[i] != 0)
	// 		printf("\n%d %lld", i, dp[i]);
	// }
	// printf("\nComplexity %lld", complexity);
	return 0;
}
