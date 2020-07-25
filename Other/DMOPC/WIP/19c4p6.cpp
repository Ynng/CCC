#include <iostream>
#include <cmath>
#include <cstdio>
// using namespace std;

#define cur inputs[i][j]
int main()
{
    int n, q, cooktimes[100005];
    std::string output = "";

    int qType, x, y, t;
    bool tempB;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cooktimes[i + 1]);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &qType);
        switch (qType)
        {
        case 1:
            scanf("%d", &x);
            output = output + std::to_string(cooktimes[x]) + "\n";
            break;
        case 2:
            scanf("%d %d %d", &x, &y, &t);
            tempB = false;
            for (int j = x; j <= y; j++)
            {
                if (cooktimes[j] < t)
                {
                    tempB = true;
                    j = y + 10;
                }
            }
            if (tempB)
                break;
            else
            {
                for (int j = x; j <= y; j++)
                {
                    cooktimes[j] = cooktimes[j] - t;
                }
                break;
            }
        case 3:
            scanf("%d %d %d", &x, &y, &t);
            for (int j = x; j <= y; j++)
            {
                cooktimes[j] = t - y + j;
            }
            break;
        case 4:
            scanf("%d %d", &x, &y);
            for (int j = x; j <= y; j++)
            {
                cooktimes[j] = (int)(sqrt(cooktimes[j]));
            }
            break;
        }
    }
    output.pop_back();
    std::cout << output;
    return 0;
}