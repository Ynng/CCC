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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
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

const int MOD = 1e9+7, MX = 10005;

int variables;

int main(int argc, char **argv)
{
  char *mainString; // rbp
  signed int length; // eax
  signed int len; // edi
  signed int b; // er8
  char *pointer; // rcx
  int i; // esi
  char currentChar; // al
  long long left; // rdx
  const char *rightCharAdd; // rcx
  char v12; // al
  char v13; // al

  mainString = argv[1];
  length = strlen(argv[1]);
  if ( length <= 0 )
    goto LABEL_11;
  len = length;
  b = length;
  pointer = (char *)mainString;
  i = 0;
  do
  {

    //loop until there's no more number
    while ( 1 )
    {
      currentChar = *pointer;
      if ( (unsigned __int8)(*pointer - 48) > 9u )
        break;


      //if it's a number
      *pointer = 105 - currentChar;
LABEL_4:
      ++i;
      ++pointer;
      if ( b == i )
        goto EndOfProgram;
    }

    //{ }, _, and UPPERCASE
    if ( (unsigned __int8)(currentChar - 97) > 0x19u )
    {
      //{ } and _
      if ( (unsigned __int8)(currentChar - 65) > 0x19u )
      {
        switch ( currentChar )
        {
          case 123:
            *pointer = 126;
            break;
          case 125:
            *pointer = 124;
            break;
          case 95:
            *pointer = i % 10 + 33;//
            break;
        }
      }
      //UPPERCASE 65 to 90
      //          94 to 119
      else
      {
        *pointer = currentChar + 29;
      }
      goto LABEL_4;
    }
    //lowercase
    //decrease by 36
    //97 to 122
    //61 to 86
    ++i;
    *(++pointer - 1) = currentChar - 36;
  }
  while ( b != i );
EndOfProgram:
  if ( len > 1 )
  {
    left = 0LL;
    rightCharAdd = &mainString[len - 1];
    do
    {
      //     right character    ^ left character
      v12 = *rightCharAdd-- ^ mainString[left];

      //left character is now right character    ^ left character
      mainString[left] = v12;

      //    right character ^ (right character ^ left character) = left character
      v13 = rightCharAdd[1] ^ v12;

      //right character is now left character
      *((unsigned __int8 *)rightCharAdd + 1) = v13;

      //right character    ^ left character ^  left character = right
      mainString[left++] ^= v13;


      //left char = right;
      //right char = left;
      //left ++;
      //len = 37
      //len/2 = 
    }
    while ( len / 2 > (signed int)left );
  }
LABEL_11:
  puts(mainString);
  return 0;
}