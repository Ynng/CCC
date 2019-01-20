#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, q, temp, treeTotalMass = 0;
    vector<int> trees, queryA, queryB;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        treeTotalMass += temp;
        trees.push_back(treeTotalMass);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d ", &temp);
        queryA.push_back(temp);
        scanf("%d", &temp);
        queryB.push_back(temp);
    }
    for (int i = 0; i < q; i++)
    {
        if (queryA[i] == 0)
        {
            printf("%d\n", trees[queryB[i]]);
        }
        else
        {
            printf("%d\n", trees[queryB[i]] - trees[queryA[i] - 1]);
        }
    }
    return 0;
}
