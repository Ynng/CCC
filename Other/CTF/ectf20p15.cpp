#define __int64 long long
#include <cmath>
#include <stdio.h>
#include <windef.h>

__int64 memo[100000];
int offset = 1000;

__int64 __fastcall f(signed int x, __int64 y, __int64 z)
{
  int v4;     // ebx
  __int64 v5; // rdx
  int v6;     // ebx
  int v7;     // ebx
  double v8;  // xmm0_8
  __int64 v9; // rdx

  if(memo[x + offset]!=-10000000)
    return memo[x + offset];

  if (x <= 3)
    return (unsigned int)(x + 5);
  v4 = f(x - 1, y, z);
  v6 = (unsigned __int64)f(x - 5, y, v5) + v4;
  v7 = 2 * (unsigned __int64)f(x / 3, y, (unsigned __int64)(1431655766LL * x) >> 32) + v6;
  v8 = sqrt((double)x);

  signed int output = (signed int)(v7 + 3 * (unsigned __int64)f((signed int)v8, y, v9)) / 3;
  // printf("%d %d\n", x, output);
  
  memo[x + offset] = output;

  return output;
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  __int64 v3;       // rdx
  __int64 v4;       // rdx
  __int64 v5;       // rdx
  __int64 v6;       // rdx
  __int64 v7;       // rdx
  int v8;           // ebx
  __int64 v9;       // rdx
  int v10;          // ebx
  __int64 v11;      // rdx
  int v12;          // ebx
  __int64 v13;      // rdx
  int v14;          // ebx
  __int64 v15;      // rdx
  __int64 v16;      // rdx
  __int64 v17;      // rdx
  __int64 v18;      // rdx
  __int64 v19;      // rdx
  signed int v20;   // eax
  __int64 v21;      // rdx
  __int64 v22;      // rdx
  signed int v23;   // eax
  __int64 v24;      // rdx
  __int64 v25;      // rdx
  int v26;          // ebx
  __int64 v27;      // rdx
  __int64 v28;      // rdx
  __int64 v29;      // rdx
  unsigned int v30; // edx
  signed int i;     // [rsp+Ch] [rbp-14h]

  for (int i = 0; i < 100000; i++)
  {
    memo[i] = -10000000;
  }

  for (int i = 0; i < 70000; i++)
  {
    f(i,0,0);
  }

  // while(true){
  //   int input;
  //   scanf("%d", &input);
  //   printf("\n%d\n", f(input, 0, 0));
  // }

  int s[20];

  s[0] = f(45599, (__int64)argv, (__int64)envp);
  s[1] = f(47918, (__int64)argv, v3);
  s[2] = f(50202, (__int64)argv, v4);
  s[3] = f(42571, (__int64)argv, v5);
  s[4] = f(49330, (__int64)argv, v6);
  v8 = f(0, (__int64)argv, v7);
  s[5] = f(59051, (__int64)argv, v9);
  v10 = f(1, (__int64)argv, (__int64)s);
  s[6] = f(46529, (__int64)argv, v11);
  v12 = f(2, (__int64)argv, (__int64)s);
  s[7] = f(42537, (__int64)argv, v13);
  v14 = f(3, (__int64)argv, (__int64)s);
  s[8] = f(54741, (__int64)argv, v15);
  s[9] = f(43886, (__int64)argv, (__int64)s);
  s[10] = f(45599, (__int64)argv, v16);
  s[11] = f(47849, (__int64)argv, v17);
  s[12] = f(45441, (__int64)argv, v18);
  v20 = f(23682, (__int64)argv, v19);
  s[13] = f(v20, (__int64)argv, v21);
  v23 = f(27906, (__int64)argv, v22);
  s[14] = f(v23, (__int64)argv, v24);
  v26 = f(5, (__int64)argv, v25);
  // printf("%d\n\n\n", v26);
  s[17] = f(46250, (__int64)argv, v27);
  s[16] = f(18259, (__int64)argv, (__int64)s);
  s[17] = f(44487, (__int64)argv, v28);
  s[18] = f(63833, (__int64)argv, v29);

  s[15] = 0;

  for (i = 0; i <= 18; ++i)
  {
    // printf("%d, ", s[i]);
    // printf("%d: ", i);

    putchar(s[i] / 256);
    if ((unsigned __int8)s[i])
    {
      v30 = s[i] >> 31;
      putchar((unsigned __int8)(HIBYTE(v30) + s[i]) - (v30 >> 24));
    }

    // printf("\n");
  }

  scanf("%d");
  scanf("%d");
  scanf("%d");
  return 0;
}