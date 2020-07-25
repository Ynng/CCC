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

__int64 __fastcall f(signed int x, __int64 y, __int64 z)
{
  int v4; // ebx
  __int64 v5; // rdx
  int v6; // ebx
  int v7; // ebx
  double v8; // xmm0_8
  __int64 v9; // rdx

  if ( x <= 3 )
    return (unsigned int)(x + 5);
  v4 = f(x - 1, y, z);
  v6 = (unsigned __int64)f(x - 5, y, v5) + v4;
  v7 = 2 * (unsigned __int64)f(x / 3, y, (unsigned __int64)(1431655766LL * x) >> 32) + v6;
  v8 = sqrt((double)x);
  return (signed int)(v7 + 3 * (unsigned __int64)f((signed int)v8, y, v9)) / 3;
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  __int64 v3; // rdx
  __int64 v4; // rdx
  __int64 v5; // rdx
  __int64 v6; // rdx
  __int64 v7; // rdx
  int v8; // ebx
  __int64 v9; // rdx
  int v10; // ebx
  __int64 v11; // rdx
  int v12; // ebx
  __int64 v13; // rdx
  int v14; // ebx
  __int64 v15; // rdx
  __int64 v16; // rdx
  __int64 v17; // rdx
  __int64 v18; // rdx
  __int64 v19; // rdx
  signed int v20; // eax
  __int64 v21; // rdx
  __int64 v22; // rdx
  signed int v23; // eax
  __int64 v24; // rdx
  __int64 v25; // rdx
  int v26; // ebx
  __int64 v27; // rdx
  __int64 v28; // rdx
  __int64 v29; // rdx
  unsigned int v30; // edx
  signed int i; // [rsp+Ch] [rbp-14h]

  s[0] = f(45599, (__int64)argv, (__int64)envp);
  dword_4064 = f(47918, (__int64)argv, v3);
  dword_4068 = f(50202, (__int64)argv, v4);
  dword_406C = f(42571, (__int64)argv, v5);
  dword_4070 = f(49330, (__int64)argv, v6);
  v8 = f(0, (__int64)argv, v7);
  s[v8] = f(59051, (__int64)argv, v9);
  v10 = f(1, (__int64)argv, (__int64)s);
  s[v10] = f(46529, (__int64)argv, v11);
  v12 = f(2, (__int64)argv, (__int64)s);
  s[v12] = f(42537, (__int64)argv, v13);
  v14 = f(3, (__int64)argv, (__int64)s);
  s[v14] = f(54741, (__int64)argv, v15);
  dword_4084 = f(43886, (__int64)argv, (__int64)s);
  dword_4088 = f(45599, (__int64)argv, v16);
  dword_408C = f(47849, (__int64)argv, v17);
  dword_4090 = f(45441, (__int64)argv, v18);
  v20 = f(23682, (__int64)argv, v19);
  dword_4094 = f(v20, (__int64)argv, v21);
  v23 = f(27906, (__int64)argv, v22);
  dword_4098 = f(v23, (__int64)argv, v24);
  v26 = f(5, (__int64)argv, v25);
  s[v26] = f(46250, (__int64)argv, v27);
  dword_40A0 = f(18259, (__int64)argv, (__int64)s);
  dword_40A4 = f(44487, (__int64)argv, v28);
  dword_40A8 = f(63833, (__int64)argv, v29);
  for ( i = 0; i <= 18; ++i )
  {
    putchar(s[i] / 256);
    if ( (unsigned __int8)s[i] )
    {
      v30 = s[i] >> 31;
      putchar((unsigned __int8)(HIBYTE(v30) + s[i]) - (v30 >> 24));
    }
  }
  return 0;
}

// int main()
// {

//   return 0;
// }