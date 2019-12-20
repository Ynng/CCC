#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int t, n[1005], largest, limit, sqrtLimit;
    bool prime[2000005];
    largest = -1;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n[i]);
        if (n[i] > largest)
            largest = n[i];
    }

    //finding the primes
    limit = largest * 2 + 1;
    sqrtLimit = sqrt(limit);
    for (int i = 2; i <= sqrtLimit; i++)
    {
        if (!prime[i])
        {
            for (int j = 2; i * j <= limit; j++)
            {
                prime[i * j] = true;
            }
        }
    }
    prime[1] = true;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            if ((!prime[j]) && (!prime[n[i] * 2 - j]))
            {
                printf("%d %d\n", j, n[i] * 2 - j);
                break;
            }
        }
    }
    return 0;
}