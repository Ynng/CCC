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
#define COW_SICk cows[i].second

int n;
vector<pair<int, bool>> cows;
int pos, wuhan;
int r;
int output;
int counter;
bool lastSick;

int main(){
  FILE *fp;
  fp = fopen("socdist2.in", "r");

  #ifdef DEBUG
  scanf("%d", &n);
  #else
  fscanf(fp,"%d", &n);
  #endif
  for (int i = 0; i < n; i++)
  {
    #ifdef DEBUG
    scanf("%d %d", &pos, &wuhan);
    #else
    fscanf(fp,"%d %d", &pos, &wuhan);
    #endif
    cows.push_back({pos, (bool)wuhan});
  }
  sort(cows.begin(), cows.end(), [](const pair<int,bool> &left, const pair<int,bool> &right) {
    return left.first < right.first;
  });

  r=1000005;
  for (int i = 0; i < n; i++)
  {
    if(!COW_SICk){
      if(i>0)
        if(cows[i-1].second)
          r = min(r, cows[i].first - cows[i-1].first - 1);
      if(i<n-1)
        if(cows[i+1].second)
          r = min(r, cows[i+1].first - cows[i].first - 1);
    }
    // #ifdef DEBUG
    // printf("%d %d\n", cows[i].first, cows[i].second);
    // #endif
  }
  // printf("r: %d\n", r);
  counter = cows[0].second;
  lastSick = cows[0].second;
  for (int i = 1; i < n; i++)
  {
    if(COW_SICk){
      if(lastSick){
        if((cows[i].first - cows[i-1].first) > r){
          counter++;
        }
      }else{
        counter++;
      }
      lastSick = true;
    }else{
      lastSick = false;
    }
  }
  output = counter;
  std::ofstream out("socdist2.out");
  out << output;
  out.close();
  printf("%d", output);

  return 0;
}