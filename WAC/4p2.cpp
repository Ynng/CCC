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

typedef long long ll;

ll N;
ll pro[5005][2];
ll goal = 0;
ll dp[6000][6000];

ll ks(ll n, ll c){
  ll result;

  if(c<=0)result = 0;
  else if(n<0)result = 9000000000000000;
  else if(dp[n][c]!=0){
    if(dp[n][c]==-1)return 0;
    else return dp[n][c];
  }
  else{
    ll temp1 = ks(n-1, c);
    ll temp2 = ks(n-1, c-pro[n][1]) + pro[n][0];
    result = std::min(temp1, temp2);
  }

  if(!(n<0 || c<0)){
    if(result==0)dp[n][c]=-1;
    else dp[n][c] = result;
  }
  return result;
}

int main(){
  memset(dp, 0, sizeof(dp));
  scanf("%lld", &N);
  ll temp;
  for (ll i = 0; i < N; i++)
  {
    scanf("%lld %lld", &temp, &pro[i][1]);
    pro[i][0] = (temp+2)/2;
    goal+=pro[i][1];
  }
  goal=(goal+2)/2;
  ll answer = ks(N, goal);
  printf("%lld\n", answer);
}