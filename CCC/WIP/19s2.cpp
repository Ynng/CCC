#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int t, n[1005], tempA, tempB, largest, limit, division;
    vector<int> primeVector;
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
    for (int i = 2; i <= largest * 2 + 1; i++)
    {
        limit = pow(i, 0.5) + 1;
        division = -1;
        for (int j = 2; j <= limit; j++)
        {
            if (i % j == 0)
            {
                division = j;
                break;
            }
        }
        if (division == -1)
        {
            prime[i] = true;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            if (prime[j] && prime[n[i] * 2 - j])
            {
                printf("%d %d\n", j, n[i] * 2 - j);
                break;
            }
        }
    }
    return 0;
}