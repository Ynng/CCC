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

using namespace std;
typedef long long ll;

// #define DEBUG

int n;
int ix, iy;
pair<int, int> particles[100005];
int visited[100005];

map<int, vector<int>> adj;
int counter = 0;

void dfs(int dot);

int main(){
  FILE *fp;
  fp = fopen("moop.in", "r");
  memset(particles, 0, sizeof particles);
  memset(visited, 0, sizeof visited);

  #ifdef DEBUG
  scanf("%d", &n);
  #else
  fscanf(fp,"%d", &n);
  #endif
  
  for (int i = 0; i < n; i++)
  {
    #ifdef DEBUG
    scanf("%d %d", &ix, &iy);
    #else
    fscanf(fp,"%d %d", &ix, &iy);
    #endif
    particles[i]= {ix, iy};
    bool alone = true;
    for (int j = 0; j < i; j++)
    {
      if((particles[j].first <= ix && particles[j].second <= iy) || (particles[j].first >= ix && particles[j].second >= iy)){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  
  dfs(0);
  int temp = 0;
  int output = 1;
  while(counter<n){
    while(visited[temp])
      temp++;
    dfs(temp);
    output++;
  }
  
  FILE *fout;
  fout = fopen("moop.out", "w");

  printf("%d", output);
  fprintf(fout, "%d", output);

  fclose(fp);
  fclose(fout);
}

void dfs(int dot){
  if(visited[dot])return;
  visited[dot] = true;
  counter++;
  for (int i = 0; i < adj[dot].size(); i++)
  {
    dfs(adj[dot][i]);
  }
}