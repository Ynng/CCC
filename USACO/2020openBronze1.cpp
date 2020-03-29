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
int n;
char input[100005];
int max1, max2, counter, maxDist, start, ending;
bool begginingFlag = true;
int temp[4];
int output;
int maxD = 100005;

// #define DEBUG

int main(){
  FILE *fp;
  fp = fopen("socdist1.in", "r");

  #ifdef DEBUG
  scanf("%d", &n);
  scanf("%s", input);
  #else
  fscanf(fp,"%d", &n);
  fscanf(fp,"%s", input);
  #endif

  input[n] = '2';

  max1 = max2 = counter = maxDist = start = ending = 0;
  for (int i = 0; i <= n; i++)
  {
    if(input[i] == '0'){
      counter++;
    }else{
      if(begginingFlag){
        if(input[i] != '2')
          begginingFlag = false;
        start = counter;
      }else if(input[i] == '2'){
        ending = counter;
      }else{
        counter++;
        if(counter<maxD){
          maxD = counter;
        }
        if(counter>max2){
          if(counter>max1){
            max2 = max1;
            max1 = counter;
          }else{
            max2 = counter;
          }
        }
      }
      counter = 0;
    }
  }

  temp[0] = start;
  temp[1] = ending;
  temp[2] = max1/2;
  temp[3] = max2/2;

  sort(temp, temp+4);

  output = min(maxD,max(max(temp[2], max(start/2, ending/2)), max1/3));
  if(begginingFlag)output = start-1;
  std::ofstream out("socdist1.out");
  out << output;
  out.close();


  #ifdef DEBUG
  printf("flag: %d\n", begginingFlag);
  printf("%d %d\n", temp[2], temp[3]);

  printf("%d %d %d %d\n", start, ending, max1, max2);
  #endif

  printf("%d\n",output);

}