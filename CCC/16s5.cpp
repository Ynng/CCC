#include <iostream>
#include "math.h"

typedef long long ll;

bool circleA[100005];
bool circleB[100005];
bool A;
ll n, t;

ll wrap(ll a, ll b){
  ll temp = (a+b)%n;
  return temp<0?temp+n:temp;
}
void evaluate(ll k){
  // printf("evaled %lld\n", k);
  for (ll j = 0; j < n; j++)
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
    //only read 1 number
    scanf("%1d", &circleA[i]);
  }
  A = true;

  ll log2t = log2(t);

  for(int i = log2t; i>=1 ; i--){
    ll temp = pow(2,i);
    if(temp<=t){
      t-=temp;
      evaluate(temp);
    }
  }
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
