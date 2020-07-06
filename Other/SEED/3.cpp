#include <iostream>
using namespace std;
int main()
{
    int i, n, j, tempA, tempB, tempC, sum[100005];
    scanf("%d", &i);
    scanf("%d", &n);
    scanf("%d", &j);
    for (int a = 1; a <= i; a++)
    {
        sum[a]=0;
    }
    for (int a = 1; a <= j; a++)
    {
        scanf("%d %d %d", &tempA, &tempB, &tempC);
        sum[tempA] += tempC;
        sum[tempB+1] -= tempC;
    }
    tempA = tempB = 0;
    for (int a = 1; a <= i; a++)
    {
        tempA += sum[a];
        if (tempA < n)
            tempB++;
    }
    printf("%d", tempB);
    return 0;
}