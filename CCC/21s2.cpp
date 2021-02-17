#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 5000000 + 5;

int M, N, K;
int R, C;
ll sum;
bool RT[MX];
bool CT[MX];

int main()
{
  scanf("%d %d %d", &M, &N, &K);
  R=M;
  C=N;
  for(int i = 1; i <= K; i++)
  {
    char op;
    int x;
    scanf(" %c %d", &op, &x);
    if(op=='R'){
      if(RT[x]==0){
        sum+=C;
        sum-=(N-C);
        R--;
      }else{
        sum-=C;
        sum+=(N-C);
        R++;
      }
      RT[x]=!RT[x];
    }else{
      if(CT[x]==0){
        sum+=R;
        sum-=(M-R);
        C--;
      }else{
        sum-=R;
        sum+=(M-R);
        C++;
      }
      CT[x]=!CT[x];
    }
  }

  printf("%lld\n", sum);

  return 0;
}