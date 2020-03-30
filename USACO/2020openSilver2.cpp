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

int n, m;
int ia, ib;
pair<int, int> cows[100005];
int cereal[100005];
int output[100005];

bool shiftDown(int cow);

int main(){
  FILE *fp;
  fp = fopen("cereal.in", "r");
  memset(cereal, 0, sizeof cereal);
  memset(output, 0, sizeof output);


  #ifdef DEBUG
  scanf("%d %d", &n, &m);
  #else
  fscanf(fp,"%d %d", &n, &m);
  #endif

  for (int i = 1; i <= n; i++)
  {
    #ifdef DEBUG
    scanf("%d %d", &ia, &ib);
    #else
    fscanf(fp,"%d %d", &ia, &ib);
    #endif
    cows[i] = {ia,ib};
  }

  // #ifdef DEBUG
  // for (int i = 1; i <= n; i++)
  // {
  //   printf("%d %d\n", cows[i].first, cows[i].second);
  // }
  // #endif

  for (int i = n; i >= 1; i--)
  {

    if(cereal[cows[i].first] == 0){
      cereal[cows[i].first] = i;
      output[i] = output[i+1] + 1;
    }else{
      int temp = cereal[cows[i].first];
      cereal[cows[i].first] = i;
      if(shiftDown(temp)){
        output[i] = output[i+1] + 1;
      }else{
        output[i] = output[i+1];
      }
      // #ifdef DEBUG
      //   for (int j = 1; j <= m; j++)
      //   {
      //     printf("%d ", cereal[j]);
      //   }
      //   printf("\n");
      // #endif
    }
  }
  
  FILE *fout;
  fout = fopen("cereal.out", "w");

  for (int i = 1; i < n; i++)
  {
    printf("%d\n", output[i]);
    fprintf(fout, "%d\n", output[i]);
  }
  printf("%d", output[n]);
  fprintf(fout, "%d", output[n]);
  
  fclose(fp);
  fclose(fout);

  return 0;
  
}

bool shiftDown(int cow){
  if(cereal[cows[cow].second] == 0){
    cereal[cows[cow].second] = cow;
    return true;
  }else if(cereal[cows[cow].second] > cow){
    int temp = cereal[cows[cow].second];
    cereal[cows[cow].second] = cow;
    return shiftDown(temp);
  }else{
    return false;
  }
}