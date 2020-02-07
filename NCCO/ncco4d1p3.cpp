#include <cstdio>
#include <queue>
#include <map>
#include <vector>
#include <string.h>
#include <limits.h>

using namespace std;

vector<pair<int, int>> graph[5005];
int dist[5005][2];

int main()
{
  int n, m, a, b, w;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d %d", &a, &b, &w);
    graph[a].push_back({b,w});
    graph[b].push_back({a,w});
  }
  for (int i = 0; i < 5005; i++)
  {
    dist[i][0] = dist[i][1] = INT_MAX;
  }
  dist[1][0] = 0;
  

  

  
  
  
  

  return 0;
}


