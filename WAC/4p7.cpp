#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <fstream>
#include <queue>
#include <unordered_map>

typedef long long ll;

using namespace std;

struct road{
  int city;
  int dura;
  int time;
};

int N, M, Q;
int x,y;
vector<road> plans[10005];
int visited[10005];
int counter;

#define NEI plans[city][i]

void dfs(int city){
  visited[city] = true;
  counter--;
  for (int i = 0; i < plans[city].size(); i++)
  {
    if( visited[plans[city][i].city] )continue;
    if(plans[city][i].dura<x)continue;
    if(plans[city][i].time>y)continue;
    dfs(plans[city][i].city);
  }
}

int main(){

  scanf("%d %d %d", &N, &M, &Q);
  int a, b, d, t;

  for (int i = 0; i < M; i++)
  {
    scanf("%d %d %d %d", &a, &b, &d, &t);
    plans[a].push_back({b, d, t});
    plans[b].push_back({a, d, t});
  }

  for (int i = 0; i < Q; i++)
  {
    memset(visited, 0, sizeof(visited));
    counter = N;
    scanf("%d %d", &x, &y);
    dfs(1);
    // printf("counter = %d", counter);
    if(counter!=0)printf("NO\n");
    else printf("YES\n");
  }
  
  
}