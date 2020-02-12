
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
long long t,x;
double speed;
double maxSpeed;
vector<pair<long long, long long>> inputs;
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld  %lld", &t, &x);
    inputs.push_back({t,x});
  }

  sort(inputs.begin(), inputs.end(), [](const pair<long long,long long> &left, const pair<long long,long long> &right) {
    return left.first < right.first;
  });
  
  maxSpeed = 0;
  for (int i = 1; i < n; i++)
  {
    speed = abs(((inputs[i].second-inputs[i-1].second)*1.0)/(inputs[i].first-inputs[i-1].first));
    if(speed>maxSpeed)maxSpeed = speed;
    // printf("%lld %lld\n", inputs[i].first, inputs[i].second);
  }
  printf("%f", maxSpeed);

  
  
  return 0;
}
