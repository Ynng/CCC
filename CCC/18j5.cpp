#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int N, M, temp;
map<int, vector<int>> graph;
vector<int> choices;
int main()
{

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            // cout << temp;
            choices.push_back(temp);
        }
        graph[N] = choices;
        choices.clear();
    }

    for (auto mapit = graph.begin(); mapit != graph.end(); mapit++)
    {
        std::stringstream ss;
        for (auto vecit = mapit->second.begin(); vecit != mapit->second.end(); vecit++)
        {
            // ss << ",";
            // ss << *vecit << endl;
            cout << *vecit;
            cout<<"vector";
        }
        // cout << ss.str();
        // cout << "map";
        cout<<endl;
        cout<<"map";
        cout<<std::distance(graph.end(),graph.begin());
    }

    return 0;
}
