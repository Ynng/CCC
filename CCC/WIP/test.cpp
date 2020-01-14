#include <map>
#include <set>


bool pho[100005]={false};

int main(){
    std::map<int, std::set<int>> graph;
    

    int n,m, tempA, tempB;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &tempA);
        pho[tempA]=true;
    }

    for(int i = 1; i < m; i++){
        scanf("%d %d", &tempA, &tempB);
        graph.insert(tempA, tempB);
    }

    return 0;
}