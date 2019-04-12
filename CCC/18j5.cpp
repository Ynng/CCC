#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int N, M, temp, reachable, shortestPath, pathlength[10005];
map<int, vector<int>> graph;
vector<int> choices, query;
int main()
{
    shortestPath = 100000;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            choices.push_back(temp);
        }
        graph[i] = choices;
        choices.clear();
    }
    /*
    for (auto mapit = graph.begin(); mapit != graph.end(); ++mapit)
    {
        for (auto vecit = mapit->second.begin(); vecit != mapit->second.end(); ++vecit)
        {
            cout << *vecit;
            cout << " ";
        }
        cout << endl;
    }*/
    query.push_back(1);
    reachable = 1;
    pathlength[1] = 1;

    while (query.size() > 0)
    {
        if (graph[query[0]].size() == 0)
        {
            if(shortestPath>pathlength[query[0]]){
                shortestPath=pathlength[query[0]];
                pathlength[query[0]]=pathlength[query[0]];
            }
        }
        else
        {
            for (auto it = graph[query[0]].begin(); it != graph[query[0]].end(); ++it)
            {
                if (pathlength[*it] == 0)
                {

                    pathlength[*it] = pathlength[query[0]] + 1;
                    query.push_back(*it);
                    reachable++;
                }
            }
        }
        query.erase(query.begin());
    }
    if (reachable == N)
    {
        printf("Y\n");
    }
    else
    {
        printf("N\n");
    }
    printf("%d", shortestPath);

    return 0;
}
