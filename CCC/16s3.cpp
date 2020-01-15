#include <map>
#include <vector>
#include <string.h>
bool pho[100005] = {false};
bool visited[100005] = {false};
bool removed[100005] = {false};
int furthestNode, furthestDist = 0;

std::map<int, std::vector<int>> graph;
int n, m, edgeCount, startNode;

int recursion(int cur, int distance)
{
    int temp, tempOutput;

    // printf("rec %d\n", cur);
    visited[cur] = true;

    if (pho[cur] && distance > furthestDist)
    {
        furthestDist = distance;
        furthestNode = cur;
    }

    if (graph[cur].size() != 1 || distance == 0)
    {
        if (pho[cur])
            tempOutput = 0;
        else
            tempOutput = -1;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int neighbor = graph[cur][i];
            if (!visited[neighbor] && !removed[neighbor])
            {
                temp = recursion(neighbor, distance + 1);
                if (temp == -1)
                {
                    removed[neighbor] = true;
                    edgeCount -= 2;
                }
                else
                {
                    tempOutput = 0;
                }
            }
        }
        return tempOutput;
    }
    else
    {
        if (pho[cur])
            return 0;
        else
            return -1;
    }
}
int main()
{
    int tempA, tempB;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tempA);
        pho[tempA] = true;
    }
    startNode = tempA;
    edgeCount = (n - 1) * 2;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &tempA, &tempB);
        graph[tempA].push_back(tempB);
        graph[tempB].push_back(tempA);
    }

    // printf("\n stuff: ");

    // for (int i = 0; i < graph[5].size(); i++)
    // {
    //     printf("%d ", graph[5][i]);
    // }

    recursion(startNode, 0);
    memset(visited, 0, sizeof(visited));
    // printf("edgecount: %d\n", edgeCount);
    recursion(furthestNode, 0);
    // printf("edgecount: %d\n", edgeCount);
    // printf("furthestDist: %d\n", furthestDist);

    // printf("%d", edgeCount);

    // printf("\nA:%d B:%d", heightA, heightB);

    // printf("\nedgeCount:%d ", edgeCount);
    printf("%d", edgeCount - furthestDist);

    // printf("\n height ");

    // for (int i = 0; i < n; i++)
    // {
    //     printf("\n%d: %d %d %d", i, height[i], removed[i], childCount[i]);
    // }

    return 0;
}