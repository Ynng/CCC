#include <iostream>
using namespace std;
int main()
{
    int n, k, a[100000][2], swifts, semaphores;
    k=swifts=semaphores=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i][1]);
    }
    /* cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i][0];
        cout << a[i][1];
    } */
    for (int i = 0; i < n; i++)
    {
        semaphores+=a[i][0];
        swifts+=a[i][1];
        if(semaphores==swifts)k=i+1;
    }
    printf("%d",k);
    return 0;
}