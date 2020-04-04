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
#define EMPTY -1
#define R(i) (B+1-i)

int T, B;
int a[105];
char outputString [105];

int l, r;


void reverse(){
  #ifdef DEBUG
  fprintf(stderr, "reversing everything");
  #endif
  int temp;
  for (int i = 1; i <= (B+1)/2; i++)
  {
    temp = a[i];
    a[i] = a[R(i)];
    a[R(i)] = temp;
  }
  temp = l;
  l = R(r);
  r = R(temp);
}

void complement(){
  for (int i = 1; i <= B; i++)
  {
    if(a[i] == 1){
      a[i] = 0;
    }else if(a[i] == 0){
      a[i] = 1;
    }
  }
}

void clear(){
  for (int i = 0; i <= B; i++)
  {
    a[i] = EMPTY;
  }
}



int main(){
  scanf("%d %d", &T, &B);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  for (int t = 0; t < T; t++)
  {
    clear();
    char result;

    l = 1;
    r = B;
    int request = 0;
    bool left = true;
    int cur = 0;
    int input, input2;
    int same, oppo;
    same = oppo = 0;
    bool normal;

    while(r>=l){
      normal = false;
      request++;
      if(request<=10){
        normal = true;
        if(l<=R(r)){
          cur = l;
          l++;
          left=true;
        }else{
          cur = r;
          r--;
          left = false;
        }
        printf("%d\n", cur);
        scanf("%d", &input);
        a[cur] = input;
      }else{

        if(same && !oppo && request%10 == 1){
          request++;
          printf("%d\n", same);
          scanf("%d", &input);
          printf("%d\n", same);
          scanf("%d", &input);
          if(a[same]!=input){
            #ifdef DEBUG
            fprintf(stderr, "bitflip detected, request = %d\n", request);
            #endif
            complement();
          }
        }else if(oppo && !same && request%10 == 1){
          request++;
          printf("%d\n", oppo);
          scanf("%d", &input);
          printf("%d\n", oppo);
          scanf("%d", &input);
          if(a[oppo]!=input){
            #ifdef DEBUG
            fprintf(stderr, "bitflip detected, request = %d\n", request);
            #endif
            complement();
          }
        }else if(same && oppo && request%10 == 1){
          request++;
          printf("%d\n", same);
          scanf("%d", &input);
          printf("%d\n", oppo);
          scanf("%d", &input2);
          #ifdef DEBUG
          fprintf(stderr, "%d %d %d %d\n", a[same], input, a[oppo], input2);
          #endif
          if(a[same] == input && a[oppo] == input2){
            //not much
          }else if(a[same] != input && a[oppo] != input2){
            #ifdef DEBUG
            fprintf(stderr, "bitflip detected, request = %d\n", request);
            #endif
            complement();
          }else if(a[oppo] != input2){
            #ifdef DEBUG
            fprintf(stderr, "reverse detected, request = %d\n", request);
            #endif
            reverse();
          }else if(a[oppo] == input2){
            #ifdef DEBUG
            fprintf(stderr, "bitflip and reverse detected, request = %d\n", request);
            #endif
            reverse();
            complement();
          }
        }else{
          normal = true;
          if(l<=R(r)){
            cur = l;
            l++;
            left = true;
          }else{
            cur = r;
            r--;
            left = false;
          }
          printf("%d\n", cur);
          scanf("%d", &input);
          a[cur] = input;
        }
      }

      #ifdef DEBUG
      fprintf(stderr, "request#: %d, [%d] = %d, l: %d r: %d\n", request, cur, a[cur], l, r);
      #endif

      if(normal && a[cur]!=EMPTY && a[R(cur)]!=EMPTY){
        if(a[R(cur)] == a[cur]){
          if(!same){
            same = R(cur);
            #ifdef DEBUG
            fprintf(stderr, "Found same pair: %d\n", same);
            #endif
          }
        }else{
          if(!oppo){
            oppo = R(cur);
            #ifdef DEBUG
            fprintf(stderr, "Found oppo pair: %d\n", oppo);
            #endif
          }
        }
      }
    }

    memset(outputString, 0, sizeof(outputString));


    for (int i = 0; i < B; i++)
    {
      outputString[i] = a[i+1]+'0';
    }
    #ifdef DEBUG
    fprintf(stderr, "printing output for test case %d\n", t);
    #endif
    printf("%s\n", outputString);
    result = 0;
    while(result!='Y'){
      scanf("%c", &result);
      if(result == 'N')return 0;
    }
  }
  
  //REMOVE ME
  // scanf("%d", &T);

  return 0;
}