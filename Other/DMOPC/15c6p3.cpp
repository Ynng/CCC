#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, m, k, tempA, tempB, row[200005], totalPotato, output, baseW;
    double tempx, tempy;
    scanf("%lld %lld %lld", &n, &m, &k);
    totalPotato = n * m;
    row[0] = m;
    for (int i = 1; i <= n; i++)
    {
        row[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld", &tempA, &tempB);
        row[tempA]--;
        row[tempB + 1]++;
        totalPotato -= (tempB - tempA + 1);
    }
    if (totalPotato < k)
    {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        row[i] = row[i - 1] + row[i];
        // cout << row[i];
    }
    row[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        row[i] = row[i - 1] + row[i];
        // cout << row[i];
    }
    output = n + 100;
    tempx = k;
    tempy = m;
    baseW = ceil(tempx / tempy);
    tempA = baseW;
    for (int i = 1; i + baseW - 1 <= n; i++)
    {
        for (int w = tempA; i + w - 1 <= n; w++)
        {
            if (row[i + w - 1] - row[i - 1] >= k)
            {
                if(w>output){
                    i+=(w-output);
                    w=output;
                }
                while (row[i + w - 1] - row[i - 1] >= k && w >= baseW && i + baseW - 1 <= n)
                {
                    i++;
                    w--;
                }
                i--;
                w++;
                if (w < output)
                {
                    output = w;
                    tempA = w;
                }
            }
        }
    }
    printf("%lld", output);
    return 0;
}