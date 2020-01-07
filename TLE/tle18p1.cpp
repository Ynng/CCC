#include <iostream>
#include <cmath>
// #include <cstdio>
#include <cstring>
// using namespace std;

int main()
{
    double n = 0, temp;
    while(true){
        scanf("%d", &temp);
        if(temp==-1)break;
        else n+=temp;
    }
    printf("\n\n\n%d", n);
    return 0;
}