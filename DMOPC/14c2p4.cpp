#include <iostream>
using namespace std;
int main()
{
    int n, q, tempA, tempB, trees[1000005], m[1000005];
    scanf("%d", &n);
    trees[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tempA);
        trees[i] = trees[i - 1] + tempA;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &tempA, &tempB);
        m[i] = trees[tempB + 1] - trees[tempA];
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", m[i]);
    }
    return 0;
}
