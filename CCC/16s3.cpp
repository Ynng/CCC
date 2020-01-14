#include <map>
#include <vector>

bool pho[100005] = {false};
bool visited[100005] = {false};
bool removed[100005] = {false};
int height[100005] = {0};

std::map<int, std::vector<int>> graph;
int n, m, tempA, tempB, edgeCount, startNode;

int recursion(int cur)
{
    printf("rec %d %d\n", cur, graph[cur].size());
    visited[cur] = true;
    tempB = -1;
    if (graph[cur].size() != 1)
    {
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]] && !removed[graph[cur][i]])
            {
                int neighbor = graph[cur][i];
                tempA = recursion(graph[cur][i]);
                if (tempA == -1)
                {
                    removed[graph[cur][i]] = true;
                    edgeCount--;
                }
                else
                {
                    if(height[cur] < height[graph[cur][i]]+1)height[cur]=height[graph[cur][i]]+1;
                    tempB = 0;
                }
            }
        }
        return tempB;
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

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tempA);
        pho[tempA] = true;
    }
    startNode = tempA;
    edgeCount = n - 1;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &tempA, &tempB);
        graph[tempA].push_back(tempB);
        graph[tempB].push_back(tempA);
    }

    printf("\n stuff: ");

    for (int i = 0; i < graph[2].size(); i++)
    {
        printf("%d ", graph[2][i]);
    }

    recursion(startNode);

    printf("\n height ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", height[i]);
    }

    return 0;
}