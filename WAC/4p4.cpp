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

using namespace std;

bool onlyNines(const string &str)
{
    return str.find_first_not_of("9") == string::npos;
}

int main(){

  string s;
  cin>>s;
  string haystack;
  int size = s.length();
  string proStr = "";
  bool good = false;
  int offset = -1;
  int initial = -1;
  for (int d = 1; d <= size; d++)
  {
    //d for digits
    for (int o = 0; o < d; o++)
    {
      int special = 0;
        printf("a");

      if(onlyNines(s.substr(0, d-o)) && o>0){
        special = 1;
        printf("b");
        string temp1 = s.substr(d-o,o);
        int temp = stoi(temp1)-1;
        string temp2 = to_string(temp);
        proStr =  temp2 + s.substr(0, d-o);
      }else
        proStr =  s.substr(d-o,o) + s.substr(0, d-o);
      int init = stoi(proStr);

      // printf("init: %d\n", ini);

      int pro = init-1;
      int digitAt = d;
      good = true;
      bool skip = false;

      for(int i = 0; i<s.length(); i++){1
        if(digitAt == 0){
          pro++;
          digitAt = 0;
          proStr = to_string(pro);
        }
        
        cout<<"str "<<proStr<<endl;
        printf("%c %c\n\n", proStr.at(i%d), s.at(i));
        printf(digitAt)
        if(proStr.at(d-digitAt)!=s.at(i)){
          skip = true;
          printf("breaking A");
          break;
        }
        digitAt--;
      }

      if(!skip){
        printf("breaking B");
        good= true;
        offset = o;
        initial = init;
        break;
      }
    }
    if(good)break;
  }

  printf("%d %d", initial, offset);
  scanf("%d", &offset);
}