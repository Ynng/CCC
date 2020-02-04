#include <iostream>
#include "math.h"

bool circleA[100005];
bool circleB[100005];
bool A;
long long n, t, tempA, tempB, tempC;

long long wrap(long long a, long long b){
  tempA = (a+b)%n;
  return tempA<0?tempA+n:tempA;
}
void evaluate(long long k){
  // printf("evaled %lld\n", k);
  for (long long j = 0; j < n; j++)
  {
    if (A)
      circleB[j] = circleA[wrap(j,k)] ^ circleA[wrap(j,-k)];
    else
      circleA[j] = circleB[wrap(j,k)] ^ circleB[wrap(j,-k)];
  }
  A = !A;
}
int main()
{
  scanf("%lld %lld", &n, &t);
  for (int i = 0; i < n; i++)
  {
    scanf("%1d", &circleA[i]);
  }
  A = true;
  tempB = (int)(floor(log2(t))+0.5);
  // std::cout<<"tempB"<<tempB<<std::endl;
  for(int i = tempB; i>=1 ; i--){
    tempC = (long long)(floor(pow(2,i))+0.5);
      // std::cout<<"t " << t <<  " | tempC "<<tempC<<std::endl;
    if(tempC<=t){
      t-=tempC;
      evaluate(tempC);
    }
  }
  // std::cout<<"t " << t << std::endl;
  if(t==1){
    t-=1;
    evaluate(1);
  }

  for (int i = 0; i < n; i++)
  {
    if(A)
    printf("%d", circleA[i]);
    else
    printf("%d", circleB[i]);
  }

  return 0;
}
