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

#define R(i) (ilen-i-1)

int T, N;
char input[105];
char s[105], e[105], m[10005];

int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    memset(s, 0, sizeof s);
    memset(m, 0, sizeof m);

    memset(e, 0, sizeof e);
    int slen, elen;
    bool good = true;
    slen = elen = 0;
    int mlen = 0;
    int l,r;

    scanf("%d", &N);
    for (int n = 0; n < N; n++)
    {
      memset(input, 0, sizeof input);
      scanf("%s", input);
      int ilen = strlen(input);
      
      // if(input[0]!='*'){
        if(!good)continue;
        for (int i = 0; i < ilen; i++)
        {
          if(input[i] == '*'){
            l=i;
            break;
          }
          if(i<slen){
            if(input[i]!=s[i]){
              good = false;
              break;
            }
          }else{
            slen++;
            s[i] = input[i];
          }
        }
        if(!good)continue;
      // }

      // if(input[R(0)]!='*'){
        for (int i = 0; i < ilen; i++)
        {
          if(input[R(i)] == '*'){
            r = R(i);
            break;
            }
          if(i<elen){
            if(input[R(i)]!=e[i]){
              good = false;
              break;
            }
          }else{
            elen++;
            e[i] = input[R(i)];
          }
        }
        if(!good)continue;
      // }


      if(l!=r){
        for (int i = l+1; i < r; i++)
        {
          if(input[i]!='*'){
            m[mlen] = input[i];
            mlen++;
          }
        }
      }


    }
    if(t!=1)printf("\n");
    printf("Case #%d: ", t);
    if(!good)printf("*");
    else{
      // for(int i = 1; i <= (slen<elen?slen:elen); i++){
      //   if(s[slen-i]==e[i-1]){
      //     s[slen-i] = 0;
      //   }else break;
      // }
      std::reverse(e, e+elen);
      printf("%s%s%s", s,m, e);
    }
  }
}