#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

//not working

#define CURRENT repeated[currentIndex]!=0?repeated[currentIndex]:currentIndex

int q, x;
char tempChar;
vector<string> a;
vector<int> output;
map<int, map<char, int>> mapping; //index + char -> next index
map<int, int> repeated; //index -> first same index
string temp;
char s[400005];

void printList()
{
  for (int i = 0; i < a.size(); i++)
  {
    printf("%s\n", a[i].c_str());
  }
}

int recursion(int currentIndex, int charIndex)
{
  //there are more characters, but there's no where to go
  // printf("recursion on %d %d", currentIndex, charIndex);
  if(mapping[CURRENT][temp[charIndex]]==0){
    return currentIndex;
  }
  if(charIndex>=temp.length()){
    //if this is the last character, and because this function is called, this item exist, therefore this is the answer
    return currentIndex;
  }
  return recursion(mapping[CURRENT][temp[charIndex]], charIndex+1);
}

int main()
{
  bool bad;
  std::cin >> temp;
  a.push_back(temp);
  scanf("%d", &q);
  for (int query = 0; query < q; query++)
  {
    scanf("\n%c", &tempChar);
    if (tempChar == 'C')
    {
      scanf("%d %c", &x, &tempChar);
      a.push_back(a[x - 1] + tempChar);
      if(mapping[repeated[x-1]==0?x-1:repeated[x-1]][tempChar]!=0){
        repeated[a.size()-1] = mapping[repeated[x-1]==0?x-1:repeated[x-1]][tempChar];
      }else{
        mapping[repeated[x-1]==0?x-1:repeated[x-1]][tempChar] = a.size()-1;
      }
    }
    else if (tempChar == 'Q')
    {
      scanf("%s", s);
      temp = string(s);
      //if the string doesnt even match the first entry
      bad = false;
      for (int i = 0; i < a[0].length() && i < temp.length(); i++)
      {
        if (a[0][i] != temp[i])
        {
          bad = true;
          break;
        }
      }
      if(bad){
        output.push_back(-1);
      }else{
        if(temp.length()<a[0].length()){
          output.push_back(1);
        }else{
          output.push_back(recursion(0, a[0].length())+1);
        }
      }
      // printf("\nread Q: %s, length:%d", temp.c_str(), temp.length());
    }
  }
  // printList();
  if(output.size()>=1){
    printf("%d", output[0]);
  }
  for (int i = 1; i < output.size(); i++)
  {
    printf("\n%d", output[i]);
  }
  
  return 0;
}
