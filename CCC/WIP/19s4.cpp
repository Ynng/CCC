#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int n, k;
int minimumDays, slack;
long long output;
vector<long long> attraction;

map<int, map<int, long long>> dp;

map<int, map<int, long long>> dpB;

long long largest(int start, int end)
{
    // printf("\nlargest on %d %d", start, end);
    if(dpB.count(start)){
        if(dpB[start].count(end)){
            return dpB[start][end];
        }
    }

    long long maximum = 0;
    for (int i = start; i < end && i < attraction.size(); i++)
    {
        if (attraction[i] > maximum)
            maximum = attraction[i];
    }
    dpB[start][end] = maximum;
    return maximum;
}

long long recursion(int startDate, int slackRemaining)
{
    // printf("\nrecursion on %d %d", startDate, slackRemaining);

    if(dp.count(startDate)){
        if(dp[startDate].count(slackRemaining)){
            return dp[startDate][slackRemaining];
        }
    }


    long long temp, maximum = 0;

    if (startDate - slackRemaining + k < n)
    {
        for (int i = 0; i <= slackRemaining; i++)
        {
            temp = recursion(startDate + k - i, slackRemaining - i);
            temp += largest(startDate, startDate + k - i);
            if (temp > maximum)
                maximum = temp;
        }
        dp[startDate][slackRemaining] = maximum;
        return maximum;
    }
    else
    {
        temp = largest(startDate, startDate + k);
        dp[startDate][slackRemaining] = temp;

        return temp;
    }
}

int main()
{
    long long temp;
    output = -1;
    scanf("%d %d", &n, &k);
    minimumDays = ceil(n / k) + 0.2; //0.2 becuz int rounds down
    slack = k - n % k;
    if (slack == k)
        slack = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &temp);
        attraction.push_back(temp);
    }

    output = recursion(0, slack);

    printf("%lld", output);

    //     for (int i = 0; i < n; i++)
    // {
    //     printf("%d", attraction[i]);
    // }
    return 0;
}
