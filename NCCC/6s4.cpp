#include <iostream>
using namespace std;
int a, b, c, d, q, queries[100005], dp[10000005], tempA, tempB;
int recursion(int x)
{
    if (x <= 0)
    {
        return 1;
    }
    else
    {
        if (x < 10000005)
        {
            if (dp[x] != -1)
            {
                return dp[x];
            }
            else
            {
                tempA = recursion(x / a - b) + recursion(x / c - d);
                dp[x] = tempA;
                return tempA;
            }
        }
        else
        {
            tempA = recursion(x / a - b) + recursion(x / c - d);
            return tempA;
        }
    }
}
int main()
{
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &queries[i]);
    }
    dp[0]=1;
    for (int i = 0; i < 10000005; i++)
    {
        tempA = i/a-b;
        tempB = i/c-d;
        if(tempA<=0&&tempB<=0){
            dp[i] = 2;
        }else if(tempA<=0){
            dp[i] = 1+ dp[i/c-d];
        }else if(tempB<=0){
            dp[i] = 1+ dp[i/a-b];
        }else{
            dp[i] = dp[i/a-b] + dp[i/c-d];
        }
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", recursion(queries[i]));
    }
    return 0;
}
