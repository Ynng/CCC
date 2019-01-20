#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, tide[100], seperate;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tide[i]);
    }
    sort(tide, tide + n);
    seperate = n / 2 + n % 2;
    if (n % 2 == 0)
    {
        for (int i = 0; i < seperate-1; i++)
        {
            printf("%d ", tide[seperate - 1 - i]);
            printf("%d ", tide[seperate + i]);
        }
            printf("%d ", tide[0]);
            printf("%d ", tide[n-1]);
    }else{
        for (int i = 0; i < seperate-1; i++)
        {
            printf("%d ", tide[seperate - 1 - i]);
            printf("%d ", tide[seperate + i]);
        }
        printf("%d ", tide[0]);
    }
    printf("\n");
    return 0;
}