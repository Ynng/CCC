#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, k;
int minimumDays, slack;
long long output;
vector<long long> attraction;

int largest(int start, int end)
{
    // printf("\nlargest on %d %d", start, end);

    long long maximum = 0;
    for (int i = start; i < end && i < attraction.size(); i++)
    {
        if (attraction[i] > maximum)
            maximum = attraction[i];
    }
    return maximum;
}

int recursion(int startDate, int slackRemaining)
{
    // printf("\nrecursion on %d %d", startDate, slackRemaining);
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
    }
    else
    {
        temp = largest(startDate, startDate + k);
        if (temp > maximum)
            maximum = temp;
    }
    return maximum;
}

int main()
{
    long long temp;
    output = -1;
    scanf("%d %d", &n, &k);
    minimumDays = ceil(n / k);
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
