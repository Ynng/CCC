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

#include <windef.h>

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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9 + 7, MX = 10005;

int variables;

// ll method(int x, ll y, ll z)
// {
//   ll v5;
//   ll v9;

//   if (x <= 3)
//     return (unsigned int)(x + 5);
//   int v4 = method((unsigned int)(x-1), y, z);
//   int v6 = (unsigned long long)method((unsigned int)(x-5), y, v5) + v4;
//   int v7 = 2 * (unsigned long long)method(x / 3, y, (unsigned long long)(1431655766LL * x) >> 32) + v6;
//   double v8 = sqrt((double)x);
//   return (signed int)(v7 + 3 * (unsigned long long)method((unsigned int)(signed int)v8, y, v9)) / 3;
// }

ll memo[100000];
int offset = 100;

ll f(int x)
{
  int v4;    // ebx
  ll v5;     // rdx
  int v6;    // ebx
  int v7;    // ebx
  double v8; // xmm0_8
  ll v9;     // rdx

  if(memo[x + offset] != -10000000)
    return memo[x + offset];

  if (x <= 3)
    return (unsigned int)(x + 5);
  v4 = f(x - 1);
  v6 = (unsigned ll)f(x - 5) + v4;
  v7 = 2 * (unsigned ll)f(x / 3) + v6;
  v8 = sqrt((double)x);

  int output = (int)(v7 + 3 * (unsigned ll)f((int)v8)) / 3;

  memo[x + offset] = output;

  // if(x % 1000 == 0)
  //   printf("%d %d\n", x, output);
  return output;
}

ll foriginal(signed int x, ll y, ll z)
{
  int v4;    // ebx
  ll v5;     // rdx
  int v6;    // ebx
  int v7;    // ebx
  double v8; // xmm0_8
  ll v9;     // rdx

  if (x <= 3)
    return (unsigned int)(x + 5);
  v4 = foriginal(x - 1, y, z);
  //   printf("%d\n", v4);
  v6 = (unsigned ll)foriginal(x - 5, y, v5) + v4;
  v7 = 2 * (unsigned ll)foriginal(x / 3, y, (unsigned ll)(1431655766LL * x) >> 32) + v6;

  v8 = sqrt((double)x);
  return (signed int)(v7 + 3 * (unsigned ll)foriginal((signed int)v8, y, v9)) / 3;
}

int main(int argc, const char **argv, const char **envp)
{
  for(int i = 0; i < 100000; i++){
    memo[i] = -10000000;
  }

  for (int i = 0; i < 70000; i++)
  {
    f(i);
    // ll y = 1235134, z = 123123613;
    // printf("i = %d, answer = %lld", i, f(i));
    // if (foriginal(i, y, z) == f(i))
    //   printf(" same");
    // else
    //   printf(" DIFFERENT!!!!!!");
  }
  // scanf("%d");

  ll v3; // rdx
  ll v4; // rdx
  ll v5; // rdx
  ll v6; // rdx
  ll v7; // rdx
  int v8; // ebx
  ll v9; // rdx
  int v10; // ebx
  ll v11; // rdx
  int v12; // ebx
  ll v13; // rdx
  int v14; // ebx
  ll v15; // rdx
  ll v16; // rdx
  ll v17; // rdx
  ll v18; // rdx
  ll v19; // rdx
  signed int v20; // eax
  ll v21; // rdx
  ll v22; // rdx
  signed int v23; // eax
  ll v24; // rdx
  ll v25; // rdx
  int v26; // ebx
  ll v27; // rdx
  ll v28; // rdx
  ll v29; // rdx
  unsigned int v30; // edx
  signed int i; // [rsp+Ch] [rbp-14h]


  ll s[18];

  s[0] = f(45599);
  s[1] = f(47918);
  s[2] = f(50202);
  s[3] = f(42571);
  s[4] = f(49330);
  // v8 = f(0,  v7);
  s[5] = f(59051);
  // v10 = f(1,  (ll)s);
  s[6] = f(46529);
  // v12 = f(2,  (ll)s);
  s[7] = f(42537);
  // v14 = f(3,  (ll)s);
  s[8] = f(54741);
  s[9] = f(43886);
  s[10] = f(45599);
  s[11] = f(47849);
  s[12] = f(45441);

  v20 = f(23682);
  s[13] = f(v20);

  v23 = f(27906);
  s[14] = f(v23);

  // v26 = f(5,  v25);
  s[15] = f(46250); //Maybe? just maybe? change this to 15?

  s[16] = f(18259);
  s[17] = f(44487);
  s[18] = f(63833);


  for ( i = 0; i <= 18; ++i )
  {
    // printf("i = %d     ", i);

    putchar(s[i] / 256);
    if ( (unsigned __int8)s[i] )
    {
      v30 = s[i] >> 31;
      putchar((unsigned __int8)(HIBYTE(v30) + s[i]) - (v30 >> 24));
    }

    // printf("\n");
  }

  scanf("%d");
  return 0;
}

// int main()
// {

//   return 0;
// }