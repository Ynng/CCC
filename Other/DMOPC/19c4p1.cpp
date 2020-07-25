#include <iostream>
#include <cmath>
// #include <cstdio>
#include <cstring>
// using namespace std;

#define cur inputs[i][j]
int main()
{
    int n, stringLength, temp;
    char inputs[105][1005];
    bool output;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &inputs[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        // printf("Length:%d\n",);
        stringLength = strlen(inputs[i]);
        temp = 0;
        output = true;
        for (int j = 0; j < stringLength; j++)
        {
            if ('0' <= cur && cur <= '9')
                continue;
            if (cur == '(')
            {
                temp++;
            }
            else if (cur == ')')
            {
                temp--;
            }
            else
            {
                output = false;
                break;
            }

            if (temp < 0)
            {
                output = false;
                break;
            }
        }
        if (temp != 0)
            output = false;

        if (output)
        {
            if (i == n - 1)
            {
                printf("YES");
            }
            else
            {
                printf("YES\n");
            }
        }
        else
        {
            if (i == n - 1)
            {
                printf("NO");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}