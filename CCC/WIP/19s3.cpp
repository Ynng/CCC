#include <iostream>
using namespace std;
int input[3][3];

int main()
{
    int temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%x", &temp);
            input[i][j] = temp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d %d\n", input[i][0], input[i][1], input[i][2]);
    }
    return 0;
}