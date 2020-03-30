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

#define DEBUG
int n, m;

pair<ll, ll> grass[100005];
ll ia, ib;
ll output;

#define END (grass[m-1].second)
#define START (grass[0].first)


int main(){
  memset(grass, 0, sizeof grass);



  FILE *fin;
  fin = fopen("socdist.in", "r");

  #ifdef DEBUG
  scanf("%d %d", &n, &m);
  #else
  fscanf(fin,"%d %d", &n, &m);
  #endif


  for (int i = 0; i < m; i++)
  {
    #ifdef DEBUG
    scanf("%lld %lld", &ia, &ib);
    #else
    fscanf(fin,"%lld %lld", &ia, &ib);
    #endif
    grass[i] = {ia,ib};
  } 

  sort(grass, grass + m, [](const pair<ll,ll> &left, const pair<ll,ll> &right) {
    return left.first < right.first;
  });

  // for (int i = 0; i < m; i++)
  // {
  //   printf("%lld %lld\n", grass[i].first, grass[i].second);
  // }

  int d = END/(n-1);
  bool good;
  int l = 1;
  int r = d;
  while(l<=r){
    ll cur = START;
    int g = 0;
    d = (l+r)/2;
    good = true;
    bool beginning = true;
    for (int i = 1; i < n; i++)
    {
      cur+=d;
      if(cur>END){
        good = false;
        break;
      }
      
      while(cur>grass[g].second){
        if(g>=m){
          good = false;
          break;
        }
        g++;
      }
      if(grass[g].second == 0){
        good = false;
        break;
      }

      if(!good)break;

      if(cur<grass[g].first)cur = grass[g].first;
    }
    if(good){
      l = d+1;
      output = d;
    }else{
      r = d-1;
    }
  }
  
  FILE *fout;
  fout = fopen("socdist.out", "w");

  printf("%lld", output);
  fprintf(fout, "%lld", output);


  fclose(fin);
  fclose(fout);

  return 0;
}