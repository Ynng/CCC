#include <bits/stdc++.h>
using namespace std; 

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
    bool phoChild;

    // printf("rec %d\n", cur);
    visited[cur] = true;

    if (pho[cur] && distance > furthestDist)
    {
        furthestDist = distance;
        furthestNode = cur;
    }

    if(distance!=0 && graph[cur].size() == 1)
        return pho[cur];

    phoChild = pho[cur];
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int neighbor = graph[cur][i];
        if(visited[neighbor] || removed[neighbor]) continue;
        if (recursion(neighbor, distance + 1)) phoChild = true;
        else{
            removed[neighbor] = true;
            edgeCount -= 2;
        }
    }
    return phoChild;
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

    recursion(startNode, 0);
    memset(visited, 0, sizeof(visited));
    recursion(furthestNode, 0);
    printf("%d", edgeCount - furthestDist);

    return 0;
}