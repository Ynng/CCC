#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, m, q, tempA, tempB, tempC, tempD, output[50005], bridges[50005][50005];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &tempA, &tempB, &tempC);
        bridges[tempA][tempB] = tempC;
        bridges[tempB][tempA] = tempC;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &tempA, &tempB);
        output[i] = recursion(tempA, tempB, 0);
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d", output[i]);
    }
    return 0;
}

int recursion(int last, int destination, int stepCounter)
{
    for()
}