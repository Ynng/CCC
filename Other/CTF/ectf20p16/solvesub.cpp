#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, int> pil;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9 + 7, MX = 10005;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Returns LCM of array elements
ll findlcm(int arr[], int n)
{
  // Initialize result
  ll ans = arr[0];

  // ans contains LCM of arr[0], ..arr[i]
  // after i'th iteration,
  for (int i = 1; i < n; i++)
  {
    ans = (((arr[i] * ans)) /
           (gcd(arr[i], ans)));

    if (ans < 0)
      printf("LL OVERFOW: %d, %lld\n", i + 1, ans);
    else
      printf("%d, %lld\n", i  + 1, ans);
  }

  return ans;
}

int main()
{
  int shuf[256] = {80, 30, 5, 163, 108, 81, 41, 22, 66, 132, 226, 197, 19, 251, 72, 157, 212, 51, 40, 94, 237, 131, 255, 21, 198, 187, 6, 45, 107, 52, 85, 74, 168, 116, 183, 166, 181, 55, 48, 37, 3, 231, 50, 224, 232, 239, 179, 77, 64, 220, 31, 84, 61, 104, 36, 147, 75, 14, 134, 169, 92, 184, 227, 137, 143, 244, 165, 43, 247, 205, 154, 67, 56, 73, 113, 102, 253, 69, 68, 35, 11, 106, 23, 225, 122, 124, 58, 128, 83, 254, 161, 216, 38, 243, 214, 236, 178, 211, 119, 4, 238, 162, 159, 44, 133, 2, 109, 186, 12, 26, 123, 57, 221, 206, 110, 248, 177, 146, 138, 203, 140, 18, 99, 218, 199, 111, 65, 103, 209, 228, 13, 76, 153, 241, 250, 60, 182, 202, 204, 222, 213, 32, 160, 174, 130, 167, 245, 155, 63, 172, 195, 188, 194, 235, 246, 62, 208, 33, 28, 98, 59, 93, 192, 180, 16, 100, 29, 97, 120, 114, 135, 142, 234, 101, 171, 24, 230, 79, 189, 117, 10, 54, 9, 136, 126, 150, 176, 7, 0, 217, 49, 34, 152, 229, 148, 252, 87, 121, 39, 233, 25, 175, 200, 141, 47, 190, 118, 215, 207, 149, 105, 88, 91, 151, 127, 90, 95, 223, 201, 96, 249, 173, 89, 242, 86, 70, 164, 170, 129, 196, 144, 112, 20, 42, 115, 8, 139, 78, 191, 158, 145, 125, 17, 71, 219, 46, 156, 193, 15, 1, 185, 27, 240, 210, 53, 82};


  int chars[37] = {160, 125, 44, 12, 64, 15, 110, 53, 253, 228, 154, 197, 88, 185, 115, 124, 20, 69, 226, 90, 146, 154, 137, 62, 158, 170, 241, 173, 127, 50, 95, 124, 151, 175, 210, 112, 153};

  int iter[257];

  for (int i = 0; i < 37; i++)
  {
    int start = 153;
    int cur = shuf[start];
    int counter = 1;
    while (true)
    {
      cur = shuf[cur];
      counter++;
      if (cur == start)
        break;
    }
    iter[i] = counter;
    printf("%d, ", counter);
  }

  printf("\nLCM: %lld", findlcm(iter, 37));
  //LCM 7324716584916787658
  //140612491110

  // iter[256] = 380;
  // printf("LCM with 380: %lld", findlcm(iter, 257));

  scanf("%d");
  return 0;
}