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
#define TIME(i) touch[i].first
#define A(i) touch[i].second.first
#define B(i) touch[i].second.second

char input[105];
bool cows[105];
bool pro[105];

int prok[105];

int n, t;
vector<pair<int, pair<int, int>>> touch;
int iT, iA, iB;

int main(){
  FILE *fp;
  fp = fopen("tracing.in", "r");

  #ifdef DEBUG
  scanf("%d %d", &n, &t);
  scanf("%s", input);
  #else
  fscanf(fp,"%d %d", &n, &t);
  fscanf(fp,"%s", input);
  #endif

  for (int i = 1; i <= n; i++)
  {
    cows[i] = (input[i-1]=='1');
  }

  for (int i = 0; i < t; i++)
  {
    #ifdef DEBUG
    scanf("%d %d %d", &iT, &iA, &iB);
    #else
    fscanf(fp,"%d %d %d", &iT, &iA, &iB);
    #endif
    touch.push_back({iT,{iA, iB}});
  }
  sort(touch.begin(), touch.end(), [](const pair<int, pair<int, int>> &left, const pair<int, pair<int, int>> &right) {
    return left.first < right.first;
  });

  #ifdef DEBUG
  // for (int i = 1; i <= n; i++)
  // {
  //   printf("%d",cows[i]);
  // }
  // printf("\n");
  // for (int j = 0; j < t; j++)
  // {
  //   printf("%d %d %d\n",TIME(j), A(j), B(j));
  // }
  #endif

  int g_minK = 100000;
  int g_maxK = -1;
  int x = 0;
  for(int p0 = 1; p0 <=n; p0++){
    if(cows[p0] == false)continue;
    memset(pro, 0, sizeof pro);
    memset(prok, 0, sizeof prok);
    pro[p0] = true;
    int maxK = 300;
    int minK = 0;
    bool bad = false;
    bool good = false;
    for (int i = 0; i < t; i++)
    {
      // if(!cows[A(i)] && !cows[A(i)]){
      //   continue;
      //   //if no one's sick, than whatever
      // }
      if(pro[A(i)])
        prok[A(i)]++;
      if(pro[B(i)])
        prok[B(i)]++;
      if(pro[A(i)] ^ pro[B(i)]){
        int sick = pro[A(i)] ? A(i) : B(i);
        int healthy = pro[B(i)] ? A(i) : B(i);
        if(cows[healthy]){
          pro[healthy] = true;
          minK = max(minK, prok[sick]);
        }else{
          maxK = min(maxK, prok[sick]-1);
        }
      }

      // if(minK>maxK){
      //   bad = true;
      //   break;
      // }
    }

    for(int k = 0; k <= maxK + 5; k++){
      memset(pro, 0, sizeof pro);
      memset(prok, 0, sizeof prok);
      pro[p0] = true;
      bad = false;
      for (int i = 0; i < t; i++)
      {
        if(pro[A(i)])
          prok[A(i)]++;
        if(pro[B(i)])
          prok[B(i)]++;
        if(pro[A(i)] ^ pro[B(i)]){
          int sick = pro[A(i)] ? A(i) : B(i);
          int healthy = pro[B(i)] ? A(i) : B(i);
          if(prok[sick]<=k){
            pro[healthy] = true;
          }
        }

        // if(minK>maxK){
        //   bad = true;
        //   break;
        // }
      }
      for (int i = 0; i < 105; i++)
      {
        if(pro[i]!=cows[i]){
          bad = true;
          break;
        }
      }
      if(!bad)good = true;
      if(!bad){
        g_minK = min(k, g_minK);
        g_maxK = max(k, g_maxK);
      }
    }
    if(good)x++;
    
    // if(!bad){
    //   g_minK = min(minK, g_minK);
    //   g_maxK = max(maxK, g_maxK);
    //   x++;
    // }
  }

  std::ofstream out("tracing.out");
  out << x << " " << g_minK << " ";
  printf("%d %d ", x, g_minK);

  if(g_maxK>=300){
    out<<"Infinity";
    printf("Infinity");
  }
  else{
    out<< g_maxK;
    printf("%d", g_maxK);
  }
  out.close();
  
}