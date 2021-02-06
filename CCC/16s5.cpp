#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int MX = 100000 + 5;

bool circleA[MX];
bool circleB[MX];
bool A;
ll N, T;

ll wrap(ll a, ll b){
  ll temp = (a+b)%N;
  return temp<0?temp+N:temp;
}
void evaluate(ll k){
  // printf("evaled %lld\N", k);
  for (ll j = 0; j < N; j++)
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
  scanf("%lld %lld", &N, &T);
  scanf("%s", circleA); //Why does this work!?
  // for (int i = 0; i < N; i++)
  //   printf("%d ", circleA[i]);
  A = true;

  ll log2t = log2(T);

  for(int i = log2t; i>=1 ; i--){
    ll temp = pow(2,i);
    if(temp<=T){
      T-=temp;
      evaluate(temp);
    }
  }
  if(T==1){
    T-=1;
    evaluate(1);
  }

  for (int i = 0; i < N; i++)
  {
    if(A)
    printf("%d", circleA[i]);
    else
    printf("%d", circleB[i]);
  }

  return 0;
}
