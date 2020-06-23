//https://dmoj.ca/problem/pathfind

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
// #define DEBUG

#define I elements[j]

using namespace std;
typedef long long ll;

struct Block
{
    int row;
    int col;
    bool up;
    bool down;
    bool left;
    bool right;
};

int N, M, K;


bool compareBlockUp(Block a, Block b) 
{ 
  return (ll)a.row*M + a.col < (ll)b.row*M + b.col;
  // return a.row < b.row;
} 

bool compareBlockLeft(Block a, Block b) 
{ 
  return (ll)a.col*N + a.row < (ll)b.col*N + b.row;
  // return a.col < b.col;
} 

Block blocks[500005];
int exist[2][500005];
int elements[500005];


int main(int argc, char const *argv[])
{

  scanf("%d %d %d", &N, &M, &K);
  int tempCol, tempRow;
  for (int i = 0; i < K; i++)
  {
    scanf("%d %d", &tempRow, &tempCol);
    // blocks[i] = {tempRow, tempCol, tempRow == 1, tempRow == N, tempCol == 1, tempCol == M};
    blocks[i] = {tempRow, tempCol, false, false, false, false};
  }

  int elementsCounter = 0;
  
  memset(exist,0,sizeof(exist[0]) * 2);
  sort(blocks, blocks + K, compareBlockUp);
  tempRow = 0;
  bool currentArr = 0;
  bool brokenLayer = false;
  for (int i = 0; i < K; i++)
  {
    if(tempRow == blocks[i].row - 1){
      if(brokenLayer)break;
      brokenLayer = true;

      for (int j = elementsCounter-1; j >= 0; j--)
      {
        if(exist[currentArr][blocks[I].col] == tempRow){
          blocks[I].up = true;
          exist[currentArr][blocks[I].col] = tempRow;
          exist[currentArr][blocks[I].col + 1] = tempRow;
          exist[currentArr][blocks[I].col - 1] = tempRow;
        }
      }

      elementsCounter = 0;
      currentArr = !currentArr;
      // memset(exist[currentArr],0,sizeof(exist[currentArr]));
      tempRow = blocks[i].row;
    }else if(tempRow != blocks[i].row){
      break;
    }

    elements[elementsCounter] = i;
    elementsCounter++;

    if(exist[!currentArr][blocks[i].col] == tempRow - 1 || tempRow == 1 || exist[currentArr][blocks[i].col - 1] == tempRow || exist[currentArr][blocks[i].col + 1] == tempRow){
      brokenLayer = false;
      blocks[i].up = true;
      exist[currentArr][blocks[i].col] = tempRow;
      exist[currentArr][blocks[i].col + 1] = tempRow;
      exist[currentArr][blocks[i].col - 1] = tempRow;
    }
  }



  elementsCounter = 0;
  memset(exist,0,sizeof(exist[0]) * 2);
  brokenLayer = false;
  // sort(blocks, blocks + K, compareBlockDown);
  tempRow = N + 1;
  for (int i = K-1; i >= 0; i--)
  {
    if(tempRow == blocks[i].row + 1){
      if(brokenLayer)break;
      brokenLayer = true;

      for (int j = elementsCounter-1; j >= 0; j--)
      {
        if(exist[currentArr][blocks[I].col] == tempRow){
          blocks[I].down = true;
          exist[currentArr][blocks[I].col] = tempRow;
          exist[currentArr][blocks[I].col + 1] = tempRow;
          exist[currentArr][blocks[I].col - 1] = tempRow;
        }
        
        if(blocks[I].down && blocks[I].up){
          printf("NO");
          return 0;
        }
      }

      elementsCounter = 0;

      currentArr = !currentArr;
      // memset(exist[currentArr],0,sizeof(exist[currentArr]));
      tempRow = blocks[i].row;
    }else if(tempRow != blocks[i].row){
      break;
    }

    elements[elementsCounter] = i;
    elementsCounter++;

    if(exist[!currentArr][blocks[i].col] == tempRow + 1 || tempRow == N){
      brokenLayer = false;
      blocks[i].down = true;
      exist[currentArr][blocks[i].col] = tempRow;
      exist[currentArr][blocks[i].col + 1] = tempRow;
      exist[currentArr][blocks[i].col - 1] = tempRow;
    }

    if(blocks[i].down && blocks[i].up){
      printf("NO");
      return 0;
    }
  }

  elementsCounter = 0;
  memset(exist,0,sizeof(exist[0]) * 2);
  sort(blocks, blocks + K, compareBlockLeft);
  brokenLayer = false;
  tempCol = 0;
  for (int i = 0; i < K; i++)
  {
    if(tempCol == blocks[i].col - 1){
      if(brokenLayer)break;
      brokenLayer = true;

      for (int j = elementsCounter-1; j >= 0; j--)
      {
        if(exist[currentArr][blocks[I].row] == tempCol){
          blocks[I].left = true;
          exist[currentArr][blocks[I].row] = tempCol;
          exist[currentArr][blocks[I].row + 1] = tempCol;
          exist[currentArr][blocks[I].row - 1] = tempCol;
        }
        
        if(blocks[I].left && blocks[I].up){
          printf("NO");
          return 0;
        }
      }

      elementsCounter = 0;

      currentArr = !currentArr;
      // memset(exist[currentArr],0,sizeof(exist[currentArr]));
      tempCol = blocks[i].col;
    }else if(tempCol != blocks[i].col){
      break;
    }

    elements[elementsCounter] = i;
    elementsCounter++;

    if(exist[!currentArr][blocks[i].row] == tempCol-1 || tempCol == 1){
      brokenLayer = false;
      blocks[i].left = true;
      exist[currentArr][blocks[i].row] = tempCol;
      exist[currentArr][blocks[i].row + 1] = tempCol;
      exist[currentArr][blocks[i].row - 1] = tempCol;
    }

    if(blocks[i].left && blocks[i].up){
      printf("NO");
      return 0;
    }
  }

  elementsCounter = 0;
  memset(exist,0,sizeof(exist[0]) * 2);
  // sort(blocks, blocks + K, compareBlockRight);
  tempCol = M + 1;
  brokenLayer = false;
  for (int i = K-1; i >= 0; i--)
  {
    if(tempCol == blocks[i].col + 1){
      if(brokenLayer)break;
      brokenLayer = true;

      for (int j = elementsCounter-1; j >= 0; j--)
      {
        if(exist[currentArr][blocks[I].row] == tempCol){
          blocks[I].right = true;
          exist[currentArr][blocks[I].row] = tempCol;
          exist[currentArr][blocks[I].row + 1] = tempCol;
          exist[currentArr][blocks[I].row - 1] = tempCol;
        }
        
        if(blocks[I].right && (blocks[I].down || blocks[I].left)){
          printf("NO");
          return 0;
        }
      }

      elementsCounter = 0;

      currentArr = !currentArr;
      // memset(exist[currentArr],0,sizeof(exist[currentArr]));
      tempCol = blocks[i].col;
    }else if(tempCol != blocks[i].col){
      break;
    }

    elements[elementsCounter] = i;
    elementsCounter++;

    if(exist[!currentArr][blocks[i].row] == tempCol + 1 || tempCol == M){
      brokenLayer = false;
      blocks[i].right = true;
      exist[currentArr][blocks[i].row] = tempCol;
      exist[currentArr][blocks[i].row + 1] = tempCol;
      exist[currentArr][blocks[i].row - 1] = tempCol;
    }

    if(blocks[i].right && (blocks[i].down || blocks[i].left)){
      printf("NO");
      return 0;
    }
  }

  //SEPERATOR================================================================

  printf("YES");
  return 0;
}
