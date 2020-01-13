#include <iostream>
using namespace std;

bool gates[100005] = {false};
int gatesJump[100005] = {0};


int main()
{
    int g, p, tempA, tempB;
    scanf("%d", &g);
    scanf("%d", &p);
    for (int i = 1; i <= p; i++)
    {
        scanf("%d", &tempA);
        for (int j = tempA; j >= 0; j--)
        {   
            if(gatesJump[j]!=0)j=gatesJump[j];
            if (j == 0)
            {
                printf("%d", i-1);
                return 0;
            }
            if (!gates[j])
            {
                gatesJump[tempA] = j;
                gates[j] = true;
                break;
            }
        }
    }
    printf("%d", p);
    return 0;
}